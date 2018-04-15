#ifndef AREAMODEL_H
#define AREAMODEL_H
#include<stdint.h>
#include "BaseModule.h"
// AreaModel class
// Environmental mapping result and methods, transformations for the result set
class AreaModel : public BaseModule{
public:
    AreaModel();
    AreaModel(const AreaModel& orig);
    virtual ~AreaModel();
private:

};

#endif /* AREAMODEL_H */

