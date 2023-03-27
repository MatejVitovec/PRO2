#ifndef MESH_H
#define MESH_H

#include <vector>
#include <memory>
#include <string>

#include "Vector3.hpp"
#include "Cell.hpp"
#include "Face.hpp"
#include "Patch.hpp"


class Mesh
{
    public:
        Mesh();

        void update();
        void loadGmsh2(std::string fileName);

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

        //load GMSH
        std::vector<std::string> readFile(std::string fileName);
        std::vector<std::vector<std::string>> parseBlockData(const std::vector<std::string>& dataIn, std::string blockName);
        void createNodesGmsh(const std::vector<std::vector<std::string>>& nodesGmsh);

};

#endif // MESH_H