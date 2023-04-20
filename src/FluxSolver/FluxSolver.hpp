#ifndef FLUXSOLVER_H
#define FLUXSOLVER_H

#include "../Mesh/Mesh.hpp"
#include "Field.hpp"
#include "Compressible.hpp"

class FluxSolver
{
    public:

        FluxSolver() {}

        virtual ~FluxSolver() {}

        Field<Vars> claculateFluxes(const Field<Compressible>& wl, const Field<Compressible>& wr, const std::vector<std::shared_ptr<Face>>& faceList) const;
        virtual Vars claculateFlux(const Compressible& wl, const Compressible& wr, const Vector3& normalVector) const = 0;

    protected:
        Vars normalFlux(const Compressible& w, const Vector3& normalVector) const;

};

#endif // FLUXSOLVER_H