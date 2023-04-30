#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

#include "Mesh/Mesh.hpp"
#include "ExplicitEuler.hpp"
#include "FluxSolver/Hll.hpp"
#include "outputVTK.hpp"

//default eqs
std::shared_ptr<EquationOfState> Compressible::eqs = std::make_shared<IdealGas>();

int main(int argc, char** argv)
{
    Mesh myMesh = Mesh();
    myMesh.loadGmsh2("Mesh/riemannMesh.msh");

    const std::vector<std::shared_ptr<Cell>>& cellList = myMesh.getCellList();
    double vol = 0;
    for (int i = 0; i < myMesh.getCellsSize(); i++)
    {
        vol += cellList[i]->volume;
    }
    

    std::unique_ptr<FluxSolver> myFluxSolver = std::make_unique<Hll>();

    ExplicitEuler mySolver(myMesh, std::move(myFluxSolver));

    mySolver.setCfl(0.8);
    mySolver.setMaxIter(60);
    mySolver.setTargetError(0.0000005);

    mySolver.setBoundaryCondition("bottom", 1);
    mySolver.setBoundaryCondition("outlet", 1);
    mySolver.setBoundaryCondition("top", 1);
    mySolver.setBoundaryCondition("inlet", 1);
    mySolver.setBoundaryCondition("back", 1);
    mySolver.setBoundaryCondition("front", 1);

    mySolver.setInitialConditionsRiemann(Compressible({1.0, 0.75, 0.0, 0.0, 1.0}), Compressible({0.125, 0.0, 0.0, 0.0, 0.1}));

    mySolver.solve();

    outputVTK("results.vtk", myMesh, mySolver.getResults());

    int a = 5;


    /*Compressible a({1.0, 2.0, 3.0, 4.0, 5.0});
    Vars<5> b({1.0, 2.0, 3.0, 4.0, 5.0});

    Vars<5> c = a + b;

    
    Field<Compressible> pole(3);

    pole[0] = Compressible({1,2,3,5,6});
    pole[1] = Compressible({1,3,3,5,6});
    pole[2] = Compressible({1,2,8,7,9});

    Vars<5> promena = Vars<5>({5,4,8,9,3});

    Field<Compressible> pole2 = pole*promena;

    pole2 += pole;

    Compressible norma = pole.norm();*/

    return 0;
}