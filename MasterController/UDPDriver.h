#ifndef UDPDRIVER_H
#define UDPDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
// UDPDriver class
// Inherited from CommunicationDriver
// Specializes the UDP communication process
class UDPDriver : public CommunicationDriver, DriverBase{
public:
    UDPDriver();
    UDPDriver(char* comm_address, uint8_t comm_port, long comm_timeout,
        uint8_t comm_est_limit, BaseModule** module_dependencies);
    UDPDriver(const UDPDriver& orig);
    virtual ~UDPDriver();
    
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

#endif /* UDPDRIVER_H */

