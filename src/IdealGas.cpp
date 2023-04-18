#include <cmath>

#include "IdealGas.hpp"

//musi byt pod IdealGas.cpp kvuli forward deklaraci - byl pouzit prototyp
#include "Compressible.hpp"

void IdealGas::setGamma(double gamma_)
{
    gamma = gamma_;
}

void IdealGas::setR(double R_)
{
    R = R_;
}

double IdealGas::getGamma() const
{
    return gamma;
}

double IdealGas::getR() const
{
    return R;
}

double IdealGas::pressure(const Compressible& data) const
{
    return (gamma - 1.0)*data.density()*(data.totalEnergy() - 0.5*data.absVelocity()*data.absVelocity());
    //return 0.0;
}

double IdealGas::internalEnergy(const Compressible& data) const
{
    return data.pressure()/((gamma - 1.0)*data.density());
    //return 0.0;
}

double IdealGas::soundSpeed(const Compressible& data) const
{
    return sqrt((gamma*data.pressure())/data.density());
    //return 0.0;
}