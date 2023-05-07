#include "PressureTemperatureInlet.hpp"


void PressureTemperatureInlet::setTotalPressure(double totalPressure_)
{
    totalPressure = totalPressure_;
}

void PressureTemperatureInlet::setTotalTemperature(double totaltemperature_)
{
    totalTemperature = totaltemperature_;
}

void PressureTemperatureInlet::setVelocityDirection(Vars<3> velocityDirection_)
{
    velocityDirection = velocityDirection_;
}

double PressureTemperatureInlet::getTotalPressure() const
{
    return totalPressure;
}

double PressureTemperatureInlet::getTotalTemperature() const
{
    return totalTemperature;
}

Vars<3> PressureTemperatureInlet::getVelocityDirection() const
{
    return velocityDirection;
}

Compressible PressureTemperatureInlet::calculateState(const Compressible& wl, const Face& f) const
{
    return Compressible::getEquationOfState()->nonLinearSubsonicInletBoundaryState(wl, vector3toVars(f.normalVector), totalPressure, totalTemperature, velocityDirection);
}