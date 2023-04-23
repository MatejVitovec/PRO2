#include "BoundaryCondition.hpp"




void BoundaryCondition::apply(const std::vector<int>& ownerIndexList, const Field<Compressible>& w, Field<Compressible>& wr) const
{
    for (auto & face : facesIndex)
    {
        wr[face] = calculateState(w[ownerIndexList[face]]);
    }    
}