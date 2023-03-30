#include <cmath>
#include "HexahedronCell.hpp"

std::vector<std::shared_ptr<Face>> HexahedronCell::createFaces()
{
    //TODO
    return std::vector<std::shared_ptr<Face>>{std::make_shared<Face>()};
}

HexahedronCell::~HexahedronCell()
{
    
}