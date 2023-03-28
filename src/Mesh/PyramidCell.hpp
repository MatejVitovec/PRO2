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
        PyramidCell(std::vector<int> nodesIdx);

        virtual ~PyramidCell();

        //virtual void calculateVolume();
        //virtual void calclateCenter();

    private:


};

#endif // PYRAMIDCELL_H