#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

class Vars
{
    public:
        Vars() : data(0) {}
        Vars(int data_) : data(data_) {}

    
        int data;

    protected:

};

class Compressible : public Vars
{
    public:
        Compressible() : Vars(0) {}
        Compressible(int data_) : Vars(data_) {}

};

Vars operator+ (const Vars& u, const Vars& v)
{
    return u.data + v.data;
}

double funkce(const Vars& u, const Vars& v)
{
    return 0.5;
}

int main(int argc, char** argv)
{
    Compressible a(6);
    Compressible b(8);

    double aaa = a + b;

    return 0;
}