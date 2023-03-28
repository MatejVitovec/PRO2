#include <cmath>
#include "TriangularFace.hpp"


TriangularFace::TriangularFace()
{
    
}

TriangularFace::TriangularFace(std::vector<int> nodesIdx)
{
    nodesIndex = nodesIdx;
    type = TRIANGULAR;
}


TriangularFace::~TriangularFace()
{
    
}