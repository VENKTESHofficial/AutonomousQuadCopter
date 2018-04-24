#ifndef SYSTEMEVENTLOG_H
#define SYSTEMEVENTLOG_H
#include <stdint.h>
#include "BaseModule.h"
class SystemEventLog : public BaseModule{
public:
    SystemEventLog();
    SystemEventLog(char* log_file_name);
    SystemEventLog(const SystemEventLog& orig);
    virtual ~SystemEventLog();
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedBack();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
private:
    char* log_file_name_;
};

#endif /* SYSTEMEVENTLOG_H */

