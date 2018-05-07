#include "BaseModule.h"
BaseModule::BaseModule(){
    
}

BaseModule::BaseModule(BaseModule** module_dependencies)
: module_dependencies_(module_dependencies) {
    module_priority_value_ = BaseModule::dynamicPriorityValue;
    ++BaseModule::dynamicPriorityValue;
}

BaseModule::BaseModule(const BaseModule& orig) {
}

BaseModule::~BaseModule() {
}

int8_t BaseModule::GetModuleStatus(){
    return module_status_;
}

uint8_t BaseModule::GetNumOfModuleStatuses(){
    return num_of_module_statuses_;
}

uint8_t BaseModule::GetDynamicPriorityValue(){
    return BaseModule::dynamicPriorityValue;
}

uint8_t BaseModule::GetModulePriorityValue(){
    return module_priority_value_;
}

uint8_t* BaseModule::GetPriorityOrder(){
    return priority_order_;
}

BaseModule** BaseModule::GetModuleDependencies(){
    return module_dependencies_;
}


