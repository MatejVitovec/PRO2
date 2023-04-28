#include <cmath>
#include "HexahedronCell.hpp"
#include "QuadrilateralFace.hpp"

std::vector<std::shared_ptr<Face>> HexahedronCell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[0], nodesIndex[1], nodesIndex[5], nodesIndex[4]}),
                                              std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[2], nodesIndex[3], nodesIndex[7], nodesIndex[6]}),
                                              std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[0], nodesIndex[4], nodesIndex[7], nodesIndex[3]}),
                                              std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[4], nodesIndex[5], nodesIndex[6], nodesIndex[7]}),
                                              std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[1], nodesIndex[2], nodesIndex[6], nodesIndex[5]}),
                                              std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[0], nodesIndex[3], nodesIndex[2], nodesIndex[1]})};
}

HexahedronCell::~HexahedronCell()
{
    
}