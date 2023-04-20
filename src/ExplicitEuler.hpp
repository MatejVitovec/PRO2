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


};



#endif // EXPLICITEULER_H