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
        PyramidCell();
        PyramidCell(std::array<int, 5> nodesIdx);

        virtual ~PyramidCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    protected:


};

#endif // PYRAMIDCELL_H