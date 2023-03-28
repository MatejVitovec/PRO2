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
        PrismCell(std::vector<int> nodesIdx);

        virtual ~PrismCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    private:


};

#endif // PRISMCELL_H