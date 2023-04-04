#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <vector>
#include <memory>
#include <string>

class Boundary
{
    public:
        Boundary() : boundaryConditionName("empty") {};
        Boundary(std::string name) : boundaryConditionName(name) {};
        //Boundary(std::vector<int> fIndexes) : facesIndex(fIndexes) {};

        //std::vector<int> nodesIndex;
        std::vector<int> facesIndex;

        std::string boundaryConditionName;

    private:

};

#endif // BOUNDARY_H