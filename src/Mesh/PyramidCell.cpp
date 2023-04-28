#include <cmath>
#include "PyramidCell.hpp"
#include "TriangularFace.hpp"
#include "QuadrilateralFace.hpp"

std::vector<std::shared_ptr<Face>> PyramidCell::createFaces()
{
    //TODO test
    return std::vector<std::shared_ptr<Face>>{std::make_shared<QuadrilateralFace>(std::vector<int>{nodesIndex[0], nodesIndex[3], nodesIndex[2], nodesIndex[1]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[1], nodesIndex[4]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[1], nodesIndex[2], nodesIndex[4]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[2], nodesIndex[3], nodesIndex[4]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[4], nodesIndex[3]})};
}

PyramidCell::~PyramidCell()
{
    
}