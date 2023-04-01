#include <cmath>
#include "Cell.hpp"


std::vector<std::shared_ptr<Face>> Cell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<Face>()};
}

double Cell::calculateVolume() const
{
    return 0.0;
}

Cell::~Cell()
{
    
}