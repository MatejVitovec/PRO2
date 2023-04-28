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

#include "Boundary.hpp"


class Mesh
{
    public:
        Mesh() {};

        const std::vector<Vector3>& getNodeList() const;
        const std::vector<std::shared_ptr<Cell>>& getCellList() const;
        const std::vector<std::shared_ptr<Face>>& getFaceList() const;
        const std::vector<Boundary>& getBoundaryList() const;
        const std::vector<int>& getOwnerIndexList() const;
        const std::vector<int>& getNeighborIndexList() const;

        int getFacesSize() const;
        int getCellsSize() const;

        void update();
        void loadGmsh2(std::string fileName);
        //std::vector<int> internalFaceIndexList;

        void exportVTK() const;

    private:
        void createFaces();
        void createBoundaries();
        void updateCellsIndexToFace();
        
        void updateCells();
        void updateFaces();
        void updateBoundaries();

        bool checkFaces() const;

        std::vector<Vector3> nodeList;
        std::vector<std::shared_ptr<Cell>> cellList;
        std::vector<std::shared_ptr<Face>> faceList;
        std::vector<Boundary> boundaryList;
        
        std::vector<int> ownerIndexList;
        std::vector<int> neighborIndexList;

        //load GMSH
        std::vector<std::string> readFile(std::string fileName);
        std::vector<std::vector<std::string>> parseBlockData(const std::vector<std::string>& dataIn, std::string blockName);
        void createNodesGmsh(const std::vector<std::vector<std::string>>& nodesGmsh);
        void createCellsGmsh(const std::vector<std::vector<std::string>>& cellsGmsh);
        void createBoundariesGmsh(const std::vector<std::vector<std::string>>& physicalNamesGmsh, const std::vector<std::vector<std::string>>& elementsGmsh);

};

#endif // MESH_H