#ifndef CELL_H
#define CELL_H

#include <vector>
#include <memory>
#include "Face.hpp"
#include "Vector3.hpp"

class Cell
{
    public:
        enum cellType{VOID, TETRAHEDRON, HEXAHEDRON, PRISM, PYRAMID};

        Cell() : type(VOID) {};
        Cell(cellType cType) : type(cType) {};
        Cell(cellType cType, std::vector<int> nodesIdx) : type(cType), nodesIndex(nodesIdx) {};

        void update(const std::vector<std::shared_ptr<Face>>& faceList, const std::vector<Vector3>& nodeList);

        virtual std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~Cell();

        std::vector<int> nodesIndex;
        std::vector<int> ownFaceIndex;
        std::vector<int> neighborFaceIndex;

        Vector3 center;
        double volume;
        

    protected:
        const int type;

        double calculateVolume(const std::vector<std::shared_ptr<Face>>& faceList, const std::vector<Vector3>& nodeList) const;
        //virtual void calclateCenter();

};

#endif // CELL_H