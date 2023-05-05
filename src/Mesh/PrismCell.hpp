#ifndef PRISMCELL_HPP
#define PRISMCELL_HPP

#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Face.hpp"
#include "Vector3.hpp"

class PrismCell : public Cell
{
    public:
        PrismCell() : Cell(PRISM) {};
        PrismCell(std::vector<int> nodesIdx) : Cell(PRISM, nodesIdx) {};

        std::vector<std::shared_ptr<Face>> createFaces();

        virtual ~PrismCell();

    private:


};

#endif // PRISMCELL_HPP