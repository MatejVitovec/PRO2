#ifndef FACE_HPP
#define FACE_HPP

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

        void update(const std::vector<Vector3>& nodeList);
        bool check() const;
        bool equal(const Face& compFace) const;

        void reverseOrientation();

        virtual ~Face();

        std::vector<int> nodesIndex;

        double area;
        Vector3 normalVector;
        Vector3 midpoint;

    protected:
        const int type;

        virtual Vector3 calculateNormalVector(const std::vector<Vector3>& nodeList) const;
        virtual Vector3 calculateMidpoint(const std::vector<Vector3>& nodeList) const;

};

#endif // FACE_HPP