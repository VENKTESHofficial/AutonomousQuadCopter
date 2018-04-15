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
private:

};

#endif /* BATTERYMANAGER_H */

