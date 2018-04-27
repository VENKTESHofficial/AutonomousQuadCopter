#ifndef BASEMODULE_H
#define BASEMODULE_H
#include <stdint.h>
#include <stdio.h>
#include "Vector.h"
// BaseModule class
// Defines the interfaces and basic members of the module classes
//
//
// Interface components
//  ReceiveData()
//      outer data request function, called from the destination(subject class)
//  TrasmitData()
//      outer command for transmission to third target class
//  GetFeedback()
//  SendFeedback()
//

class BaseModule {
public:
    BaseModule();
    BaseModule(BaseModule** module_dependencies);
    BaseModule(char* log_file_name);
    BaseModule(const BaseModule& orig);
    virtual ~BaseModule();
    // Class interface
    // data transaction function
    virtual void* ReceiveData() = 0;
    virtual uint8_t TransmitData() = 0;
    template <uint8_t k>
    virtual void* ReceiveData() = 0;
    template <uint8_t k>
    virtual uint8_t TransmitData(void* param_data) = 0;
    
    // feedback transaction functions
    virtual int8_t GetFeedback() = 0;
    virtual int8_t SendFeedback() = 0;
    template <uint8_t k>
    virtual int8_t GetFeedback() = 0;
    template <uint8_t k>
    virtual int8_t SendFeedback(void* param_data) = 0;
    
    Vector<(int8_t)(*)()> rest_routine_list_;
    
protected:
    // error management
    int8_t module_status_;
    uint8_t num_of_module_statuses_;
    
    // thread management
    // module-level lock/critical section management
    // deterministic method
    // using priority queues, module prior vals are defined
    // by user written declaration sequence
    // at simultaneous bidirectional critical section state, evaluate according
    // to prior vals
    
    static uint8_t dynamicPriorityValue = 0;
    uint8_t module_priority_value_;
    //bool module_priority_value_has_set_;
    uint8_t* priority_order_;
    BaseModule** module_dependencies_;
private:
    
    
};

#endif /* BASEMODULE_H */

