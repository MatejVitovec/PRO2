#include "Vars.hpp"

void Vars::operator+= (const Vars& v)
{
    data[0] += v[0];
    data[1] += v[1];
    data[2] += v[2];
    data[3] += v[3];
    data[4] += v[4];
}

void Vars::operator-= (const Vars& v)
{
    data[0] -= v[0];
    data[1] -= v[1];
    data[2] -= v[2];
    data[3] -= v[3];
    data[4] -= v[4];
}

//////////////Non member operators///////////////////


Vars operator+ (const Vars& u, const Vars& v)
{
    return Vars({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
Vars operator- (const Vars& u, const Vars& v)
{
    return Vars({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
Vars operator* (const Vars& u, const Vars& v)
{
    return Vars({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

// a * u
Vars operator* (const double& a, const Vars& u)
{
    return Vars({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u * a
Vars operator* (const Vars& u, const double& a)
{
    return Vars({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u / a
Vars operator/ (const Vars& u, const double& a)
{
    return Vars({u[0]/a, u[1]/a, u[2]/a, u[3]/a, u[4]/a});
}


//////////////Non member function///////////////////

Vars sqrt(const Vars& u)
{
    return Vars({sqrt(u[0]), sqrt(u[1]), sqrt(u[2]), sqrt(u[3]), sqrt(u[4])});
}