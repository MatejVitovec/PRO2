#include <cmath>
#include "TetrahedronCell.hpp"


TetrahedronCell::TetrahedronCell()
{
    
}

TetrahedronCell::TetrahedronCell(std::array<int, 4> nodesIdx)
{
    nodesIndex = std::vector<int>(nodesIdx.begin(), nodesIdx.end());
}

TetrahedronCell::~TetrahedronCell()
{
    
}