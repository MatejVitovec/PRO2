#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

#include "Mesh.hpp"

int main(int argc, char** argv)
{
    Mesh myMesh = Mesh();
    myMesh.loadGmsh2("t2");

    const std::vector<std::shared_ptr<Cell>>& cells = myMesh.getCellList();
    const std::vector<std::shared_ptr<Face>>& faces = myMesh.getFaceList();

    return 0;
}