#ifndef PYRAMIDCELL_H
#define PYRAMIDCELL_H

#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Face.hpp"
#include "Vector3.hpp"

class PyramidCell : public Cell
{
    public:
        PyramidCell() : Cell(PYRAMID) {};
        PyramidCell(std::vector<int> nodesIdx) : Cell(PYRAMID, nodesIdx) {};

        std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~PyramidCell();

    private:
        double calculateVolume() const;

};

#endif // PYRAMIDCELL_H