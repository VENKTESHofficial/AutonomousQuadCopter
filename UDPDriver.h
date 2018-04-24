#ifndef UDPDRIVER_H
#define UDPDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// UDPDriver class
// Inherited from CommunicationDriver
// Specializes the UDP communication process
class UDPDriver : public BaseModule{
public:
    UDPDriver();
    UDPDriver(const UDPDriver& orig);
    virtual ~UDPDriver();
    
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

#endif /* UDPDRIVER_H */

