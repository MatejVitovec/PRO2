#include <cmath>

#include "Compressible.hpp"


double Compressible::density() const
{
    return data[RHO];
}

double Compressible::absVelocity() const
{
    return sqrt(data[RHO_U]*data[RHO_U] + data[RHO_V]*data[RHO_V] + data[RHO_W]*data[RHO_W]) / data[RHO];
}

double Compressible::velocityU() const
{
    return data[RHO_U] / data[RHO];
}

double Compressible::velocityV() const
{
    return data[RHO_V] / data[RHO];
}

double Compressible::velocityW() const
{
    return data[RHO_W] / data[RHO];
}

double Compressible::totalEnergy() const
{
    return data[RHO_E] / data[RHO];
}

double Compressible::pressure() const
{
    //return eqs->pressure(*this);
}

double Compressible::internalEnergy() const
{
    //return eqs->internalEnergy(*this);
}

double Compressible::soundSpeed() const
{
    //return eqs->soundSpeed(*this);
}

Compressible Compressible::flux() const
{
    return Compressible();
}

Vars Compressible::primitive() const
{
    return Vars();
}
