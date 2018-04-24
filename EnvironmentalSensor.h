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
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedBack();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
private:

};

#endif /* ENVIRONMENTALSENSOR_H */

