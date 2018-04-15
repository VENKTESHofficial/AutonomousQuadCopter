#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// MotorDriver class
// Drives electric speed controller, that belongs to electric motor
// Uses PWM method(conversion is defined)
class MotorDriver : public BaseModule{
public:
    MotorDriver();
    MotorDriver(const MotorDriver& orig);
    virtual ~MotorDriver();
private:

};

#endif /* MOTORDRIVER_H */

