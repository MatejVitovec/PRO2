#ifndef COMPRESSIBLE_H
#define COMPRESSIBLE_H

#include <vector>
#include <memory>

#include "Vars.hpp"
#include "EquationOfState.hpp"
#include "IdealGas.hpp"

class Compressible : public Vars
{
    public:
        enum {RHO, RHO_U, RHO_V, RHO_W, RHO_E};

        Compressible() : Vars() {}
        Compressible(const std::array<double, 5>& in) : Vars(in) {}

        virtual ~Compressible() {}

        void operator+=(const Compressible& v);
        void operator-=(const Compressible& v);
        void operator+=(const Vars& v);
        void operator-=(const Vars& v);

        static void setEquationOfState(std::shared_ptr<EquationOfState> eqs_);        

        double density() const;
        double absVelocity() const;
        double velocityU() const;
        double velocityV() const;
        double velocityW() const;
        double totalEnergy() const;

        double pressure() const;
        double internalEnergy() const;
        double soundSpeed() const;

        Compressible flux() const;
        Vars primitive() const;

    private:
        static std::shared_ptr<EquationOfState> eqs;
};



//////////////Non member operators///////////////////


// u + v
Compressible operator+ (const Compressible& u, const Compressible& v);

// u - v
Compressible operator- (const Compressible& u, const Compressible& v);

// w * u
Compressible operator* (const Compressible& u, const Compressible& v);

// a * u
Compressible operator* (const double& a, const Compressible& u);

// u * a
Compressible operator* ( const Compressible& u, const double& a);

// u / a
Compressible operator/ (const Compressible& u, const double& a);

// Compressible, Vars

// u + v
Compressible operator+ (const Compressible& u, const Vars& v);

// u - v
Compressible operator- (const Compressible& u, const Vars& v);

// w * u
Compressible operator* (const Compressible& u, const Vars& v);



//////////////Non member function///////////////////

Compressible sqrt(const Compressible& u);

#endif // COMPRESSIBLE_H