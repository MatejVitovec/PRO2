#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

#include "Mesh.hpp"


Mesh::Mesh()
{
    
}

void Mesh::loadGmsh2(std::string fileName)
{
    std::vector<std::string> stringData = readFile(fileName);

    createNodesGmsh(parseBlockData(stringData, "Nodes"));
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
            std::cout << "chybejici Node index:" << i << std::endl;
            nodeList.push_back(Vector3());
        }
    }
}