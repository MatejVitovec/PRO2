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
        HexahedronCell() : Cell(HEXAHEDRON) {};
        HexahedronCell(std::vector<int> nodesIdx) : Cell(HEXAHEDRON, nodesIdx) {};

        std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~HexahedronCell();

    private:

};

#endif // HEXAHEDRONCELL_H