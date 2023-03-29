#ifndef TETRAHEDRONCELL_H
#define TETRAHEDRONCELL_H

#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Face.hpp"
#include "Vector3.hpp"

class TetrahedronCell : public Cell
{
    public:
        TetrahedronCell();
        TetrahedronCell(std::vector<int> nodesIdx);

        std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~TetrahedronCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    private:


};

#endif // TETRAHEDRONCELL_H