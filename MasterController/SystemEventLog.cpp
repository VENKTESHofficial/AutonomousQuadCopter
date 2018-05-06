#include "SystemEventLog.h"

SystemEventLog::SystemEventLog() : BaseModule() {
    
}

SystemEventLog::SystemEventLog(char* log_file_name, BaseModule* module_dependencies)
: BaseModule(module_dependencies){
    module_status_ = 0;
    
    if(0 != (file_descriptor_ = fopen(log_file_name, "a"))){
        module_status_ = 1;
    }
    
    
    char* msg;
    strcpy(msg, "Event logging has started\n", );
    WriteMsg(msg);
}

SystemEventLog::SystemEventLog(const SystemEventLog& orig) {
}

SystemEventLog::~SystemEventLog() {
}

void SystemEventLog::WriteMsg(char* msg){
    if(0 < fwrite(file_descriptor_, msg, sizeof(msg))){
        module_status_ = 2;
    }
}

uint8_t SystemEventLog::ReceiveData(){
    return 0;
}

void* SystemEventLog::TransmitData(){
    return NULL;
}

template <uint8_t k>
uint8_t SystemEventLog::ReceiveData(){
    return 0;
}

template <uint8_t k = 0>
uint8_t SystemEventLog::ReceiveData(void* param_data){
    WriteMsg(param_data);
    strcpy(last_msg_, (char*)param_data);
    return module_status_;
}

template <uint8_t k = 0>
void* SystemEventLog::TransmitData(){
    return (void*)last_msg_;
}
