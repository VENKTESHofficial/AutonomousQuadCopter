#ifndef AREAMODEL_H
#define AREAMODEL_H
#include<stdint.h>
#include "BaseModule.h"
// AreaModel class
// Environmental mapping result and methods, transformations for the result set
template <class T>
class AreaModel : public BaseModule{
public:
    AreaModel();
    AreaModel(const AreaModel& orig);
    virtual ~AreaModel();
    
    void* ReceiveData();
    uint8_t TransmitData();
    void* ReceiveData(uint8_t data_id);
    uint8_t TransmitData(uint8_t data_id);
    
    uint8_t GetFeedback();
    uint8_t SendFeedback();
    uint8_t GetFeedback(uint8_t data_id);
    uint8_t SendFeedback(uint8_t data_id);
    
private:
    static double diagonal_of_copter_;
    //
    uint64_t subarea_usage_threshold_;
    

    T** data_storage_;
};

#endif /* AREAMODEL_H */

