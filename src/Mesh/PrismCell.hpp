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
        PrismCell();
        PrismCell(std::array<int, 6> nodesIdx);

        virtual ~PrismCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    protected:


};

#endif // PRISMCELL_H