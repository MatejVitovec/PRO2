#ifndef COMPRESSIBLE_H
#define COMPRESSIBLE_H

#include <vector>
#include <memory>

#include "Vars.hpp"
#include "EquationOfState.hpp"

class Compressible : public Vars
{
    public:
        enum {RHO, RHO_U, RHO_V, RHO_W, RHO_E};

        Compressible() {};

        Compressible(const std::array<double, 5>& in) : Vars(in), eqs(std::make_shared<EquationOfState>()) {};

        virtual ~Compressible() {};

        double density() const;
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
        std::shared_ptr<EquationOfState> eqs;
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
    Compressible out;
    out[0] = u[0] + v[0];
    out[1] = u[1] + v[1];
    out[2] = u[2] + v[2];
    out[3] = u[3] + v[3];
    out[4] = u[4] + v[4];
    return out;
}

// u - v
inline Compressible operator- (const Compressible& u, const Compressible& v)
{
    Compressible out;
    out[0] = u[0] - v[0];
    out[1] = u[1] - v[1];
    out[2] = u[2] - v[2];
    out[3] = u[3] - v[3];
    out[4] = u[4] - v[4];
    return out;
}

// a * u
inline Compressible operator* (double a, const Compressible& u)
{
    Compressible out;
    out[0] = a * u[0];
    out[1] = a * u[1];
    out[2] = a * u[2];
    out[3] = a * u[3];
    out[4] = a * u[4];
    return out;
}

// w * u
inline Compressible operator* (const Compressible& w, const Compressible& u)
{
    Compressible out;
    out[0] = w[0] * u[0];
    out[1] = w[1] * u[1];
    out[2] = w[2] * u[2];
    out[3] = w[3] * u[3];
    out[4] = w[4] * u[4];
    return out;
}

// u / a
inline Compressible operator/ (const Compressible& u, double a)
{
    Compressible out;
    out[0] = u[0] / a;
    out[1] = u[1] / a;
    out[2] = u[2] / a;
    out[3] = u[3] / a;
    out[4] = u[4] / a;
    return out;
}

// u + v
inline Compressible operator+ (const Compressible& u, const Vars& v)
{
    Compressible out;
    out[0] = u[0] + v[0];
    out[1] = u[1] + v[1];
    out[2] = u[2] + v[2];
    out[3] = u[3] + v[3];
    out[4] = u[4] + v[4];
    return out;
}

// u - v
inline Compressible operator- (const Compressible& u, const Vars& v)
{
    Compressible out;
    out[0] = u[0] - v[0];
    out[1] = u[1] - v[1];
    out[2] = u[2] - v[2];
    out[3] = u[3] - v[3];
    out[4] = u[4] - v[4];
    return out;
}

// w * u
inline Compressible operator* (const Compressible& w, const Vars& u)
{
    Compressible out;
    out[0] = w[0] * u[0];
    out[1] = w[1] * u[1];
    out[2] = w[2] * u[2];
    out[3] = w[3] * u[3];
    out[4] = w[4] * u[4];
    return out;
}

#endif // COMPRESSIBLE_H