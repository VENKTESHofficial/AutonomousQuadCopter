#ifndef ENVIRONMENTALSENSOR_H
#define ENVIRONMENTALSENSOR_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
// EnvironmentalSensor class
// Temperature, pressure, humidity, hygrometer sensor manager
class EnvironmentalSensor : public BaseModule, DriverBase{
public:
    EnvironmentalSensor();
    EnvironmentalSensor(BaseModule** module_dependencies);
    EnvironmentalSensor(const EnvironmentalSensor& orig);
    virtual ~EnvironmentalSensor();
    
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    bool InitComponent();
private:

};

#endif /* ENVIRONMENTALSENSOR_H */

