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
private:

};

#endif /* COMMAND_H */

