#include "Hllc.hpp"

Vars<5> Hllc::claculateFlux(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const
{    
    double rhoL = wl.density();
    double pL = wl.pressure();
    double nuL = wl.normalVelocity(normalVector);
    double aL = wl.soundSpeed();

    double rhoR = wr.density();
    double pR = wr.pressure();
    double nuR = wr.normalVelocity(normalVector);
    double aR = wr.soundSpeed();
    
    //PVRS
    double pm = std::fmax(0, 0.5*(pL + pR) - 0.5*(nuR - nuL)*0.5*(rhoL + rhoR)*0.5*(aL + aR));

    double sl;
    double sr;
    double sm;

    if (pm <= pL)
    {
        sl = nuL - aL;
    }        
    else
    {
        sl = 0.5*(nuL + nuR) - 0.5*(aL + aR);
    }
        
    if (pm <= pR)
    {
        sr = nuR + aR;
    }        
    else
    {
        sr = 0.5*(nuL + nuR) + 0.5*(aL + aR);
    }
        
    //contact wave speed
    sm = pR - pL + rhoL*nuL*(sl - nuL) - rhoR*nuR*(sr - nuR);
    sm = sm / (rhoL*(sl - nuL) - rhoR*(sr - nuR));


    //HLLC scheme
    if (sl >= 0)
    {
        //left state
        return wl.flux(normalVector);
    }
    else if (sr <= 0)
    {
        //right state
        return wl.flux(normalVector);
    }
    else if (sm >= 0)
    {
        //middle-left state
        Vars<5> middleLeftFlux = Vars<5>();

        double uL = wl.velocityU();
        double vL = wl.velocityU();
        double wL = wl.velocityU();
        double EL = wl.totalEnergy();

        pm = pL + rhoL*(sl - nuL)*(sm - nuL);
        double rM = rhoL*(sl - nuL)/(sl - sm);

        return Vars<5>({rhoL*nuL + sl*(rM - rhoL),
        rhoL*nuL*uL + pL*normalVector[0] + sl*((rM - rhoL)*uL + (pm - pL)/(sl - sm)*normalVector[0]),
        rhoL*nuL*vL + pL*normalVector[1] + sl*((rM - rhoL)*vL + (pm - pL)/(sl - sm)*normalVector[1]),
        rhoL*nuL*wL + pL*normalVector[2] + sl*((rM - rhoL)*wL + (pm - pL)/(sl - sm)*normalVector[2]),
        rhoL*nuL*(EL + pL/rhoL) + sl*((rM - rhoL)*EL + (pm*sm - pL*nuL)/(sl - sm))});
    }
    else
    {
        //middle-right state
        Vars<5> middleRightFlux = Vars<5>();

        double uR = wr.velocityU();
        double vR = wr.velocityU();
        double wR = wr.velocityU();
        double ER = wr.totalEnergy();

        pm = pR + rhoR*(sr - nuR)*(sm - nuR);
        double rM = rhoR*(sr - nuR)/(sr - sm);
        return Vars<5>({rhoR*nuR + sr*(rM - rhoR),
                        rhoR*nuR*uR + pR*normalVector[0] + sr*((rM - rhoR)*uR + (pm - pR)/(sr - sm)*normalVector[0]),
                        rhoR*nuR*vR + pR*normalVector[1] + sr*((rM - rhoR)*vR + (pm - pR)/(sr - sm)*normalVector[1]),
                        rhoR*nuR*wR + pR*normalVector[2] + sr*((rM - rhoR)*wR + (pm - pR)/(sr - sm)*normalVector[2]),
                        rhoR*nuR*(ER + pR/rhoR) + sr*((rM - rhoR)*ER + (pm*sm - pR*nuR)/(sr - sm))});
    }
}



//nechce se mi to mazat - muze se hodit
Vars<3> waveSpeedsEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector)
{
    //PVRS
    double rhoL = wl.density();
    double pL = wl.pressure();
    double nuL = wl.normalVelocity(normalVector);
    double aL = wl.soundSpeed();

    double rhoR = wr.density();
    double pR = wr.pressure();
    double nuR = wr.normalVelocity(normalVector);
    double aR = wr.soundSpeed();

    double pm = std::fmax(0, 0.5*(pL + pR) - 0.5*(nuR - nuL)*0.5*(rhoL + rhoR)*0.5*(aL + aR));

    double sl;
    double sr;
    double sm;

    if (pm <= pL)
    {
        sl = nuL - aL; // left wave is expansion
    }        
    else
    {
        sl = 0.5*(nuL + nuR) - 0.5*(aL + aR); // left wave is shock, Lax approach
    }
        
    if (pm <= pR)
    {
        sr = nuR + aR; // right wave is expansion
    }        
    else
    {
        sr = 0.5*(nuL + nuR) + 0.5*(aL + aR); // right wave is shock, Lax approach
    }
        
    //contact wave speed : sm
    sm = pR - pL + rhoL*nuL*(sl - nuL) - rhoR*nuR*(sr - nuR);
    sm = sm / (rhoL*(sl - nuL) - rhoR*(sr - nuR));

    return Vars<3>({sl, sm, sr});
}

//nechce se mi to mazat - muze se hodit
Vars<3> basicSpeedEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector)
{
    //basic speed approximation
    double ul = wl.normalVelocity(normalVector);
    double ur = wr.normalVelocity(normalVector);
    double al = wl.soundSpeed();
    double ar = wr.soundSpeed();
    double pl = wl.pressure();
    double pr = wr.pressure();
    double rhol = wl.density();
    double rhor = wr.density();

    double sl = std::min(ul - al, ur - ar);
    double sr = std::max(ul + al, ur + ar);
    double sm = (pr - pl + rhol*ul*(sl - ul) - rhor*ur*(sr - ur))/(rhol*sl - rhol*ul - rhor*sr + rhor*ur);

    return Vars<3>({sl, sm, sr});
}