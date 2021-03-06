#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#include <stdint.h>
#include "BaseModule.h"
// DistanceSensor class
// Distance measurement sensor driver class
// Generalized operation(laser, ultrasonic, etc..)
class DistanceSensor : public BaseModule{
public:
    DistanceSensor();
    DistanceSensor(const DistanceSensor& orig);
    virtual ~DistanceSensor();
    
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
    uint8_t* distance_sensor_comm_pins_;
    uint64_t absorption_weekness_timout_;
    double lower_pulse_bound_;
    double upper_pulse_bound_;
    uint64_t sampling_rate_;
    uint8_t error_number_threshold_;
    double relative_radar_x_pos_;
    double relative_radar_y_pos_;
    double relative_radar_z_pos_;
    
};

#endif /* DISTANCESENSOR_H */

