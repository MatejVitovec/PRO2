#ifndef FACE_H
#define FACE_H

#include <vector>
#include <memory>

#include "Vector3.hpp"

class Face
{
    public:
        enum faceType{VOID, TRIANGULAR, QUADRILATERAL};

        Face() : type(VOID) {};
        Face(faceType fType) : type(fType) {};
        Face(faceType fType, std::vector<int> nodesIdx) : type(fType), nodesIndex(nodesIdx) {};

        virtual void update(const std::vector<Vector3>& nodeList);

        bool check() const;
        bool equal(const Face& compFace) const;
        void reverseOrientation();

        virtual ~Face();

        std::vector<int> nodesIndex;

        double area;
        Vector3 normalVector;

        //Vector3 center;

        //virtual void calculateArea();
        //virtual void calculateNormal();
        //virtual void calculateCenter();

    protected:
        const int type;
        //virtual void calculateArea();
        //virtual void calculateNormal();

};

#endif // FACE_H