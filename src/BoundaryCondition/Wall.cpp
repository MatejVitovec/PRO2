#include "Wall.hpp"

Compressible Wall::calculateState(const Compressible& wl, const Face& f) const
{
    Vars<3> normalVector = vector3toVars(f.normalVector);
    Vars<3> ghostVelocity = wl.velocity() - 2*wl.normalVelocity(normalVector)*normalVector;

    return Compressible({wl.density(), ghostVelocity[0], ghostVelocity[1], ghostVelocity[2], wl.totalEnergy()});
}