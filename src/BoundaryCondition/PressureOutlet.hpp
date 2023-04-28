#ifndef PRESSUREOUTLET_H
#define PRESSUREOUTLET_H

#include "BoundaryCondition.hpp"

class PressureOutlet : public BoundaryCondition
{
    public:

        PressureOutlet() {}
        PressureOutlet(Boundary meshBoundary) : BoundaryCondition(meshBoundary) {}

        void setPressure(double pressure_);
        double getPressure() const;

        Compressible calculateState(const Compressible& wl, const Face& f) const;
        

    private:
        double pressure;
};

#endif // PRESSUREOUTLET