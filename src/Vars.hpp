#ifndef VARS_H
#define VARS_H

#include <vector>
#include <memory>
#include <cmath>

class Vars
{
    public:
        Vars() {}

        Vars(const std::array<double, 5>& in) : data(in) {}

        virtual ~Vars() {}

        inline const double& operator[](int i) const
        {
            return data[i];
        }

        inline double& operator[] (int i)
        {
            return data[i];
        }

        void operator+=(const Vars& v);
        void operator-=(const Vars& v);
        
    protected:
        std::array<double, 5> data;
};


//////////////Non member operators///////////////////

// u + v
Vars operator+ (const Vars& u, const Vars& v);

// u - v
Vars operator- (const Vars& u, const Vars& v);

// w * u
Vars operator* (const Vars& u, const Vars& v);

// a * u
Vars operator* (const double& a, const Vars& u);

// u * a
Vars operator* (const Vars& u, const double& a);

// u / a
Vars operator/ (const Vars& u, const double& a);


//////////////Non member function///////////////////

Vars sqrt(const Vars& u);

#endif // VARS_H