#include "ExplicitEuler.hpp"
#include <iostream>
#include "outputCFD.hpp"


void ExplicitEuler::solve()
{

    //mozna presun do konstruktoru
    wl = Field<Compressible>(mesh.getFacesSize());
    wr = Field<Compressible>(mesh.getFacesSize());

    int iter = 0;

    double time = 0;
    bool exitLoop = false;

    while (iter < maxIter && !exitLoop)
    {
        iter++;

        updateTimeStep();
        time += timeStep;

        applyBoundaryConditions();

        calculateWlWr();

        calculateFluxes();

        Field<Vars<5>> res = calculateResidual();
        
        Field<Compressible> wn = explicitIntegration(res);

        Vars<5> resNorm = (wn - w).norm(); //mozna spatne
        saveResidual("results/residuals.txt", resNorm);

        if(resNorm[0] < targetError) exitLoop = true;
        

        w = std::move(wn); //mozna to bude fungovat

        if(iter % 500 == 0)
        {
            outputVTK("results/results." + std::to_string(iter) + ".vtk", mesh, w);
            std::cout << "iter: " << iter << std::endl;
        }
    }

    std::cout << "time: " << time << std::endl;
    
}

Field<Vars<5>> ExplicitEuler::calculateResidual()
{
    const std::vector<Cell>& cells = mesh.getCellList();
    const std::vector<Face>& faces = mesh.getFaceList();

    Field<Vars<5>> res(w.size());

    for (int i = 0; i < cells.size(); i++)
    {
        Vars<5> aux= Vars<5>();

        for (auto & faceIndex : cells[i].ownFaceIndex)
        {
            aux -= fluxes[faceIndex];
        }

        for (auto & faceIndex : cells[i].neighborFaceIndex)
        {
            aux += fluxes[faceIndex];
        }

        res[i] = aux/(cells[i].volume);
    }    
    
    return res;
}

Field<Compressible> ExplicitEuler::explicitIntegration(const Field<Vars<5>>& res)
{
    Field<Compressible>wn(w.size());

    for (int i = 0; i < w.size(); i++)
    {
        wn[i] = w[i] + timeStep*res[i];        
    }
    
    return wn;
}