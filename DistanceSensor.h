#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#include <stdint.h>
#include "BaseModule.h"
// DistanceSensor class
// Distance measurement sensor driver class
// Generalized operation(laser, ultrasonic, etc..)
class DistanceSensor : public BaseModule{
public:
    DistanceSensor();
    DistanceSensor(const DistanceSensor& orig);
    virtual ~DistanceSensor();
private:

};

#endif /* DISTANCESENSOR_H */

