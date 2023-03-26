#ifndef FACE_H
#define FACE_H

#include <vector>
#include <memory>

#include "Vector3.hpp"

class Face
{
    public:
        Face();

        std::vector<int> nodesIndex;
        int ownerIndex;
        int neighborIndex;

        Vector3 center;
        Vector3 normalVector;

        virtual void calculateArea();
        virtual void calculateCenter();

    protected:


};

#endif // FACE_H