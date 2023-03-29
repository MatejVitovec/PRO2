#ifndef CELL_H
#define CELL_H

#include <vector>
#include <memory>
#include "Face.hpp"
#include "Vector3.hpp"

class Cell
{
    public:
        enum cellType{TETRAHEDRON, HEXAHEDRON, PRISM, PYRAMID};

        Cell();

        virtual std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~Cell();

        std::vector<int> nodesIndex;
        std::vector<int> facesIndex;
        //std::vector<int> neighborsIndex;
        
        int type;

        Vector3 center;
        double volume;

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    protected:


};

#endif // CELL_H