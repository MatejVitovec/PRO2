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

        static void setEquationOfState(std::shared_ptr<EquationOfState> eqs_);

        virtual ~Compressible() {}

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




//////////////operators///////////////////

inline bool operator== (const Compressible& u, const Vars& v)
{
    //ble
    return u[0] == v[0] && u[1] == v[1] && u[2] == v[2] && u[3] == v[3] && u[4] == v[4];
}


// u + v
inline Compressible operator+ (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
inline Compressible operator- (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
inline Compressible operator* (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

// a * u
inline Compressible operator* (double a, const Compressible& u)
{
    return Compressible({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u / a
inline Compressible operator/ (const Compressible& u, double a)
{
    return Compressible({u[0]/a, u[1]/a, u[2]/a, u[3]/a, u[4]/a});
}

// Compressible, Vars

// u + v
inline Compressible operator+ (const Compressible& u, const Vars& v)
{
    return Compressible({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
inline Compressible operator- (const Compressible& u, const Vars& v)
{
    return Compressible({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
inline Compressible operator* (const Compressible& u, const Vars& v)
{
    return Compressible({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

#endif // COMPRESSIBLE_H