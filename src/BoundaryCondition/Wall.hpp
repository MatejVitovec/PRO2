#ifndef WALL_H
#define WALL_H

#include "BoundaryCondition.hpp"

class Wall : public BoundaryCondition
{
    public:

        Wall() {}
        Wall(Boundary meshBoundary) : BoundaryCondition(meshBoundary) {}

        Compressible calculateState(const Compressible& wl, const Face& f) const;
    
    private:

};

#endif // WALL