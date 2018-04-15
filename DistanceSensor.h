#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

// DistanceSensor class
// Distance measurement sensor driver class
// Generalized operation(laser, ultrasonic, etc..)
class DistanceSensor {
public:
    DistanceSensor();
    DistanceSensor(const DistanceSensor& orig);
    virtual ~DistanceSensor();
private:

};

#endif /* DISTANCESENSOR_H */

