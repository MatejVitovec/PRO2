#ifndef QUADRILATERALFACE_H
#define QUADRILATERALFACE_H

#include <vector>
#include <memory>

#include "Face.hpp"
#include "Vector3.hpp"

class QuadrilateralFace : public Face
{
    public:
        QuadrilateralFace();

        virtual ~QuadrilateralFace();

        //void calculateArea();
        //void calculateCenter();

    protected:


};

#endif // QUADRILATERALFACE_H