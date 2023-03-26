#ifndef CELL_H
#define CELL_H

#include <vector>
#include <memory>
#include <Face.hpp>
#include "Vector3.hpp"

class Cell
{
    public:
        Cell();

        std::vector<int> nodesIndex;
        std::vector<int> facesIndex;
        //std::vector<int> neighborsIndex;
        
        Vector3 center;
        double volume;

        virtual void calculateVolume();
        virtual void calclateCenter();

    protected:


};

#endif // CELL_H