#ifndef HLLC_H
#define HLLC_H

#include "FluxSolver.hpp"

class Hllc : public FluxSolver
{
    public:

        Hllc() {}

        virtual ~Hllc() {}

        Vars claculateFlux(const Compressible& wl, const Compressible& wr, const Vector3& normalVector);

    private:


};

#endif // HLLC_H