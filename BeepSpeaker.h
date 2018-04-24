#ifndef BEEPSPEAKER_H
#define BEEPSPEAKER_H
#include <stdint.h>
#include "BaseModule.h"
// BeepSpeaker class
// audio feedback for vehicle operation status
class BeepSpeaker : public BaseModule{
public:
    BeepSpeaker();
    BeepSpeaker(uint8_t port);
    BeepSpeaker(const BeepSpeaker& orig);
    virtual ~BeepSpeaker();
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedBack();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
private:
    uint8_t port_;
};

#endif /* BEEPSPEAKER_H */

