#ifndef TRIANGULARFACE_HPP
#define TRIANGULARFACE_HPP

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class TriangularFace : public Face
{
    public:
        TriangularFace() : Face(TRIANGULAR) {};
        TriangularFace(std::vector<int> nodesIdx) : Face(TRIANGULAR, nodesIdx) {};

        virtual ~TriangularFace();

    private:
        Vector3 calculateNormalVector(const std::vector<Vector3>& nodeList) const;
        Vector3 calculateMidpoint(const std::vector<Vector3>& nodeList) const;

};

#endif // TRIANGULARFACE_HPP