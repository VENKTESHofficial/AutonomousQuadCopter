#ifndef INERTIALMEASUREMENTUNIT_H
#define INERTIALMEASUREMENTUNIT_H
#include <stdint.h>
#include "BaseModule.h"
// IntertialMeasurementUnit class
// IMU sensor driver unit
// Manages axial accelerations and angular accelerations
// Updates position, speed, acceleration vectors
class InertialMeasurementUnit : public BaseModule{
public:
    InertialMeasurementUnit();
    InertialMeasurementUnit(const InertialMeasurementUnit& orig);
    virtual ~InertialMeasurementUnit();
    
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
    uint8_t* imu_comm_pins_;
    double offset_sensor_displacement_x_;
    double offset_sensor_displacement_y_;
    double offset_sensor_displacement_z_;
    double gravity_;
    
    double lower_x_axial_accel_bound_;
    double upper_x_axial_accel_bounds_;
    double lower_y_axial_accel_bound_;
    double upper_y_axial_accel_bound_;
    double lower_z_axial_accel_bound_;
    double upper_z_axial_accel_bound_;
    
    double lower_pitch_angular_accel_bound_;
    double upper_pitch_angular_accel_bound_;
    double lower_roll_angular_accel_bound_;
    double upper_roll_angular_accel_bound_;
    double lower_yaw_angular_accel_bound_;
    double upper_yaw_angular_accel_bounds_;
    
    uint64_t imu_diff_threshold_;
    
    
    
};

#endif /* INERTIALMEASUREMENTUNIT_H */

