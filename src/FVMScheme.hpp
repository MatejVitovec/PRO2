#ifndef FVMSCHEME_H
#define FVMSCHEME_H

#include <vector>
#include <memory>

#include "Compressible.hpp"
#include "Mesh/Mesh.hpp"
#include "Field.hpp"

class FVMScheme
{
    public:

        FVMScheme() : mesh(Mesh()), u(Field<Compressible>()) {}
        FVMScheme(Mesh mesh_) : mesh(mesh_), u(Field<Compressible>()) {}

        virtual ~FVMScheme() {}

        void setCfl(const double& cfl_);
        void setMaxIter(const int& maxIter_);
        void setTargetError(const double& targetError_);
        double getCfl() const;
        int getMaxIter() const;
        double getTargetError() const;

        void updateTimeStep();

        virtual void solve() = 0;

        void getResults();
        void saveResults();
        
        

    protected:
        Field<Compressible> u;
        Mesh mesh;

        double timeStep;
        double cfl;
        int maxIter;
        double targetError;

};



#endif // FVMSCHEME_H