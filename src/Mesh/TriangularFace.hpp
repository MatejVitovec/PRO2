#ifndef TRIANGULARFACE_H
#define TRIANGULARFACE_H

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class TriangularFace : public Face
{
    public:
        TriangularFace() : Face(TRIANGULAR) {};
        TriangularFace(std::vector<int> nodesIdx) : Face(TRIANGULAR, nodesIdx) {};

        void update(const std::vector<Vector3>& nodeList);

        virtual ~TriangularFace();

    private:


};

#endif // TRIANGULARFACE_H