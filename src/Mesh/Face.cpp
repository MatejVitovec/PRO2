#include <cmath>
#include <algorithm>
#include "Face.hpp"


void Face::update(const std::vector<Vector3>& nodeList)
{
    area = 0;
    normalVector = Vector3();
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

Face::~Face()
{
    
}