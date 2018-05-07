#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
#include <string.h>
#include "wiringSerial.h"
// SerialDriver class
// Inherited from CommunicationDriver
// Specializes the operation process of serial communication
class SerialDriver : public CommunicationDriver, DriverBase{
public:
    SerialDriver();
    SerialDriver(char* comm_port, long comm_timeout, uint8_t comm_est_limit,
        BaseModule** module_dependencies);
    SerialDriver(const SerialDriver& orig);
    virtual ~SerialDriver();
    
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
    uint8_t comm_port_;
    int file_descriptor_;
};

#endif /* SERIALDRIVER_H */

