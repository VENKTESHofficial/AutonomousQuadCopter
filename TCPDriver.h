#ifndef TCPDRIVER_H
#define TCPDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// TCPDriver class
// Inherited from CommunicationDriver
// Specializes the TCP communication process
class TCPDriver : public BaseModule{
public:
    TCPDriver();
    TCPDriver(const TCPDriver& orig);
    virtual ~TCPDriver();
    
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

#endif /* TCPDRIVER_H */

