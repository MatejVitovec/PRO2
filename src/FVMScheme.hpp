#ifndef FVMSCHEME_H
#define FVMSCHEME_H

#include <vector>
#include <memory>

#include "Mesh/Mesh.hpp"
#include "FluxSolver/FluxSolver.hpp"
#include "Compressible.hpp"
#include "Field.hpp"

class FVMScheme
{
    public:

        FVMScheme() : mesh(Mesh()), w(Field<Compressible>()), wl(Field<Compressible>()), wr(Field<Compressible>()) {}
        FVMScheme(Mesh mesh_) : mesh(mesh_), w(Field<Compressible>()), wl(Field<Compressible>()), wr(Field<Compressible>()) {}
        FVMScheme(Mesh mesh_, std::unique_ptr<FluxSolver> fluxSolver_) : mesh(mesh_), w(Field<Compressible>()) , fluxSolver(std::move(fluxSolver_)), wl(Field<Compressible>()), wr(Field<Compressible>()) {}


        virtual ~FVMScheme() {}

        void setCfl(const double& cfl_);
        void setMaxIter(const int& maxIter_);
        void setTargetError(const double& targetError_);
        double getCfl() const;
        int getMaxIter() const;
        double getTargetError() const;

        void initialCondition(Compressible initialCondition);

        virtual void solve() = 0;

        void getResults();
        void saveResults();
        
        
    protected:
        std::unique_ptr<FluxSolver> fluxSolver;

        Mesh mesh;

        Field<Compressible> w;

        Field<Compressible> wl;
        Field<Compressible> wr;
        Field<Vars> fluxes;

        double timeStep;
        double cfl;
        int maxIter;
        double targetError;

        void updateTimeStep();
        void calculateFluxes();

    private:

};



#endif // FVMSCHEME_H