#ifndef QUADRILATERALFACE_HPP
#define QUADRILATERALFACE_HPP

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class QuadrilateralFace : public Face
{
    public:
        QuadrilateralFace() : Face(QUADRILATERAL) {};
        QuadrilateralFace(std::vector<int> nodesIdx) : Face(QUADRILATERAL, nodesIdx) {};

        virtual ~QuadrilateralFace();

    private:
        Vector3 calculateNormalVector(const std::vector<Vector3>& nodeList) const;
        Vector3 calculateMidpoint(const std::vector<Vector3>& nodeList) const;

};

#endif // QUADRILATERALFACE_HPP