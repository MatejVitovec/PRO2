#ifndef EQUATIONOFSTATE_H
#define EQUATIONOFSTATE_H

//prototype
class Compressible;

class EquationOfState
{
    public:
    
        EquationOfState() {}

        virtual double pressure(const Compressible& data) const = 0;
        virtual double internalEnergy(const Compressible& data) const = 0;
        virtual double soundSpeed(const Compressible& data) const = 0;

    protected:

};

#endif // EQUATIONOFSTATE_H