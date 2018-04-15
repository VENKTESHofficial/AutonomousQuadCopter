#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
// SerialDriver class
// Inherited from CommunicationDriver
// Specializes the operation process of serial communication
class SerialDriver : public BaseModule{
public:
    SerialDriver();
    SerialDriver(const SerialDriver& orig);
    virtual ~SerialDriver();
private:

};

#endif /* SERIALDRIVER_H */

