#ifndef COMMAND_H
#define COMMAND_H
#include <stdint.h>
#include "BaseModule.h"
// Command class
// Contains one multiple layer instruction unit
class Command : public BaseModule{
public:
    Command();
    Command(const Command& orig);
    virtual ~Command();
private:

};

#endif /* COMMAND_H */

