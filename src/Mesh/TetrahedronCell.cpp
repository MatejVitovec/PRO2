#include <cmath>
#include "TetrahedronCell.hpp"
#include "TriangularFace.hpp"


std::vector<std::shared_ptr<Face>> TetrahedronCell::createFaces()
{
    return std::vector<std::shared_ptr<Face>>{std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[2], nodesIndex[1]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[1], nodesIndex[3]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[3], nodesIndex[2]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[1], nodesIndex[2], nodesIndex[3]})};
}

TetrahedronCell::~TetrahedronCell()
{

}