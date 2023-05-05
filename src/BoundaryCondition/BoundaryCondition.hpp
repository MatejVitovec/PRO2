#ifndef BOUNDARYCONDITION_HPP
#define BOUNDARYCONDITION_HPP

#include "../Mesh/Boundary.hpp"
#include "../Mesh/Face.hpp"
#include "../Field.hpp"
#include "../Compressible.hpp"

class BoundaryCondition
{
    public:

        BoundaryCondition() {}
        BoundaryCondition(Boundary meshBoundary) : facesIndex(meshBoundary.facesIndex) {}

        void apply(const std::vector<int>& ownerIndexList,const std::vector<std::shared_ptr<Face>>& faces, const Field<Compressible>& w, Field<Compressible>& wr) const;

        virtual Compressible calculateState(const Compressible& wl, const Face& f) const = 0;
        
    protected:
        std::vector<int> facesIndex;

};

#endif // BOUNDARYCONDITION_HPP