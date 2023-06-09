#ifndef PRESSURETEMPERATUREINLET_HPP
#define PRESSURETEMPERATUREINLET_HPP

#include "BoundaryCondition.hpp"

class PressureTemperatureInlet : public BoundaryCondition
{
    public:

        PressureTemperatureInlet() {}
        PressureTemperatureInlet(Boundary meshBoundary, double totalPressure_, double totaltemperature_, Vars<3> velocityDirection_) : BoundaryCondition(meshBoundary),
                    totalPressure(totalPressure_),
                    totalTemperature(totaltemperature_),
                    velocityDirection(velocityDirection_) {}

        void setTotalPressure(double totalPressure_);
        void setTotalTemperature(double totaltemperature_);
        void setVelocityDirection(Vars<3> velocityDirection_);
        double getTotalPressure() const;
        double getTotalTemperature() const;
        Vars<3> getVelocityDirection() const;

        Compressible calculateState(const Compressible& wl, const Face& f) const;
        

    private:
        double totalPressure;
        double totalTemperature;
        Vars<3> velocityDirection;
};

#endif // PRESSURETEMPERATUREINLET