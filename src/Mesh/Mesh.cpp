#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Mesh.hpp"


Mesh::Mesh()
{
    
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

void Mesh::loadGmsh2(std::string fileName)
{
    std::vector<std::string> stringData = readFile(fileName);

    createNodesGmsh(parseBlockData(stringData, "Nodes"));
    createCellsGmsh(parseBlockData(stringData, "Elements"));

    createFaces();
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

    for (int i = 1; i < cellsGmsh.size(); i++)
    {
        if(stoi(cellsGmsh[i][0]) == i)
        {
            int numOfTags = stoi(cellsGmsh[i][2]);

            switch (stoi(cellsGmsh[i][1]))
            {
            case 4:
                //std::vector<int> temp = {0,0,0,0};
                cellList.push_back(std::make_shared<TetrahedronCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]), stoi(cellsGmsh[i][4+numOfTags]), stoi(cellsGmsh[i][5+numOfTags]), stoi(cellsGmsh[i][6+numOfTags])}));
                break;
            case 5:
                //cellList.push_back(std::make_shared<HexahedronCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]), stoi(cellsGmsh[i][4+numOfTags]), stoi(cellsGmsh[i][5+numOfTags]), stoi(cellsGmsh[i][6+numOfTags]), stoi(cellsGmsh[i][7+numOfTags]), stoi(cellsGmsh[i][8+numOfTags]), stoi(cellsGmsh[i][9+numOfTags]), stoi(cellsGmsh[i][10+numOfTags])}));
                break;
            case 6:
                //cellList.push_back(std::make_shared<PrismCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]), stoi(cellsGmsh[i][4+numOfTags]), stoi(cellsGmsh[i][5+numOfTags]), stoi(cellsGmsh[i][6+numOfTags]), stoi(cellsGmsh[i][7+numOfTags]), stoi(cellsGmsh[i][8+numOfTags])}));
                break;
            case 7:
                //cellList.push_back(std::make_shared<PyramidCell>(std::vector<int>{stoi(cellsGmsh[i][3+numOfTags]), stoi(cellsGmsh[i][4+numOfTags]), stoi(cellsGmsh[i][5+numOfTags]), stoi(cellsGmsh[i][6+numOfTags]), stoi(cellsGmsh[i][7+numOfTags])}));
                break;
            
            default:
                //std::cout << "Neplatný typ 3D bunky" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Chybejici Cell, index:" << i << std::endl;
            //cellList.push_back(std::make_shared<Cell>());
        }
    }
}