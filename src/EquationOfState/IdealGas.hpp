#ifndef IDEALGAS_H
#define IDEALGAS_H

#include "EquationOfState.hpp"

class IdealGas : public EquationOfState
{
    public:

        IdealGas() : EquationOfState(), gamma(1.4), R(287.05) {}
        IdealGas(double gamma, double R) : EquationOfState(), gamma(gamma), R(R) {}

        void setGamma(double gamma_);
        void setR(double R_);
        double getGamma() const;
        double getR() const;

        //overwritten virtual
        double pressure(const Compressible& data) const;
        double internalEnergy(const Compressible& data) const;
        double soundSpeed(const Compressible& data) const;

        Compressible primitiveToConservative(const Vars<5>& primitive) const;

    private:
        double gamma;
        double R;

};

#endif // IDEALGAS_H