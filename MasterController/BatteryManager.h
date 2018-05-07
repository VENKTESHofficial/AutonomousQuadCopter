#ifndef BATTERYMANAGER_H
#define BATTERYMANAGER_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
// Active sensor
// BatteryManager class
// Battery monitoring and operation availability calculations
class BatteryManager : public BaseModule, DriverBase{
public:
    BatteryManager();
    
    BatteryManager(const BatteryManager& orig);
    virtual ~BatteryManager();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    bool InitComponent();
    
    bool SignalConditioner();// Converting incoming raw data to nominal form
private:
    uint64_t raw_value_;
    double converted_value_;
    double lower_value_bound_;
    double upper_value_bound_;
    
};

#endif /* BATTERYMANAGER_H */

