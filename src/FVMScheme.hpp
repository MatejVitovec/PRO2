#ifndef FVMSCHEME_HPP
#define FVMSCHEME_HPP

#include <vector>
#include <memory>

#include "Mesh/Mesh.hpp"
#include "FluxSolver/FluxSolver.hpp"
#include "Compressible.hpp"
#include "Field.hpp"
#include "BoundaryCondition/BoundaryCondition.hpp"

class FVMScheme
{
    public:

        //vznikne obraz meshe - neprekopiruje se
        //FVMScheme() : mesh(Mesh()), w(Field<Compressible>()), wl(Field<Compressible>()), wr(Field<Compressible>()) {}
        FVMScheme(Mesh&& mesh_, std::unique_ptr<FluxSolver> fluxSolver_) : mesh(std::move(mesh_)), fluxSolver(std::move(fluxSolver_)), w(Field<Compressible>()), wl(Field<Compressible>()), wr(Field<Compressible>()) {}


        virtual ~FVMScheme() {}

        void setCfl(double cfl_);
        void setMaxIter(int maxIter_);
        void setTargetError(double targetError_);
        
        double getCfl() const;
        int getMaxIter() const;
        double getTargetError() const;
        const Mesh& getMesh() const;

        void setInitialConditions(Compressible initialCondition);
        void setInitialConditionsRiemann(Compressible initialConditionL, Compressible initialConditionR);
        void setBoundaryConditions(std::vector<std::unique_ptr<BoundaryCondition>> boundaryConditions);

        virtual void solve() = 0;

        Field<Compressible> getResults() const;
        
        
    protected:
        std::unique_ptr<FluxSolver> fluxSolver;

        Mesh mesh;
        std::vector<std::unique_ptr<BoundaryCondition>> boundaryConditionList;

        Field<Compressible> w; //cell size

        Field<Compressible> wl; //faces size
        Field<Compressible> wr;
        Field<Vars<5>> fluxes;

        double timeStep;
        double cfl;
        int maxIter;
        double targetError;

        void updateTimeStep();
        void applyBoundaryConditions();
        void calculateWlWr();
        void calculateFluxes();

    private:

};



#endif // FVMSCHEME_HPP