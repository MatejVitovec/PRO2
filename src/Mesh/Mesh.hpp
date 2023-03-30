#ifndef MESH_H
#define MESH_H

#include <vector>
#include <memory>
#include <string>

#include "Vector3.hpp"

#include "Cell.hpp"
#include "TetrahedronCell.hpp"
#include "HexahedronCell.hpp"
#include "PrismCell.hpp"
#include "PyramidCell.hpp"

#include "Face.hpp"
#include "TriangularFace.hpp"
#include "QuadrilateralFace.hpp"

#include "Patch.hpp"


class Mesh
{
    public:
        Mesh();

        void update();
        void loadGmsh2(std::string fileName);

        std::vector<Vector3> nodeList;
        std::vector<std::shared_ptr<Cell>> cellList;
        std::vector<std::shared_ptr<Face>> faceList;
        std::vector<Patch> patchList;
        
        std::vector<int> ownerIndexList;
        std::vector<int> neighborIndexList;
        std::vector<int> internalFaceIndexList;


    private:
        void createCells();
        void createFaces();
        void createPatches();

        void updateCells();
        void updateFaces();
        void updatePatches();

        bool checkFaces() const;

        //load GMSH
        std::vector<std::string> readFile(std::string fileName);
        std::vector<std::vector<std::string>> parseBlockData(const std::vector<std::string>& dataIn, std::string blockName);
        void createNodesGmsh(const std::vector<std::vector<std::string>>& nodesGmsh);
        void createCellsGmsh(const std::vector<std::vector<std::string>>& cellsGmsh);

};

#endif // MESH_H