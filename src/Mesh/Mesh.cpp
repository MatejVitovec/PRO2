#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Mesh.hpp"


const std::vector<Vector3>& Mesh::getNodeList() const
{
    return nodeList;
}

const std::vector<std::shared_ptr<Cell>>& Mesh::getCellList() const
{
    return cellList;
}

const std::vector<std::shared_ptr<Face>>& Mesh::getFaceList() const
{
    return faceList;
}

const std::vector<Boundary>& Mesh::getBoundaryList() const
{
    return boundaryList;
}

const std::vector<int>& Mesh::getOwnerIndexList() const
{
    return ownerIndexList;
}

const std::vector<int>& Mesh::getNeighborIndexList() const
{
    return neighborIndexList;
}

int Mesh::getNodesSize() const
{
    return nodeList.size();
}

int Mesh::getFacesSize() const
{
    return faceList.size();
}

int Mesh::getCellsSize() const
{
    return cellList.size();
}

void Mesh::update()
{
    updateFaces();
    updateCells();
}

void Mesh::createFaces()
{
    faceList.clear();
    ownerIndexList.clear();

    //vytvoreni sten + ownerList
    for (int j = 0; j < cellList.size(); j++)
    {
        std::vector<std::shared_ptr<Face>> ownFaces = cellList[j]->createFaces();

        for (auto & ownFace : ownFaces)
        {
            bool existInList = false;

            for (int i = 0; i < faceList.size(); i++)
            {
                if (faceList[i]->equal(*ownFace))
                {
                    existInList = true;
                }                
            }

            if (!existInList)
            {
                faceList.push_back(ownFace);
                ownerIndexList.push_back(j);
            }
        }
    }

    //naplneni pole sousedu
    neighborIndexList = std::vector<int>(faceList.size(), -1);

    for (int j = 0; j < cellList.size(); j++)
    {
        std::vector<std::shared_ptr<Face>> ownFaces = cellList[j]->createFaces();

        for (auto & ownFace : ownFaces)
        {
            for (int i = 0; i < faceList.size(); i++)
            {
                if (faceList[i]->equal(*ownFace) && ownerIndexList[i] != j)
                {
                    neighborIndexList[i] = j;
                    break;
                }
            }
        }
    }
}

void Mesh::updateCellsIndexToFace()
{
    for(int j = 0; j < cellList.size(); j++)
    {
        cellList[j]->ownFaceIndex.clear();
        cellList[j]->neighborFaceIndex.clear();

        for (int i = 0; i < ownerIndexList.size(); i++)
        {
            if(ownerIndexList[i] == j)
            {
                cellList[j]->ownFaceIndex.push_back(i);
            }
        }

        for (int i = 0; i < neighborIndexList.size(); i++)
        {
            if(neighborIndexList[i] == j)
            {
                cellList[j]->neighborFaceIndex.push_back(i);
            }
        }
    }
}

void Mesh::updateCells()
{
    for(auto & cell : cellList)
    {
        cell->update(faceList);
    }
}

void Mesh::updateFaces()
{
    for(auto & face : faceList)
    {
        face->update(nodeList);
    }
}

bool Mesh::checkFaces() const
{
    bool fail = false;

    //kontrola sten na nenulovy obsah
    for (auto & face : faceList)
    {
        if(face->check())
        {
            std::cout << "stena neprosla kontorlou na nenulovy obsah" << std::endl;
            fail = true;
        }
    }

    //kontrola na opakujici se bunky
    for (int j = 0; j < faceList.size(); j++)
    {
        for (int i = 0; i < faceList.size(); i++)
        {
            if(i != j)
            {
                if(faceList[i]->equal(*faceList[j]))
                {
                    std::cout << "v seznamuz sten je duplikat i:" << j << " j: "<< i << std::endl;
                    fail = true;
                }
            }
        }
    }

    return fail;
}

void Mesh::updateBoundaries()
{
    //TODO
}

void Mesh::loadGmsh2(std::string fileName)
{
    std::vector<std::string> stringData = readFile(fileName);

    createNodesGmsh(parseBlockData(stringData, "Nodes"));
    createCellsGmsh(parseBlockData(stringData, "Elements"));

    createFaces();
    createBoundariesGmsh(parseBlockData(stringData, "PhysicalNames"), parseBlockData(stringData, "Elements"));
    updateCellsIndexToFace();

    update();
}

std::vector<std::string> Mesh::readFile(std::string fileName)
{
    std::ifstream stream;
    std::string line;
    std::vector<std::string> data;

    stream.open(fileName, std::ios_base::in);

    if (stream.is_open())
    {
        while (std::getline(stream, line))
        {
            line.pop_back();
            data.push_back(line);
        }
    }
    stream.close();

    return data;
}

std::vector<std::vector<std::string>> Mesh::parseBlockData(const std::vector<std::string>& dataIn, std::string blockName)
{
    std::vector<std::vector<std::string>> out;

    int lineIndex = 0;

    while (dataIn[lineIndex] != ("$" + blockName))
    {
        ++lineIndex;
    }
    ++lineIndex;

    while(dataIn[lineIndex] != ("$End" + blockName))
    {
        std::vector<std::string> rowData;

        std::string w = "";
        for (auto x : dataIn[lineIndex]) 
        {
            if (x == ' ')
            {
                rowData.push_back(w);
                w = "";
            }
            else
            {
                w = w + x;
            }
        }
        rowData.push_back(w);
        out.push_back(rowData);
        ++lineIndex;
    }

    return out;
}


void Mesh::createNodesGmsh(const std::vector<std::vector<std::string>>& nodesGmsh)
{
    int nodesSum = stoi(nodesGmsh[0][0]);

    nodeList.clear();

    for (int i = 1; i < nodesGmsh.size(); i++)
    {
        if(stoi(nodesGmsh[i][0]) == i)
        {
            nodeList.push_back(Vector3(stof(nodesGmsh[i][1]), stof(nodesGmsh[i][2]), stof(nodesGmsh[i][3])));
        }
        else
        {
            std::cout << "Chybejici Node, index:" << i << std::endl;
            nodeList.push_back(Vector3());
        }
    }
}

void Mesh::createCellsGmsh(const std::vector<std::vector<std::string>>& cellsGmsh)
{
    int cellsSum = stoi(cellsGmsh[0][0]);

    cellList.clear();

    //TODO -> for( auto : ...), index from file (not for)
    for (int i = 1; i < cellsGmsh.size(); i++)
    {
        if(stoi(cellsGmsh[i][0]) == i)
        {
            int numOfTags = stoi(cellsGmsh[i][2]);

            switch (stoi(cellsGmsh[i][1]))
            {
            case 4:
                cellList.push_back(std::make_shared<TetrahedronCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]) - 1, stoi(cellsGmsh[i][4+numOfTags]) - 1, stoi(cellsGmsh[i][5+numOfTags]) - 1, stoi(cellsGmsh[i][6+numOfTags]) - 1}));
                break;
            case 5:
                cellList.push_back(std::make_shared<HexahedronCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]) - 1, stoi(cellsGmsh[i][4+numOfTags]) - 1, stoi(cellsGmsh[i][5+numOfTags]) - 1, stoi(cellsGmsh[i][6+numOfTags]) - 1, stoi(cellsGmsh[i][7+numOfTags]) - 1, stoi(cellsGmsh[i][8+numOfTags]) - 1, stoi(cellsGmsh[i][9+numOfTags]) - 1, stoi(cellsGmsh[i][10+numOfTags]) - 1}));
                break;
            case 6:
                cellList.push_back(std::make_shared<PrismCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]) - 1, stoi(cellsGmsh[i][4+numOfTags]) - 1, stoi(cellsGmsh[i][5+numOfTags]) - 1, stoi(cellsGmsh[i][6+numOfTags]) - 1, stoi(cellsGmsh[i][7+numOfTags]) - 1, stoi(cellsGmsh[i][8+numOfTags]) - 1}));
                break;
            case 7:
                cellList.push_back(std::make_shared<PyramidCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]) - 1, stoi(cellsGmsh[i][4+numOfTags]) - 1, stoi(cellsGmsh[i][5+numOfTags]) - 1, stoi(cellsGmsh[i][6+numOfTags]) - 1, stoi(cellsGmsh[i][7+numOfTags]) - 1}));
                break;
            
            default:
                //std::cout << "Neplatný typ 3D bunky na pozici" << i << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Chybejici Cell, index:" << i << std::endl;
            cellList.push_back(std::make_shared<Cell>());
        }
    }
}

void Mesh::createBoundariesGmsh(const std::vector<std::vector<std::string>>& physicalNamesGmsh, const std::vector<std::vector<std::string>>& elementsGmsh)
{
    boundaryList.clear();

    std::vector<std::shared_ptr<Face>> auxFaceList;
    auxFaceList.clear();
    std::vector<int> auxFacePhysicalGroupList;
    auxFacePhysicalGroupList.clear();

    //TODO -> for( auto : ...), index from file (not for)
    for (int i = 1; i < elementsGmsh.size(); i++)
    {
        if(stoi(elementsGmsh[i][0]) == i)
        {
            int numOfTags = stoi(elementsGmsh[i][2]);

            switch (stoi(elementsGmsh[i][1]))
            {
            case 2:
                auxFaceList.push_back(std::make_shared<TriangularFace>(std::vector<int>{stoi(elementsGmsh[i][3+numOfTags]) - 1, stoi(elementsGmsh[i][4+numOfTags]) - 1, stoi(elementsGmsh[i][5+numOfTags]) - 1}));
                auxFacePhysicalGroupList.push_back(stoi(elementsGmsh[i][3]));
                break;
            case 3:
                auxFaceList.push_back(std::make_shared<QuadrilateralFace>(std::vector<int>{stoi(elementsGmsh[i][3+numOfTags]) - 1, stoi(elementsGmsh[i][4+numOfTags]) - 1, stoi(elementsGmsh[i][5+numOfTags]) - 1, stoi(elementsGmsh[i][6+numOfTags]) - 1}));
                auxFacePhysicalGroupList.push_back(stoi(elementsGmsh[i][3]));
                break;
            
            default:
                //std::cout << "Neplatný typ 3D bunky na pozici" << i << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Chybejici Cell, index:" << i << std::endl;
            cellList.push_back(std::make_shared<Cell>());
        }
    }

    for (int j = 1; j < physicalNamesGmsh.size(); j++)
    {
        if(stoi(physicalNamesGmsh[j][0]) != 2)
        {
            continue;
        }

        int physicalId = stoi(physicalNamesGmsh[j][1]);
        std::string physicalName = physicalNamesGmsh[j][2];
        physicalName.erase(0,1);
        physicalName.pop_back();

        Boundary auxBoundary = Boundary(physicalName);

        for (int j = 0; j < auxFacePhysicalGroupList.size(); j++)
        {
            if(auxFacePhysicalGroupList[j] == physicalId)
            {
                for (int i = 0; i < faceList.size(); i++)
                {
                    if(faceList[i]->equal(*auxFaceList[j]))
                    {
                        auxBoundary.facesIndex.push_back(i);
                    }
                }                
            }
        }
        
        boundaryList.push_back(auxBoundary);
    }
}


void Mesh::exportVTK() const
{


}