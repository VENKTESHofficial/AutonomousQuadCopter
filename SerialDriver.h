#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// SerialDriver class
// Inherited from CommunicationDriver
// Specializes the operation process of serial communication
class SerialDriver : public CommunicationDriver{
public:
    SerialDriver();
    SerialDriver(char* comm_port, long comm_timeout, uint8_t comm_est_limit,
        BaseModule** module_dependencies);
    SerialDriver(const SerialDriver& orig);
    virtual ~SerialDriver();
    
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
    
    uint8_t SendRemoteData();
    uint8_t GetRemoteData();
private:
    uint8_t comm_port_;
};

#endif /* SERIALDRIVER_H */

