#include "FVMScheme.hpp"


void FVMScheme::setCfl(const double& cfl_)
{
    cfl = cfl_;
}

void FVMScheme::setMaxIter(const int& maxIter_)
{
    maxIter = maxIter_;
}

void FVMScheme::setTargetError(const double& targetError_)
{
    targetError = targetError_;
}

double FVMScheme::getCfl() const
{
    return cfl;
}

int FVMScheme::getMaxIter() const
{
    return maxIter;
}

double FVMScheme::getTargetError() const
{
    return targetError;
}

void FVMScheme::initialCondition(Compressible initialCondition)
{
    for (int i = 0; i < mesh.getCellsSize(); i++)
    {
        w[i] = initialCondition;
    }    
}


void FVMScheme::updateTimeStep()
{
    const std::vector<std::shared_ptr<Cell>>& cells = mesh.getCellList();

    timeStep = 1000000;

    for (int i = 0; i < w.size(); i++)
    {
        double soundSpeed = w[i].soundSpeed();
        timeStep = std::min(cfl*((cells[i]->volume)/(cells[i]->projectedArea.x*(w[i].velocityU() + soundSpeed) + cells[i]->projectedArea.y*(w[i].velocityV() + soundSpeed) + cells[i]->projectedArea.z*(w[i].velocityW() + soundSpeed))), timeStep);
    }
}


void FVMScheme::calculateFluxes()
{
    fluxes = fluxSolver->claculateFluxes(wl, wr, mesh.getFaceList());
}

void FVMScheme::getResults()
{

}

void FVMScheme::saveResults()
{

}