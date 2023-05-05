#include "FVMScheme.hpp"


void FVMScheme::setCfl(double cfl_)
{
    cfl = cfl_;
}

void FVMScheme::setMaxIter(int maxIter_)
{
    maxIter = maxIter_;
}

void FVMScheme::setTargetError(double targetError_)
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

const Mesh& FVMScheme::getMesh() const
{
    return mesh;
}

void FVMScheme::setInitialConditions(Compressible initialCondition)
{
    w = Field<Compressible>(mesh.getCellsSize());
    for (int i = 0; i < mesh.getCellsSize(); i++)
    {
        w[i] = initialCondition;
    }    
}

void FVMScheme::setInitialConditionsRiemann(Compressible initialConditionL, Compressible initialConditionR)
{
    w = Field<Compressible>(mesh.getCellsSize());
    int i = 0;
    for (i; i < 30; i++)
    {
        w[i] = initialConditionL;
    }
    for (i; i < mesh.getCellsSize(); i++)
    {
        w[i] = initialConditionR;
    }
}

void FVMScheme::applyBoundaryConditions()
{
    const std::vector<int>& ownerIndexList = mesh.getOwnerIndexList();
    const std::vector<std::shared_ptr<Face>>& faceList = mesh.getFaceList();

    for (auto & boundaryCondition : boundaryConditionList)
    {
        boundaryCondition->apply(ownerIndexList, faceList, w, wr);
    }
}

void FVMScheme::setBoundaryCondition(std::string boundaryName, int type)
{
    /*const std::vector<Boundary>& meshBoundaryList = mesh.getBoundaryList();
    Boundary aux;

    for (auto & meshBoundary : meshBoundaryList)
    {
        if(meshBoundary.boundaryConditionName == boundaryName)
        {
            aux = meshBoundary;
            break;
        }
    }

    //TODO udelat lepe
    if(type == BoundaryCondition::PRESSURETEMPERATUREINLET) boundaryConditionList.push_back(std::make_unique<PressureTemperatureInlet>(aux));
    else if(type == BoundaryCondition::PRESSUREOUTLET) boundaryConditionList.push_back(std::make_unique<PressureOutlet>(aux));
    else if(type == BoundaryCondition::FREEBOUNDARY) boundaryConditionList.push_back(std::make_unique<FreeBoundary>(aux));
    else if(type == BoundaryCondition::WALL) boundaryConditionList.push_back(std::make_unique<Wall>(aux));*/
}

void FVMScheme::setBoundaryConditions(std::vector<std::unique_ptr<BoundaryCondition>> boundaryConditions)
{
    boundaryConditionList = std::move(boundaryConditions);
}

void FVMScheme::calculateWlWr()
{
    //Without reconstruction

    const std::vector<std::shared_ptr<Cell>>& cells = mesh.getCellList();

    for (int i = 0; i < cells.size(); i++)
    {        
        for (auto & faceIndex : cells[i]->ownFaceIndex)
        {
            wl[faceIndex] = w[i];
        }

        for (auto & faceIndex : cells[i]->neighborFaceIndex)
        {
            wr[faceIndex] = w[i];
        }
    }

    //TODO udelat pres steny
    
}

void FVMScheme::updateTimeStep()
{
    const std::vector<std::shared_ptr<Cell>>& cells = mesh.getCellList();

    timeStep = 1000000;

    for (int i = 0; i < w.size(); i++)
    {
        double soundSpeed = w[i].soundSpeed();
        Vars<3> ssVector({soundSpeed, soundSpeed, soundSpeed});
        timeStep = std::min(cfl*((cells[i]->volume)/sum((abs(w[i].velocity()) + ssVector)*vector3toVars(cells[i]->projectedArea))), timeStep);
        
        //timeStep = std::min(cfl*((cells[i]->volume)/(cells[i]->projectedArea.x*(w[i].velocityU() + soundSpeed) + cells[i]->projectedArea.y*(w[i].velocityV() + soundSpeed) + cells[i]->projectedArea.z*(w[i].velocityW() + soundSpeed))), timeStep);
    }
}

void FVMScheme::calculateFluxes()
{
    fluxes = fluxSolver->claculateFluxes(wl, wr, mesh.getFaceList());
}

Field<Compressible> FVMScheme::getResults() const
{
    return w;
}