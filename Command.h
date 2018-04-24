#ifndef COMMAND_H
#define COMMAND_H
#include <stdint.h>
#include "BaseModule.h"
// Command class
// Contains one multiple layer instruction unit
class Command : public BaseModule{
public:
    Command();
    Command(const Command& orig);
    virtual ~Command();
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedBack();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
    
private:

};

#endif /* COMMAND_H */

