#ifndef EQUATIONOFSTATE_H
#define EQUATIONOFSTATE_H

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
        
};

#endif // EQUATIONOFSTATE_H