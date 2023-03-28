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
        HexahedronCell(std::vector<int> nodesIdx);

        virtual ~HexahedronCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    private:


};

#endif // HEXAHEDRONCELL_H