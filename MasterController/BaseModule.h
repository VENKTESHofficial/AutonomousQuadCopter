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

// master-slave role layout
class BaseModule {
public:
    BaseModule();
    BaseModule(BaseModule** module_dependencies);
    BaseModule(char* log_file_name);
    BaseModule(const BaseModule& orig);
    virtual ~BaseModule();
    // Class interface
    // data transaction function
    virtual uint8_t ReceiveData() = 0;
    virtual void* TransmitData() = 0;
    template <uint8_t k>
    virtual uint8_t ReceiveData(void* param_data) = 0;
    template <uint8_t k>
    virtual void* TransmitData() = 0;
        
    int8_t GetModuleStatus();
    uint8_t GetNumOfModuleStatuses();
    static uint8_t GetDynamicPriorityValue();
    uint8_t GetModulePriorityValue();
    uint8_t* GetPriorityOrder();
    BaseModule** GetModuleDependencies();
    
    virtual bool InitComponent();
    
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
    
    // time-based process control
    long* timings_;
    
    // condition-based process control
    CF** conditioning_functors_;
    
    // test routine functions
    Vector<(int8_t)(*)()> test_routine_list_;
    
private:
    
    
};

// Conditioning functor
struct CF{
    virtual bool operator()();
};

// Process conditioning functor
struct PCF : public CF{
    bool operator()();
};

#endif /* BASEMODULE_H */

