#include <cmath>
#include "Cell.hpp"
#include "Vector3.hpp"


void Cell::update(const std::vector<std::shared_ptr<Face>>& faceList)
{
    //update volume, center
    //TODO no copy midpoint

    double vol = 0.0;
    Vector3 cen = Vector3(0.0, 0.0, 0.0);
    Vector3 projArea = Vector3(0.0, 0.0, 0.0);

    for (auto & faceIndex : ownFaceIndex)
    {
        Vector3 midpoint = faceList[faceIndex]->midpoint;
        Vector3 normal = faceList[faceIndex]->area*(faceList[faceIndex]->normalVector);
        vol += dot(midpoint, normal);
        cen = cen + norm2(midpoint)*norm2(midpoint)*normal;
        projArea = projArea + abs(normal);
    }

    for (auto & faceIndex : neighborFaceIndex)
    {
        Vector3 midpoint = faceList[faceIndex]->midpoint;
        Vector3 normal = faceList[faceIndex]->area*(-1.0)*(faceList[faceIndex]->normalVector);
        vol += dot(midpoint, normal);
        cen = cen + norm2(midpoint)*norm2(midpoint)*normal;
        projArea = projArea + abs(normal);
    }
    
    volume = vol/3.0;
    center = (0.5/volume)*cen;
    projectedArea = 0.5*projArea;
}

std::vector<std::shared_ptr<Face>> Cell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<Face>()};
}

Cell::~Cell()
{
    
}