#ifndef HLLC_H
#define HLLC_H

#include "FluxSolver.hpp"

class Hllc : public FluxSolver
{
    public:

        Hllc() {}

        virtual ~Hllc() {}

        Vars<5> claculateFlux(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector);

    private:
        Vars<3> waveSpeedsEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const;

};

#endif // HLLC_H