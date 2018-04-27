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
    
    void WriteMsg(char* msg);
private:
    char* log_file_name_;
    int32_t file_descriptor_;
    char* last_msg_;
};

#endif /* SYSTEMEVENTLOG_H */

