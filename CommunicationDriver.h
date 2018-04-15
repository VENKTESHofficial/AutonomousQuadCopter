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
private:

};

#endif /* COMMUNICATIONDRIVER_H */

