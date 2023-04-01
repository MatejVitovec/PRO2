#include <cmath>
#include "TriangularFace.hpp"


Vector3 TriangularFace::calculateNormalVector(const std::vector<Vector3>& nodeList) const
{
    double dxyA = (nodeList[nodesIndex[0]].x - nodeList[nodesIndex[1]].x)*(nodeList[nodesIndex[0]].y + nodeList[nodesIndex[1]].y);
    double dxyB = (nodeList[nodesIndex[1]].x - nodeList[nodesIndex[2]].x)*(nodeList[nodesIndex[1]].y + nodeList[nodesIndex[2]].y);
    double dxyC = (nodeList[nodesIndex[2]].x - nodeList[nodesIndex[0]].x)*(nodeList[nodesIndex[2]].y + nodeList[nodesIndex[0]].y);

    double dyzA = (nodeList[nodesIndex[0]].y - nodeList[nodesIndex[1]].y)*(nodeList[nodesIndex[0]].z + nodeList[nodesIndex[1]].z);
    double dyzB = (nodeList[nodesIndex[1]].y - nodeList[nodesIndex[2]].y)*(nodeList[nodesIndex[1]].z + nodeList[nodesIndex[2]].z);
    double dyzC = (nodeList[nodesIndex[2]].y - nodeList[nodesIndex[0]].y)*(nodeList[nodesIndex[2]].z + nodeList[nodesIndex[0]].z);

    double dzxA = (nodeList[nodesIndex[0]].z - nodeList[nodesIndex[1]].z)*(nodeList[nodesIndex[0]].x + nodeList[nodesIndex[1]].x);
    double dzxB = (nodeList[nodesIndex[1]].z - nodeList[nodesIndex[2]].z)*(nodeList[nodesIndex[1]].x + nodeList[nodesIndex[2]].x);
    double dzxC = (nodeList[nodesIndex[2]].z - nodeList[nodesIndex[0]].z)*(nodeList[nodesIndex[2]].x + nodeList[nodesIndex[0]].x);

    return 0.5*(Vector3(dyzA + dyzB + dyzC, dzxA + dzxB + dzxC, dxyA + dxyB + dxyC));
}

Vector3 TriangularFace::calculateMidpoint(const std::vector<Vector3>& nodeList) const
{
    return (nodeList[nodesIndex[0]] + nodeList[nodesIndex[2]] + nodeList[nodesIndex[3]]) / 3.0;
}


TriangularFace::~TriangularFace()
{
    
}