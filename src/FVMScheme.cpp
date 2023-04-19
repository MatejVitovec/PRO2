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

double FVMScheme::updateTimeStep()
{


    return 0.0;
}

void FVMScheme::getResults()
{

}

void FVMScheme::saveResults()
{

}