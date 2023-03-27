#ifndef HEXAHEDRONCELL_H
#define HEXAHEDRONCELL_H

#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Face.hpp"
#include "Vector3.hpp"

class HexahedronCell : public Cell
{
    public:
        HexahedronCell();
        HexahedronCell(std::array<int, 8> nodesIdx);

        virtual ~HexahedronCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    protected:


};

#endif // HEXAHEDRONCELL_H