#ifndef EXPLICITEULER_H
#define EXPLICITEULER_H

#include "FVMScheme.hpp"

class ExplicitEuler : public FVMScheme
{
    public:

        ExplicitEuler() : FVMScheme() {}
        ExplicitEuler(Mesh mesh_) : FVMScheme(mesh_) {}

        virtual ~ExplicitEuler() {}

        void solve();        
        

    private:
    
        Field<Vars<5>> calculateResidual();
        Field<Compressible> explicitIntegration(const Field<Vars<5>>& res);
        

};



#endif // EXPLICITEULER_H