#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// SerialDriver class
// Inherited from CommunicationDriver
// Specializes the operation process of serial communication
class SerialDriver : public BaseModule{
public:
    SerialDriver();
    SerialDriver(char* port);
    SerialDriver(const SerialDriver& orig);
    
    virtual ~SerialDriver();
    
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedBack();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
private:
    char* port_;
};

#endif /* SERIALDRIVER_H */

