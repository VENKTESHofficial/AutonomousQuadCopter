#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdint.h>
#include "BaseModule.h"
// Vehicle class
// Executes the main task layer(user-defined tasks)
// at coop case, distributed path development operation
class Vehicle : public BaseModule{
public:
    Vehicle();
    Vehicle(const Vehicle& orig);
    virtual ~Vehicle();
    uint8_t ExecuteTasks();
    uint8_t InitDevs();
private:
    // hardware communication pin layout
    
    uint8_t voltage_meter_0_;
    uint8_t voltage_meter_1_;
    uint8_t voltage_meter_2_;
    uint8_t motor_ESC_0_;
    uint8_t motor_ESC_1_;
    uint8_t motor_ESC_2_;
    uint8_t motor_ESC_3_;
    uint8_t central_IMU_sensor_;
    uint8_t env_temp_hum_sensor_;
    uint8_t distance_sensor_0_;
    uint8_t distance_sensor_1_;
    uint8_t distance_sensor_2_;
    uint8_t distance_sensor_3_;
    
    // vehicle components
    SerialDriver* sensor_controller_comm_;
    SerialDriver* actuator_controller_comm_;
    BatteryManager* battery_0_manager_;
    MotorDriver** motor_drivers_;
    InertialMeasurementUnit* central_IMU_sensor_;
    EnvironmentalSensor* env_temp_hum_sensor_;
    DistanceSensor** distance_sensors_;
    
    AreaModel* metric_point_area_model_;
    //AreaModel* thermal_point_are_model_;
    TCPDriver* metric_point_area_comm_;
    //TCPDriver* thermal_point_area_comm_;
    
    TrajectoryPlanner* trajectory_planner_;
    TCPDriver* user_realtime_control_comm_;
    
    
    BeepSpeaker* status_beep_speaker_;
    
    
    
    
    uint8_t vehicle_id_;
    uint8_t vehicle_right_;
    
    
    
    // timing control and operation synchronization
    long elapsed_operation_time_;
    
    
    // task section
    Command** operation_tasks_;
    
    // error management
    
    
    // supervisory system
    uint8_t num_of_crashes_;
    
    
    // global(point-represented) vehicle attributes
    Vector* axial_position_;
    Vector* angular_position_;
    Vector* axial_speed_;
    Vector* angular_speed_;
    Vector* axial_acceleration_;
    Vector* angular_acceleration_;
    double circumference_speed_;
    double circumference_acceleration_;
    
     
};

#endif /* VEHICLE_H */

