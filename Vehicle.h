#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "BaseModule.h"
#include "SystemEventLog.h"
#include "BeepSpeaker.h"
#include "SerialDriver.h"
#include "BatteryManager.h"
#include "MotorDriver.h"
#include "InertialMeasurementUnit.h"
#include "EnvironmentalSensor.h"
#include "DistanceSensor.h"
#include "AreaModel.h"
#include "TCPDriver.h"
#include "TrajectoryPlanner.h"
#include <pthread.h>
// Vehicle class
// Executes the main task layer(user-defined tasks)
// at coop case, distributed path development operation
class Vehicle : public BaseModule{
public:
    Vehicle();
    Vehicle(const Vehicle& orig);
    virtual ~Vehicle();
    
    int8_t ExecuteTasks();
    int8_t InitVehicle();
    
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
    
    
    int8_t setCurrentErrorStatus(int8_t error_id);
    
    
private:
    // hardware communication pin layout
    
    char* log_file_name_;
    uint8_t beep_speaker_port_;
    char* sensor_controller_comm_port_;
    char* actuator_controller_comm_port_;
    uint8_t battery_cell_number_;
    double battery_capacity_;
    double battery_discharge_rate_;
    double battery_full_lvl_;
    double battery_warning_lvl_;
    double battery_critical_lvl_;
    uint8_t num_of_motor_drivers_;
    uint8_t* motor_driver_ports_;
    uint8_t* central_IMU_sensor_ports_;
    uint8_t* env_temp_hum_sensor_ports_;
    uint8_t num_of_distance_sensors_;
    uint8_t** distance_sensor_ports_;
    long distance_sensor_sampling_rate_;
    char* metric_point_area_comm_address_;
    uint32_t metric_point_area_comm_port_;
    char* user_realtime_control_comm_address_;
    uint32_t user_realtime_control_comm_port_;
    
    
    std::vector<BaseModule*> error_manager_container_;
    
    // vehicle components
    SystemEventLog* system_log_;
    BeepSpeaker* status_beep_speaker_;
    
    SerialDriver* sensor_controller_comm_;
    SerialDriver* actuator_controller_comm_;
    BatteryManager* battery_0_manager_;
    MotorDriver** motor_drivers_;
    InertialMeasurementUnit* central_IMU_sensor_;
    EnvironmentalSensor* env_temp_hum_sensor_;
    DistanceSensor** distance_sensors_;
    
    AreaModel<Vector>* metric_point_area_model_;
    //AreaModel* thermal_point_are_model_;
    TCPDriver* metric_point_area_comm_;
    //TCPDriver* thermal_point_area_comm_;
    
    TrajectoryPlanner* trajectory_planner_;
    TCPDriver* user_realtime_control_comm_;
    
    uint8_t vehicle_id_;
    uint8_t vehicle_right_;
    TCPDriver** vehicle_group_;
    
    
    // timing control and operation synchronization
    long elapsed_operation_time_;
    
    
    // task section
    Command** operation_tasks_;
    
    
    // error management
    int8_t current_error_status_;
    
    
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

struct VehicleParameter{
    char* log_file_name_;
    
    uint8_t beep_speaker_port_;
    
    char* sensor_controller_comm_port_;
    long sensor_controller_comm_timeout_;
    uint8_t sensor_controller_comm_establishment_attemption_limit_;
    
    char* actuator_controller_comm_port_;
    long actuator_controller_comm_timeout_;
    uint8_t actuator_controller_comm_establishment_attemption_limit_;
    
    uint8_t battery_cell_number_;
    double battery_capacity_;
    double battery_discharge_rate_;
    double battery_full_lvl_;
    double battery_warning_lvl_;
    double battery_critical_lvl_;
    
    uint8_t num_of_motor_drivers_;
    uint8_t* motor_driver_ports_;
    double* pid_controle_section_lower_bounds_;
    double* pid_control_section_upper_bounds_;
    
    uint8_t* central_IMU_sensor_ports_;
    long central_IMU_sensor_samling_rate_;
    Vector<double> central_IMU_sensor_position_offsets_;
    
    uint8_t* env_temp_hum_sensor_ports_;
    long env_temp_hum_sensor_sampling_rate_;
    
    uint8_t num_of_distance_sensors_;
    uint8_t** distance_sensor_ports_;
    long distance_sensor_sampling_rate_;
    Vector<double>* distance_sensor_position_offsets_;
    
    char* metric_point_area_comm_address_;
    uint32_t metric_point_area_comm_port_;
    long metric_point_area_comm_timeout_;
    
    struct TrajectoryParams{
        Vector<double>* external_forces_;
        Vector<double>* internal_forces_;
        bool discretization_sampling_mode_;// time or equidistance-based
        long actuator_time_sampling_rate_;
        uint64_t actuator_dist_sampling_rate_;
        Vector<double> metric_position_upper_bounds_;
        Vector<double> metric_position_lower_bounds_;
        Vector<double> metric_speed_upper_bounds_;
        Vector<double> metric_speed_lower_bounds_;
        Vector<double> metric_accel_upper_bounds_;
        Vector<double> metric_accel_lower_bounds_;
        // positional_trajectory_execution_error_bounds_
        Vector<double>* pos_traj_exec_err_bounds_;// x, y, z
    }trajectory_params_;
    
        
    char* user_realtime_control_comm_address_;
    long user_realtime_control_comm_timeout_;
    uint32_t user_realtime_control_comm_port_;
    uint8_t vehicle_id_;
    uint8_t vehicle_right_;
};

#endif /* VEHICLE_H */

