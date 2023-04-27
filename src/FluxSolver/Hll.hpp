#ifndef HLL_H
#define HLL_H

#include "FluxSolver.hpp"

class Hll : public FluxSolver
{
    public:

        Hll() {}

        virtual ~Hll() {}

        Vars<5> claculateFlux(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector);

    private:
        Vars<3> waveSpeedsEstimate(const Compressible& wl, const Compressible& wr, const Vars<3>& normalVector) const;

};

#endif // HLL_H