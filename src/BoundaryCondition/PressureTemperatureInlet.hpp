#ifndef PRESSURETEMPERATUREINLET_H
#define PRESSURETEMPERATUREINLET_H

#include "BoundaryCondition.hpp"

class PressureTemperatureInlet : public BoundaryCondition
{
    public:

        PressureTemperatureInlet() {}
        PressureTemperatureInlet(Boundary meshBoundary) : BoundaryCondition(meshBoundary) {}

        void setTotalPressure(double totalPressure_);
        void setTotalTemperature(double totaltemperature_);
        double getTotalPressure() const;
        double getTotalTemperature() const;

        Compressible calculateState(const Compressible& wl, const Face& f) const;
        

    private:
        double totalPressure;
        double totalTemperature;
        double angle1 = 0;
        double angle2 = 0;
};

#endif // PRESSURETEMPERATUREINLET