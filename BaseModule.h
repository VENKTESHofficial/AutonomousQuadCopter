#ifndef BASEMODULE_H
#define BASEMODULE_H
#include <stdint.h>
#include "Vector.h"
// BaseModule class
// Defines the interfaces and basic members of the module classes
class BaseModule {
public:
    BaseModule();
    BaseModule(const BaseModule& orig);
    virtual ~BaseModule();
    // Class interface
    // data transaction function
    void* ReceiveData() = 0;
    uint8_t TransmitData() = 0;
    void* ReceiveData(uint8_t data_id) = 0;
    uint8_t TransmitData(uint8_t data_id) = 0;
    
    // feedback transaction functions
    int8_t GetFeedback() = 0;
    int8_t SendFeedback() = 0;
    int8_t GetFeedback(uint8_t data_id) = 0;
    int8_t SendFeedback(uint8_t data_id) = 0;
    Vector<(int8_t)(*)()> rest_routine_list_;
    
protected:
    int8_t module_status_;
    uint8_t num_of_module_statuses_;
private:
    
    
};

#endif /* BASEMODULE_H */

