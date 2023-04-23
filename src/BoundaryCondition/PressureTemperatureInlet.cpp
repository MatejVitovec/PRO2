#include "PressureTemperatureInlet.hpp"


void PressureTemperatureInlet::setTotalPressure(double totalPressure_)
{
    totalPressure = totalPressure_;
}

void PressureTemperatureInlet::setTotalTemperature(double totaltemperature_)
{
    totalTemperature = totaltemperature_;
}

double PressureTemperatureInlet::getTotalPressure() const
{
    return totalPressure;
}

double PressureTemperatureInlet::getTotalTemperature() const
{
    return totalTemperature;
}

Compressible PressureTemperatureInlet::calculateState(const Compressible& wl) const
{
    //TODO

    return Compressible();
}