#include <cmath>
#include "Cell.hpp"
#include "Vector3.hpp"


void Cell::update(const std::vector<std::shared_ptr<Face>>& faceList, const std::vector<Vector3>& nodeList)
{
    volume = calculateVolume(faceList, nodeList);

    //TODO
    //center = Vector3();
}

std::vector<std::shared_ptr<Face>> Cell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<Face>()};
}

double Cell::calculateVolume(const std::vector<std::shared_ptr<Face>>& faceList, const std::vector<Vector3>& nodeList) const
{
    double vol = 0.0;
    Vector3 origin = nodeList[nodesIndex[0]];

    for (auto & faceIndex : ownFaceIndex)
    {
        Vector3 midpoint = faceList[faceIndex]->midpoint - origin;
        Vector3 normal = faceList[faceIndex]->area*(faceList[faceIndex]->normalVector);
        vol += dot(midpoint, normal);
    }

    for (auto & faceIndex : neighborFaceIndex)
    {
        Vector3 midpoint = faceList[faceIndex]->midpoint - origin;
        Vector3 normal = faceList[faceIndex]->area*(-1.0)*(faceList[faceIndex]->normalVector);
        vol += dot(midpoint, normal);
    }
    
    return vol/3.0;
}

Cell::~Cell()
{
    
}