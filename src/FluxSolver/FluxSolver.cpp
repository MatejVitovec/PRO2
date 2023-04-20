#include "FluxSolver.hpp"

Vars FluxSolver::normalFlux(const Compressible& w, const Vector3& normalVector) const
{
    //predelat na Vars<3>
    /*return Vars({w.density()*(w.velocityU()*normalVector.x + w.velocityV()*normalVector.y + w.velocityW()*normalVector.z),
                w.density()
                });*/         //TODO
    return Vars();
}

Field<Vars> FluxSolver::claculateFluxes(const Field<Compressible>& wl, const Field<Compressible>& wr, const std::vector<std::shared_ptr<Face>>& faceList) const
{
    Field<Vars> out(wl.size());

    for (int i = 0; i < wl.size(); i++)
    {
        out[i] = claculateFlux(wl[i], wr[i], faceList[i]->normalVector);
    }
    
}