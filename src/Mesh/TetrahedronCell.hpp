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
        TetrahedronCell() : Cell(TETRAHEDRON) {};
        TetrahedronCell(std::vector<int> nodesIdx) : Cell(TETRAHEDRON, nodesIdx) {};

        std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~TetrahedronCell();

    private:
        double calculateVolume() const;

};

#endif // TETRAHEDRONCELL_H