#ifndef BEEPSPEAKER_H
#define BEEPSPEAKER_H
#include <stdint.h>
#include <string.h>
#include "BaseModule.h"
// BeepSpeaker class
// audio feedback for vehicle operation status
class BeepSpeaker : public BaseModule{
public:
    BeepSpeaker();
    BeepSpeaker(uint8_t port, BaseModule** module_dependencies);
    BeepSpeaker(const BeepSpeaker& orig);
    virtual ~BeepSpeaker();
    
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
private:
    uint8_t port_;
    char** status_sound_patterns_;
};

#endif /* BEEPSPEAKER_H */

