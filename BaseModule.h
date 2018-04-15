#ifndef BASEMODULE_H
#define BASEMODULE_H
#include<stdint.h>
// BaseModule class
// Defines the interfaces and basic members of the module classes
class BaseModule {
public:
    BaseModule();
    BaseModule(const BaseModule& orig);
    virtual ~BaseModule();
private:

};

#endif /* BASEMODULE_H */

