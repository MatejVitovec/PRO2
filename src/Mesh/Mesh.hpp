#ifndef MESH_H
#define MESH_H

#include <vector>
#include <memory>

#include "Vector3.hpp"
#include "Cell.hpp"
#include "Face.hpp"
#include "Patch.hpp"


class Mesh
{
    public:
        Mesh();

        void update();
        void loadGmsh();

        std::vector<Vector3> nodeList;
        std::vector<Cell> cellList;        
        std::vector<Face> faceList;
        std::vector<Patch> patchList;
        std::vector<int> internalFaceList;


    private:        
        void createCells();
        void createFaces();
        void createPatches();

        void updateCells();
        void updateFaces();
        void updatePatches();

};

#endif // MESH_H