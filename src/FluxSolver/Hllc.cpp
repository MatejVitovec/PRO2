#include "Hllc.hpp"

Vars<5> Hllc::claculateFlux(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const
{
    enum {sl, ss, sr};
    Vars<3> wSpeed = waveSpeedsEstimate(wl, wr, normalVector);        


    if (0 <= wSpeed[sl])
    {
        //FL
        return wl.flux(normalVector);
    }
    else if(0 <= wSpeed[ss])
    {
        //F*L
        //musi se natocit ss
        Vars<3> normalVelocity = wl.velocity(normalVector); ////////////////???
        double density = wl.density();
        double totalEnergy = wl.totalEnergy();
        double pressure = wl.pressure();

        double starE = (totalEnergy/density) + (wSpeed[ss] - normalVelocity[0])*(wSpeed[ss] + (pressure/(density*(wSpeed[sl] - normalVelocity[0]))));
        
        Compressible wStar = density * (((wSpeed[sl] - normalVector[0])/(wSpeed[sl] - wSpeed[ss]))*Compressible({1.0, wSpeed[ss], normalVelocity[1], normalVelocity[2], starE}));////????
        //ss natocit zpet

        return wl.flux(normalVector) + wSpeed[sl]*(wStar - wl);
    }
    else if(0 <= wSpeed[sr])
    {
        //F*R
        Vars<3> normalVelocity = wr.velocity(normalVector);
        double density = wr.density();
        double totalEnergy = wr.totalEnergy();
        double pressure = wr.pressure();

        double starE = (totalEnergy/density) + (wSpeed[ss] - normalVelocity[0])*(wSpeed[ss] + (pressure/(density*(wSpeed[sr] - normalVelocity[0]))));
        Compressible wStar = density * (((wSpeed[sr] - normalVelocity[0])/(wSpeed[sr] - wSpeed[ss]))*Compressible({1.0, wSpeed[ss], normalVelocity[1], normalVelocity[2], starE}));

        return wl.flux(normalVector) + wSpeed[sr]*(wStar - wr);
    }
    else
    {
        //FR
        return wr.flux(normalVector);
    }
    
    return Vars<5>();
}


Vars<3> Hllc::waveSpeedsEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const
{
    //TODO

    //PVRS
    /*double pl = eulerEqn->pressure(wl);
    double pr = eulerEqn->pressure(wr);
    double ul = eulerEqn->velocity(wl);
    double ur = eulerEqn->velocity(wr);
    double rhol = eulerEqn->density(wl);
    double rhor = eulerEqn->density(wr);
    double al = eulerEqn->soundSpeed(wl);
    double ar = eulerEqn->soundSpeed(wr);
    double Gamma = eulerEqn->getGamma();

    double pStar = std::fmax(0, 0.5*((pl + pr) - 0.25*(ul + ur)*(rhol + rhor)*(al + ar)));
    double ql;
    double qr;

    if(pStar > pl)
    {
        ql = pow(1 + ((Gamma + 1)/(2*Gamma))*((pStar/pl) - 1), 0.5);
    }
    else
    {
        ql = 1;
    }
    double sl = ul - al*ql;

    if(pStar > pr)
    {
        qr = pow(1 + ((Gamma + 1)/(2*Gamma))*((pStar/pr) - 1), 0.5);
    }
    else
    {
        qr = 1;
    }
    double sr = ur + ar*qr;

    double ss = (pr - pl + rhol*ul*(sl - ul) - rhor*ur*(sr - ur))/(rhol*sl - rhol*ul - rhor*sr + rhor*ur);

    return Vector3({sl, ss, sr});*/

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