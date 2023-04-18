#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

//#include "Mesh/Mesh.hpp"

#include "Vars.hpp"
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

    

    Compressible a({1,2,3,5,6});
    Vars b({1,2,3,5,6});
    Vars d({1,2,3,5,6});

    Compressible::setEquationOfState(std::make_shared<IdealGas>());

    a[1] = 5.0;
    
    Vars x = b + d;

    b += d;
    a -= ((-2.0)*a);

    Compressible c(a);
    Compressible e({1,2,3,5,8});

    //Compressible c = a + b;

    return 0;
}