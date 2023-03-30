#include <cmath>
#include "Cell.hpp"


std::vector<std::shared_ptr<Face>> Cell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<Face>()};
}

Cell::~Cell()
{
    
}