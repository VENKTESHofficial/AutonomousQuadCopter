#ifndef SYSTEMEVENTLOG_H
#define SYSTEMEVENTLOG_H
#include <stdint.h>
#include <string.h>
#include "BaseModule.h"
class SystemEventLog : public BaseModule{
public:
    SystemEventLog();
    SystemEventLog(char* log_file_name, BaseModule* module_dependencies);
    SystemEventLog(const SystemEventLog& orig);
    virtual ~SystemEventLog();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
private:
    
    void WriteMsg(char* msg);
    
    char* log_file_name_;
    int32_t file_descriptor_;
    char* last_msg_;
};

#endif /* SYSTEMEVENTLOG_H */

