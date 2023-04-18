#ifndef VARS_H
#define VARS_H

#include <vector>
#include <memory>

class Vars
{
    public:
        Vars() {};

        Vars(const std::array<double, 5>& in) : data(in) {};

        //virtual ~Vars();

        const double& operator[](int i) const
        {
            return data[i];
        }

        double& operator[] (int i)
        {
            return data[i];
        }

    protected:
        std::array<double, 5> data;
};

// u + v
inline Vars operator+ (const Vars& u, const Vars& v)
{
    Vars out;
    out[0] = u[0] + v[0];
    out[1] = u[1] + v[1];
    out[2] = u[2] + v[2];
    out[3] = u[3] + v[3];
    out[4] = u[4] + v[4];
    return out;
}

// u - v
inline Vars operator- (const Vars& u, const Vars& v)
{
    Vars out;
    out[0] = u[0] - v[0];
    out[1] = u[1] - v[1];
    out[2] = u[2] - v[2];
    out[3] = u[3] - v[3];
    out[4] = u[4] - v[4];
    return out;
}

// a * u
inline Vars operator* (double a, const Vars& u)
{
    Vars out;
    out[0] = a * u[0];
    out[1] = a * u[1];
    out[2] = a * u[2];
    out[3] = a * u[3];
    out[4] = a * u[4];
    return out;
}

// w * u
inline Vars operator* (const Vars& w, const Vars& u)
{
    Vars out;
    out[0] = w[0] * u[0];
    out[1] = w[1] * u[1];
    out[2] = w[2] * u[2];
    out[3] = w[3] * u[3];
    out[4] = w[4] * u[4];
    return out;
}

// u / a
inline Vars operator/ (const Vars& u, double a)
{
    Vars out;
    out[0] = u[0] / a;
    out[1] = u[1] / a;
    out[2] = u[2] / a;
    out[3] = u[3] / a;
    out[4] = u[4] / a;
    return out;
}

#endif // VARS_H