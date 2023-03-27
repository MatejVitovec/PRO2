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
        TetrahedronCell(std::array<int, 4> nodesIdx);

        virtual ~TetrahedronCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    protected:


};

#endif // TETRAHEDRONCELL_H