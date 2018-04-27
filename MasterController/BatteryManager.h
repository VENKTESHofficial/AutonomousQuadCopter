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

#endif /* BATTERYMANAGER_H */

