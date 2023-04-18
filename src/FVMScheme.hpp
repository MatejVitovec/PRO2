#ifndef FVMSCHEME_H
#define FVMSCHEME_H

#include <vector>
#include <memory>

#include "Compressible.hpp"
#include "Mesh/Mesh.hpp"

class FVMScheme
{
    public:

        FVMScheme() {}
        FVMScheme(Mesh mesh_) : mesh(mesh_) {}

        virtual ~FVMScheme() {}

        virtual double updateTimeStep();

        virtual void solve() = 0;

        void getResults();
        void saveResults();
        
        

    protected:
        std::vector<Compressible> u;
        Mesh mesh;

        double timeStep;

};



#endif // FVMSCHEME_H