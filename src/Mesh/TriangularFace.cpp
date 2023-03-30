#include <cmath>
#include "TriangularFace.hpp"



void TriangularFace::update(const std::vector<Vector3>& nodeList)
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


    Vector3 normalVectorScale = 0.5*(Vector3(dyzA + dyzB + dyzC, dzxA + dzxB + dzxC, dxyA + dxyB + dxyC));

    area = sqrt(normalVectorScale.x*normalVectorScale.x + normalVectorScale.y*normalVectorScale.y + normalVectorScale.z*normalVectorScale.z);
    normalVector = normalVectorScale/area;
}


TriangularFace::~TriangularFace()
{
    
}