#ifndef VARS_H
#define VARS_H

#include <vector>
#include <memory>
#include <cmath>
#include "Mesh/Vector3.hpp"


template <int N>
class Vars
{
    public:
        Vars() {}

        Vars(const std::array<double, N>& in) : data(in) {}

        virtual ~Vars() {}

        inline const double& operator[](int i) const
        {
            return data[i];
        }

        inline double& operator[] (int i)
        {
            return data[i];
        }

        void operator+=(const Vars<N>& v);
        void operator-=(const Vars<N>& v);
        
    protected:
        std::array<double, N> data;
};

template <int N>
void Vars<N>::operator+= (const Vars<N>& v)
{
    data[0] += v[0];
    data[1] += v[1];
    data[2] += v[2];
    data[3] += v[3];
    data[4] += v[4];
}

template <int N>
void Vars<N>::operator-= (const Vars<N>& v)
{
    data[0] -= v[0];
    data[1] -= v[1];
    data[2] -= v[2];
    data[3] -= v[3];
    data[4] -= v[4];
}

//////////////Non member operators///////////////////

template <int N>
Vars<N> operator+ (const Vars<N>& u, const Vars<N>& v)
{
    return Vars<N>({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
template <int N>
Vars<N> operator- (const Vars<N>& u, const Vars<N>& v)
{
    return Vars<N>({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
template <int N>
Vars<N> operator* (const Vars<N>& u, const Vars<N>& v)
{
    return Vars<N>({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

// a * u
template <int N>
Vars<N> operator* (const double& a, const Vars<N>& u)
{
    return Vars<N>({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u * a
template <int N>
Vars<N> operator* (const Vars<N>& u, const double& a)
{
    return Vars<N>({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u / a
template <int N>
Vars<N> operator/ (const Vars<N>& u, const double& a)
{
    return Vars<N>({u[0]/a, u[1]/a, u[2]/a, u[3]/a, u[4]/a});
}


//////////////Non member function///////////////////

template <int N>
Vars<N> sqrt(const Vars<N>& u)
{
    return Vars<N>({sqrt(u[0]), sqrt(u[1]), sqrt(u[2]), sqrt(u[3]), sqrt(u[4])});
}

template <int N>
double dot(const Vars<N>& u, const Vars<N>& v)
{
    return u[0]*v[0] + u[1]*v[1] + u[2]*v[2] + u[3]*v[3] + u[4]*v[4];
}

template <int N>
Vars<N> cross(const Vars<N>& u, const Vars<N>& v)
{
    //TODO
    return Vars();
}

/*Vars Vector3toVars(const Vector3& vec)
{
    return Vars({})
}*/


#endif // VARS_H