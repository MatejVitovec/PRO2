#include "ExplicitEuler.hpp"



void ExplicitEuler::solve()
{

    //mozna presun do konstruktoru
    wl = Field<Compressible>(mesh.getFacesSize());
    wr = Field<Compressible>(mesh.getFacesSize());

    int iter = 0;

    while (iter < maxIter)
    {
        iter++;

        updateTimeStep();

        // ? gradient ?

        // wl / wr

        calculateFluxes();

        //calc reziduum
        
        //numerical integration - Euler

        //rezisuum check

        //stream


    }
    
}