#include <cmath>

#include "Compressible.hpp"

void Compressible::setEquationOfState(std::shared_ptr<EquationOfState> eqs_)
{
    eqs = eqs_;
}


double Compressible::density() const
{
    return data[RHO];
}

Vars<3> Compressible::velocity() const
{
    return Vars<3>({data[RHO_U] / data[RHO], data[RHO_V] / data[RHO], data[RHO_W] / data[RHO]});
}

Vars<3> Compressible::velocity(const Vars<3>& normalvector) const
{
    return Vars<3>();
}

double Compressible::absVelocity() const
{
    return sqrt(data[RHO_U]*data[RHO_U] + data[RHO_V]*data[RHO_V] + data[RHO_W]*data[RHO_W]) / data[RHO];
}

double Compressible::velocityU() const
{
    return data[RHO_U] / data[RHO];
}

double Compressible::velocityV() const
{
    return data[RHO_V] / data[RHO];
}

double Compressible::velocityW() const
{
    return data[RHO_W] / data[RHO];
}

double Compressible::totalEnergy() const
{
    return data[RHO_E] / data[RHO];
}

double Compressible::pressure() const
{
    return eqs->pressure(*this);
}

double Compressible::internalEnergy() const
{
    return eqs->internalEnergy(*this);
}

double Compressible::soundSpeed() const
{
    return eqs->soundSpeed(*this);
}

Vars<5> Compressible::flux(const Vars<3>& normalVector) const
{
    double density = this->density();
    Vars<3> velocity = this->velocity();
    double pressure = this->pressure();
    double enthalpy = this->totalEnergy() + pressure/density;

    double normalVelocity = dot(velocity, normalVector);

    //mozna to takto nejde

    return Compressible({density * normalVelocity,
                    density * velocity[0] * normalVelocity + pressure * normalVector[0],
                    density * velocity[1] * normalVelocity + pressure * normalVector[1],
                    density * velocity[2] * normalVelocity + pressure * normalVector[2],
                    density * enthalpy * normalVelocity});
}

Vars<5> Compressible::primitive() const
{
    //TODO
    return Vars<5>();
}

void Compressible::operator+=(const Compressible& v)
{
    data[0] += v[0];
    data[1] += v[1];
    data[2] += v[2];
    data[3] += v[3];
    data[4] += v[4];
}

void Compressible::operator-=(const Compressible& v)
{
    data[0] -= v[0];
    data[1] -= v[1];
    data[2] -= v[2];
    data[3] -= v[3];
    data[4] -= v[4];
}

void Compressible::operator+=(const Vars<5>& v)
{
    data[0] += v[0];
    data[1] += v[1];
    data[2] += v[2];
    data[3] += v[3];
    data[4] += v[4];
}

void Compressible::operator-=(const Vars<5>& v)
{
    data[0] -= v[0];
    data[1] -= v[1];
    data[2] -= v[2];
    data[3] -= v[3];
    data[4] -= v[4];
}


//////////////Non member operators///////////////////


// u + v
Compressible operator+ (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
Compressible operator- (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
Compressible operator* (const Compressible& u, const Compressible& v)
{
    return Compressible({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

// a * u
Compressible operator* (const double& a, const Compressible& u)
{
    return Compressible({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u * a
Compressible operator* (const Compressible& u, const double& a)
{
    return Compressible({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u / a
Compressible operator/ (const Compressible& u, const double& a)
{
    return Compressible({u[0]/a, u[1]/a, u[2]/a, u[3]/a, u[4]/a});
}

// Compressible, Vars<5>

// u + v
Compressible operator+ (const Compressible& u, const Vars<5>& v)
{
    return Compressible({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
Compressible operator- (const Compressible& u, const Vars<5>& v)
{
    return Compressible({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
Compressible operator* (const Compressible& u, const Vars<5>& v)
{
    return Compressible({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}


//////////////Non member function///////////////////

Compressible sqrt(const Compressible& u)
{
    return Compressible({std::sqrt(u[0]), std::sqrt(u[1]), std::sqrt(u[2]), std::sqrt(u[3]), std::sqrt(u[4])});
}