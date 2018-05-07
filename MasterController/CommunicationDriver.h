#ifndef COMMUNICATIONDRIVER_H
#define COMMUNICATIONDRIVER_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "BaseModule.h"
#include "DriverBase.h"
// CommunicationDriver class
// General communication manager
class CommunicationDriver : public BaseModule, DriverBase{
public:
    CommunicationDriver();
    CommunictaionDriver(uint8_t comm_port, long comm_timeout,
        uint8_t comm_est_limit, BaseModule** module_dependencies);
    CommunicationDriver(char* comm_address, uint8_t comm_port, long comm_timeout,
        uint8_t comm_est_limit, BaseModule** module_dependencies);
    CommunicationDriver(const CommunicationDriver& orig);
    virtual ~CommunicationDriver();
    virtual uint8_t SendRemoteData();
    virtual uint8_t GetRemoteData();
    
    bool InitComponent();
private:
    long comm_timeout_;
    uint8_t comm_est_limit_;
};

#endif /* COMMUNICATIONDRIVER_H */

