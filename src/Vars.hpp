#ifndef VARS_H
#define VARS_H

#include <vector>
#include <memory>

class Vars
{
    public:
        Vars() {}

        Vars(const std::array<double, 5>& in) : data(in) {}

        virtual ~Vars() {}

        const double& operator[](int i) const
        {
            return data[i];
        }

        double& operator[] (int i)
        {
            return data[i];
        }

        void operator+=(const Vars& v);
        void operator-=(const Vars& v);
        
    protected:
        std::array<double, 5> data;
};

// u + v
inline Vars operator+ (const Vars& u, const Vars& v)
{
    return Vars({u[0] + v[0], u[1] + v[1], u[2] + v[2], u[3] + v[3], u[4] + v[4]});
}

// u - v
inline Vars operator- (const Vars& u, const Vars& v)
{
    return Vars({u[0] - v[0], u[1] - v[1], u[2] - v[2], u[3] - v[3], u[4] - v[4]});
}

// w * u
inline Vars operator* (const Vars& u, const Vars& v)
{
    return Vars({u[0] * v[0], u[1] * v[1], u[2] * v[2], u[3] * v[3], u[4] * v[4]});
}

// a * u
inline Vars operator* (const double& a, const Vars& u)
{
    return Vars({a*u[0], a*u[1], a*u[2], a*u[3], a*u[4]});
}

// u / a
inline Vars operator/ (const Vars& u, const double& a)
{
    return Vars({u[0]/a, u[1]/a, u[2]/a, u[3]/a, u[4]/a});
}


#endif // VARS_H