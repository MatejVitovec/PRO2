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



void FVMScheme::updateTimeStep()
{
    const std::vector<std::shared_ptr<Cell>>& cells = mesh.getCellList();

    timeStep = 1000000;

    for (int i = 0; i < u.size(); i++)
    {
        double soundSpeed = u[i].soundSpeed();
        timeStep = std::min(cfl*((cells[i]->volume)/(cells[i]->projectedArea.x*(u[i].velocityU() + soundSpeed) + cells[i]->projectedArea.y*(u[i].velocityV() + soundSpeed) + cells[i]->projectedArea.z*(u[i].velocityW() + soundSpeed))), timeStep);
    }
}



void FVMScheme::getResults()
{

}

void FVMScheme::saveResults()
{

}