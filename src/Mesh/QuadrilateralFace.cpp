#include <cmath>
#include "QuadrilateralFace.hpp"


Vector3 QuadrilateralFace::calculateNormalVector(const std::vector<Vector3>& nodeList) const
{
    double dxA = (nodeList[nodesIndex[3]].x - nodeList[nodesIndex[1]].x);
    double dyA = (nodeList[nodesIndex[3]].y - nodeList[nodesIndex[1]].y);
    double dzA = (nodeList[nodesIndex[3]].z - nodeList[nodesIndex[1]].z);

    double dxB = (nodeList[nodesIndex[2]].x - nodeList[nodesIndex[0]].x);
    double dyB = (nodeList[nodesIndex[2]].y - nodeList[nodesIndex[0]].y);
    double dzB = (nodeList[nodesIndex[2]].z - nodeList[nodesIndex[0]].z);

    //return 0.5*(Vector3(dyA*dzB - dzA*dyB, dzA*dxB - dxA*dzB, dxA*dyB - dyA*dxB));
    return 0.5*(Vector3(dzA*dyB - dyA*dzB, dxA*dzB - dzA*dxB, dyA*dxB - dxA*dyB));
}

Vector3 QuadrilateralFace::calculateMidpoint(const std::vector<Vector3>& nodeList) const
{
    return (nodeList[nodesIndex[0]] + nodeList[nodesIndex[1]] + nodeList[nodesIndex[2]] + nodeList[nodesIndex[3]]) / 4.0;
}

QuadrilateralFace::~QuadrilateralFace()
{
    
}