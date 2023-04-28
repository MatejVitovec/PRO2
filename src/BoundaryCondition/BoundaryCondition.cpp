#include "BoundaryCondition.hpp"




void BoundaryCondition::apply(const std::vector<int>& ownerIndexList, const std::vector<std::shared_ptr<Face>>& faces, const Field<Compressible>& w, Field<Compressible>& wr) const
{
    for (auto & faceIndex : facesIndex)
    {
        wr[faceIndex] = calculateState(w[ownerIndexList[faceIndex]], *faces[faceIndex]);
    }    
}