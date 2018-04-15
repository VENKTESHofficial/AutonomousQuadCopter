#ifndef BEEPSPEAKER_H
#define BEEPSPEAKER_H
#include "BaseModule.h"
// BeepSpeaker class
// audio feedback for vehicle operation status
class BeepSpeaker : public BaseModule{
public:
    BeepSpeaker();
    BeepSpeaker(const BeepSpeaker& orig);
    virtual ~BeepSpeaker();
private:

};

#endif /* BEEPSPEAKER_H */

