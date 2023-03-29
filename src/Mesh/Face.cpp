#include <cmath>
#include <algorithm>
#include "Face.hpp"


Face::Face()
{
    
}

bool Face::check()
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

Face::~Face()
{
    
}