#ifndef TCPDRIVER_H
#define TCPDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// TCPDriver class
// Inherited from CommunicationDriver
// Specializes the TCP communication process
class TCPDriver : public CommunicationDriver{
public:
    TCPDriver();
    TCPDriver(char* comm_address, uint8_t comm_port, long comm_timeout,
        uint8_t comm_est_limit, BaseModule** module_dependencies);
    TCPDriver(const TCPDriver& orig);
    virtual ~TCPDriver();
    
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
    char* comm_address_;
    uint8_t comm_port_;
};

#endif /* TCPDRIVER_H */

