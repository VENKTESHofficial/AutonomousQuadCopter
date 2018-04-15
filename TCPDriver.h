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
private:

};

#endif /* TCPDRIVER_H */

