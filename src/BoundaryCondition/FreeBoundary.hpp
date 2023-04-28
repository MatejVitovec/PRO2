#ifndef FREEBOUNDARY_H
#define FREEBOUNDARY_H

#include "BoundaryCondition.hpp"

class FreeBoundary : public BoundaryCondition
{
    public:

        FreeBoundary() {}
        FreeBoundary(Boundary meshBoundary) : BoundaryCondition(meshBoundary) {}

        Compressible calculateState(const Compressible& wl, const Face& f) const;

};

#endif // FREEBOUNDARY