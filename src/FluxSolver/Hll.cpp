#include "Hll.hpp"

Vars<5> Hll::claculateFlux(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector)
{
    enum {sl, ss, sr};
    Vars<3> wSpeed = waveSpeedsEstimate(wl, wr, normalVector);        


    if (0 <= wSpeed[sl])
    {
        //FL
        return wl.flux(normalVector);
    }
    else if(0 < wSpeed[sr])
    {
        //F*
        return ((wSpeed[sr]*wl.flux(normalVector) - wSpeed[sl]*wr.flux(normalVector) + wSpeed[sr]*wSpeed[sl]*(wr-wl)) / (wSpeed[sr] - wSpeed[sl]));
    }
    else
    {
        //FR
        return wr.flux(normalVector);
    }
    
    return Vars<5>();
}


Vars<3> Hll::waveSpeedsEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const
{
    double ul = wl.velocity(normalVector)[0];
    double ur = wr.velocity(normalVector)[0];
    double al = wl.soundSpeed();
    double ar = wr.soundSpeed();
    double pl = wl.pressure();
    double pr = wr.pressure();
    double rhol = wl.density();
    double rhor = wr.density();

    double sl = std::min(ul - al, ur - ar);
    double sr = std::max(ul + al, ur + ar);
    double ss = (pr - pl + rhol*ul*(sl - ul) - rhor*ur*(sr - ur))/(rhol*sl - rhol*ul - rhor*sr + rhor*ur);

    return Vars<3>({sl, ss, sr});
}