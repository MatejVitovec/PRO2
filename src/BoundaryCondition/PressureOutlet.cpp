#include "PressureOutlet.hpp"


void PressureOutlet::setPressure(double pressure_)
{
    pressure = pressure_;
}

double PressureOutlet::getPressure() const
{
    return pressure;
}

Compressible PressureOutlet::calculateState(const Compressible& wl, const Face& f) const
{
    //TODO

    return Compressible();
}