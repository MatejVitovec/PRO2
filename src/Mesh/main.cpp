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

    return 0;
}