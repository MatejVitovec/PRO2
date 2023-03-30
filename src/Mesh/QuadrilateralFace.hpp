#ifndef QUADRILATERALFACE_H
#define QUADRILATERALFACE_H

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class QuadrilateralFace : public Face
{
    public:
        QuadrilateralFace() : Face(QUADRILATERAL) {};
        QuadrilateralFace(std::vector<int> nodesIdx) : Face(QUADRILATERAL, nodesIdx) {};

        void update(const std::vector<Vector3>& nodeList);

        virtual ~QuadrilateralFace();

    protected:


};

#endif // QUADRILATERALFACE_H