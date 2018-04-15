#ifndef INERTIALMEASUREMENTUNIT_H
#define INERTIALMEASUREMENTUNIT_H

// IntertialMeasurementUnit class
// IMU sensor driver unit
// Manages axial accelerations and angular accelerations
// Updates position, speed, acceleration vectors
class InertialMeasurementUnit {
public:
    InertialMeasurementUnit();
    InertialMeasurementUnit(const InertialMeasurementUnit& orig);
    virtual ~InertialMeasurementUnit();
private:

};

#endif /* INERTIALMEASUREMENTUNIT_H */

