#ifndef TCPDRIVER_H
#define TCPDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
// TCPDriver class
// Inherited from CommunicationDriver
// Specializes the TCP communication process
class TCPDriver : public CommunicationDriver, DriverBase{
public:
    TCPDriver();
    TCPDriver(char* comm_address, uint8_t comm_port, long comm_timeout,
        uint8_t comm_est_limit, BaseModule** module_dependencies);
    TCPDriver(const TCPDriver& orig);
    virtual ~TCPDriver();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    bool InitComponent();
    
    uint8_t SendRemoteData();
    uint8_t GetRemoteData();
private:
    char* comm_address_;
    uint8_t comm_port_;
};

#endif /* TCPDRIVER_H */

