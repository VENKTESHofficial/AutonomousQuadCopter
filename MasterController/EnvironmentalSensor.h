#ifndef ENVIRONMENTALSENSOR_H
#define ENVIRONMENTALSENSOR_H
#include <stdint.h>
#include "BaseModule.h"
// EnvironmentalSensor class
// Temperature, pressure, humidity, hygrometer sensor manager
class EnvironmentalSensor : public BaseModule{
public:
    EnvironmentalSensor();
    EnvironmentalSensor(BaseModule** module_dependencies);
    EnvironmentalSensor(const EnvironmentalSensor& orig);
    virtual ~EnvironmentalSensor();
    
    
    void* ReceiveData();
    uint8_t TransmitData();
    template <uint8_t k>
    void* ReceiveData();
    template <uint8_t k>
    uint8_t TransmitData(void* param_data);
    
    uint8_t GetFeedback();
    uint8_t SendFeedback();
    template <uint8_t k>
    uint8_t GetFeedback();
    template <uint8_t k>
    uint8_t SendFeedback(void* param_data);
private:

};

#endif /* ENVIRONMENTALSENSOR_H */

