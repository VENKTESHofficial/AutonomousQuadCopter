#ifndef INERTIALMEASUREMENTUNIT_H
#define INERTIALMEASUREMENTUNIT_H
#include <stdint.h>
#include "BaseModule.h"
// IntertialMeasurementUnit class
// IMU sensor driver unit
// Manages axial accelerations and angular accelerations
// Updates position, speed, acceleration vectors
class InertialMeasurementUnit : public BaseModule{
public:
    InertialMeasurementUnit();
    InertialMeasurementUnit(const InertialMeasurementUnit& orig);
    virtual ~InertialMeasurementUnit();
private:

};

#endif /* INERTIALMEASUREMENTUNIT_H */

