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
    myMesh.loadGmsh2("testMesh");

    const std::vector<std::shared_ptr<Cell>>& cells = myMesh.getCellList();
    const std::vector<std::shared_ptr<Face>>& faces = myMesh.getFaceList();
    const std::vector<Boundary>& boundaries = myMesh.getBoundaryList();

    double vol = 0.0;
    for (int i = 0; i < cells.size(); i++)
    {
        vol += fabs(cells[i]->volume);
    }

    Vector3 normal = Vector3(0.0, 0.0, 0.0);
    for (auto boundary : boundaries)
    {
        for (int i = 0; i < boundary.facesIndex.size(); i++)
        {
            normal = normal + (faces[boundary.facesIndex[i]]->area)*faces[boundary.facesIndex[i]]->normalVector;
        }
    }
    

    return 0;
}