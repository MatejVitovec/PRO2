#ifndef PATCH_H
#define PATCH_H

#include <vector>
#include <memory>

class Patch
{
    public:
        Patch();

        std::vector<int> nodesIndex;
        std::vector<int> facesIndex;

        int boundaryConditionTypeID;

    protected:

};

#endif // PATCH_H