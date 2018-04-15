#ifndef SYSTEMEVENTLOG_H
#define SYSTEMEVENTLOG_H
#include <stdint.h>
#include "BaseModule.h"
class SystemEventLog : public BaseModule{
public:
    SystemEventLog();
    SystemEventLog(const SystemEventLog& orig);
    virtual ~SystemEventLog();
private:

};

#endif /* SYSTEMEVENTLOG_H */

