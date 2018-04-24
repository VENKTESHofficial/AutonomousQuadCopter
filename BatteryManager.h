#ifndef BATTERYMANAGER_H
#define BATTERYMANAGER_H
#include <stdint.h>
#include "BaseModule.h"
// BatteryManager class
// Battery monitoring and operation availability calculations
class BatteryManager : public BaseModule{
public:
    BatteryManager();
    BatteryManager(const BatteryManager& orig);
    virtual ~BatteryManager();
    
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

#endif /* BATTERYMANAGER_H */

