#ifndef PRISMCELL_H
#define PRISMCELL_H

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

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    private:


};

#endif // PRISMCELL_H