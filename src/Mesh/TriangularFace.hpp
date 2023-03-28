#ifndef TRIANGULARFACE_H
#define TRIANGULARFACE_H

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class TriangularFace : public Face
{
    public:
        TriangularFace();
        TriangularFace(std::vector<int> nodesIdx);

        virtual ~TriangularFace();

        //void calculateArea();
        //void calculateCenter();

    private:


};

#endif // TRIANGULARFACE_H