#include <cmath>
#include "TetrahedronCell.hpp"
#include "TriangularFace.hpp"


TetrahedronCell::TetrahedronCell()
{
    
}

TetrahedronCell::TetrahedronCell(std::vector<int> nodesIdx)
{
    nodesIndex = nodesIdx;
    type = TETRAHEDRON;
}

std::vector<std::shared_ptr<Face>> TetrahedronCell::createOwnFaces()
{
/*
                   v
                 .
               ,/
              /
           2
         ,/|`\
       ,/  |  `\
     ,/    '.   `\
   ,/       |     `\
 ,/         |       `\
0-----------'.--------1 --> u
 `\.         |      ,/
    `\.      |    ,/
       `\.   '. ,/
          `\. |/
             `3
                `\.
                   ` w
*/


    return std::vector<std::shared_ptr<Face>>{std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[1], nodesIndex[3]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[1], nodesIndex[2], nodesIndex[3]})};
}

std::vector<std::shared_ptr<Face>> TetrahedronCell::createNeighborFaces()
{

    return std::vector<std::shared_ptr<Face>>{std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[1], nodesIndex[2]}),
                                              std::make_shared<TriangularFace>(std::vector<int>{nodesIndex[0], nodesIndex[2], nodesIndex[3]})};
}

TetrahedronCell::~TetrahedronCell()
{
    
}