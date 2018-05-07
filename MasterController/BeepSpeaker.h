#ifndef BEEPSPEAKER_H
#define BEEPSPEAKER_H
#include <stdint.h>
#include <string.h>
#include "BaseModule.h"
#include "DriverBase.h"
// BeepSpeaker class
// audio feedback for vehicle operation status
class BeepSpeaker : public BaseModule, DriverBase{
public:
    BeepSpeaker();
    BeepSpeaker(uint8_t port, BaseModule** module_dependencies);
    BeepSpeaker(const BeepSpeaker& orig);
    virtual ~BeepSpeaker();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    bool InitComponent();
private:
    uint8_t port_;
    char** status_sound_patterns_;
};

#endif /* BEEPSPEAKER_H */

