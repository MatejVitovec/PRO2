#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include <chrono>

#include "Mesh/Mesh.hpp"
#include "ExplicitEuler.hpp"
#include "FluxSolver/Hll.hpp"
#include "FluxSolver/Hllc.hpp"
#include "outputVTK.hpp"
#include "setCFD.hpp"



//default eqs
std::shared_ptr<EquationOfState> Compressible::eqs = std::make_shared<IdealGas>();

int main(int argc, char** argv)
{
    Mesh myMesh = Mesh();

    //auto stop1 = std::chrono::high_resolution_clock::now();

    myMesh.loadGmsh2("Mesh/GAMM_fine.msh");

    /*auto stop2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(stop2 - stop1).count() << " ms\n";

    const std::vector<std::shared_ptr<Cell>>& cellList = myMesh.getCellList();
    double vol = 0;
    for (int i = 0; i < myMesh.getCellsSize(); i++)
    {
        vol += cellList[i]->volume;
    }
    
    std::cout << "Volume: " << vol << std::endl;*/


    std::unique_ptr<FluxSolver> myFluxSolver = std::make_unique<Hllc>();

    ExplicitEuler mySolver(std::move(myMesh), std::move(myFluxSolver));

    mySolver.setCfl(0.8);
    mySolver.setMaxIter(100000);
    mySolver.setTargetError(0.0000005);

    std::vector<std::unique_ptr<BoundaryCondition>> bc = createBoundaryCondition(mySolver.getMesh());

    mySolver.setBoundaryConditions(std::move(bc));

    /*Compressible leftState = Compressible::primitiveToConservative(Vars<5>({1.0, 0.75, 0.0, 0.0, 1.0}));
    Compressible rightState = Compressible::primitiveToConservative(Vars<5>({0.125, 0.0, 0.0, 0.0, 0.1}));
    mySolver.setInitialConditionsRiemann(leftState, rightState);*/
    mySolver.setInitialConditions(Compressible::primitiveToConservative(Vars<5>({1.0, 0.0, 0.0, 0.0, 0.7143})));

    outputVTK("results/results.0.vtk", mySolver.getMesh(), mySolver.getResults());

    mySolver.solve();

    int a = 5;

    return 0;
}