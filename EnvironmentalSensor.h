#ifndef ENVIRONMENTALSENSOR_H
#define ENVIRONMENTALSENSOR_H
#include <stdint.h>
#include "BaseModule.h"
// EnvironmentalSensor class
// Temperature, pressure, humidity, hygrometer sensor manager
class EnvironmentalSensor : public BaseModule{
public:
    EnvironmentalSensor();
    EnvironmentalSensor(const EnvironmentalSensor& orig);
    virtual ~EnvironmentalSensor();
private:

};

#endif /* ENVIRONMENTALSENSOR_H */

