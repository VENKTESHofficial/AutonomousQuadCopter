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
private:

};

#endif /* UDPDRIVER_H */

