#ifndef BOUNDARYCONDITION_H
#define BOUNDARYCONDITION_H

#include "../Mesh/Boundary.hpp"
#include "Field.hpp"
#include "Compressible.hpp"

class BoundaryCondition
{
    public:

        BoundaryCondition() {}
        BoundaryCondition(Boundary meshBoundary) : facesIndex(meshBoundary.facesIndex) {}

        void apply(const std::vector<int>& ownerIndexList, const Field<Compressible>& w, Field<Compressible>& wr) const;

        virtual Compressible calculateState(const Compressible& wl) const = 0;
        
    protected:
        std::vector<int> facesIndex;

};

#endif // BOUNDARYCONDITION_H