#ifndef EQUATIONOFSTATE_HPP
#define EQUATIONOFSTATE_HPP

#include "../Vars.hpp"

//prototype
class Compressible;

class EquationOfState
{
    public:
    
        EquationOfState() {}

        virtual double pressure(const Compressible& data) const = 0;
        virtual double internalEnergy(const Compressible& data) const = 0;
        virtual double soundSpeed(const Compressible& data) const = 0;

        virtual Compressible primitiveToConservative(const Vars<5>& primitive) const = 0;

        virtual Compressible subsonicInletBoundaryState(const Compressible& inDomainState, const Vars<3>& normalVector, double totalPressure, double totaltemperature, Vars<3> velocityDirection) const = 0;
        
};

#endif // EQUATIONOFSTATE_HPP