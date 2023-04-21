#include <cmath>
#include <algorithm>
#include "Face.hpp"


void Face::update(const std::vector<Vector3>& nodeList)
{
    Vector3 normalVectorScale = calculateNormalVector(nodeList);

    area = sqrt(normalVectorScale.x*normalVectorScale.x + normalVectorScale.y*normalVectorScale.y + normalVectorScale.z*normalVectorScale.z);
    normalVector = normalVectorScale/area;

    midpoint = calculateMidpoint(nodeList);
}

bool Face::check() const
{
    if(std::adjacent_find(nodesIndex.begin(), nodesIndex.end()) != nodesIndex.end())
    {
        return true;
    }

    return false;
}

bool Face::equal(const Face& compFace) const
{
    bool isEqual = true;

    for (auto & compNodeIndex : compFace.nodesIndex)
    {
        if(std::find(nodesIndex.begin(), nodesIndex.end(), compNodeIndex) == nodesIndex.end())
        {
            isEqual = false;
        }
    }
    
    return isEqual;
}

void Face::reverseOrientation()
{
    std::reverse(nodesIndex.begin(), nodesIndex.end());
    //update();
}

Vector3 Face::calculateNormalVector(const std::vector<Vector3>& nodeList) const
{
    //pouze virtualni - spatne
    return Vector3();
}

Vector3 Face::calculateMidpoint(const std::vector<Vector3>& nodeList) const
{
    Vector3 aux = Vector3(0.0, 0.0, 0.0);

    int i;
    for (i = 0; i < nodeList.size(); i++)
    {
        aux = aux + nodeList[nodesIndex[i]];
    }
    
    return aux / ((double) i);
}

Face::~Face()
{
    
}