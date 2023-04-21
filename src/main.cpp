#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

#include "Mesh/Mesh.hpp"

#include "Vars.hpp"
#include "Field.hpp"
#include "Compressible.hpp"

//default eqs
std::shared_ptr<EquationOfState> Compressible::eqs = std::make_shared<IdealGas>();

int main(int argc, char** argv)
{
    /*Mesh myMesh = Mesh();
    myMesh.loadGmsh2("Mesh/testMesh");

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
    }*/

    
    Field<Compressible> pole(3);

    pole[0] = Compressible({1,2,3,5,6});
    pole[1] = Compressible({1,3,3,5,6});
    pole[2] = Compressible({1,2,8,7,9});

    Vars<5> promena = Vars<5>({5,4,8,9,3});

    Field<Compressible> pole2 = pole*promena;

    pole2 += pole;

    Compressible norma = pole.norm();

    return 0;
}