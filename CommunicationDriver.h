#ifndef COMMUNICATIONDRIVER_H
#define COMMUNICATIONDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// CommunicationDriver class
// General communication manager
class CommunicationDriver : public BaseModule{
public:
    CommunicationDriver();
    CommunicationDriver(const CommunicationDriver& orig);
    virtual ~CommunicationDriver();
    
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

#endif /* COMMUNICATIONDRIVER_H */

