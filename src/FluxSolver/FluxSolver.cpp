#include <cmath>

#include "FluxSolver.hpp"

/*Vars<5> FluxSolver::normalFlux(const Compressible& w, const Vector3& normalVector) const
{
    double density = w.density();
    Vars<3> velocity = w.velocity();
    double pressure = w.pressure();
    double enthalpy = w.totalEnergy() + pressure/density;

    Vars<3>normal = vector3toVars(normalVector);
    double dotVelocityNormal = dot(velocity, normal);

    return Vars<5>({density * dotVelocityNormal,
                    density * velocity[0] * dotVelocityNormal + pressure * normal[0],
                    density * velocity[1] * dotVelocityNormal + pressure * normal[1],
                    density * velocity[2] * dotVelocityNormal + pressure * normal[2],
                    density * enthalpy * dotVelocityNormal});
}*/

Field<Vars<5>> FluxSolver::claculateFluxes(const Field<Compressible>& wl, const Field<Compressible>& wr, const std::vector<std::shared_ptr<Face>>& faceList) const
{
    Field<Vars<5>> out(wl.size());

    for (int i = 0; i < wl.size(); i++)
    {
        out[i] = claculateFlux(wl[i], wr[i], vector3toVars(faceList[i]->normalVector))*faceList[i]->area;
    }
    
    return out;
}