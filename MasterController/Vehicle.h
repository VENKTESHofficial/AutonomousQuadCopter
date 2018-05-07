#ifndef VEHICLE_H
#define VEHICLE_H
// moving system component attributes
//  to components from vehicle object
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "BaseModule.h"
#include "SystemEventLog.h"
#include "BeepSpeaker.h"
#include "SerialDriver.h"
#include "BatteryManager.h"
#include "ActuatorDriver.h"
#include "InertialMeasurementUnit.h"
#include "EnvironmentalSensor.h"
#include "DistanceSensor.h"
#include "AreaModel.h"
#include "TCPDriver.h"
#include "MechanicalModel.h"
#include <pthread.h>
// Vehicle class
// Executes the main task layer(user-defined tasks)
// at coop case, distributed path development operation
class Vehicle : public BaseModule{
public:
    Vehicle();
    Vehicle(const Vehicle& orig);
    virtual ~Vehicle();
    
    template <uint8_t k>
    int8_t Run();
    int8_t InitVehicle();
    
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    int8_t SetCurrentErrorStatus(int8_t error_id);
    
    void Vehicle::Run<0>();
    void inline Vehicle::Run<1>();
    void inline Vehicle::Run<2>();
    void inline Vehicle::Run<3>();
    void inline Vehicle::Run<4>();
    // begining of control loop
    void Vehicle::Run<5>();
    void inline Vehicle::Run<6>();
    void inline Vehicle::Run<7>();
    void inline Vehicle::Run<8>();
    void inline Vehicle::Run<10>();
    void inline Vehicle::Run<11>();
    void inline Vehicle::Run<12>();
    void inline Vehicle::Run<13>();
    // beginig of distance sensor loop
    void Vehicle::Run<14>();
    void inline Vehicle::Run<15>(void* param_data, uint8_t i);
    void inline Vehicle::Run<16>(void* param_data, uint8_t i);
    // RECURSIVE NESTING??
    void inline Vehicle::Run<17>(void* param_data, uint8_t i);
    // end of distance sensor loop
    void inline Vehicle::Run<18>();
    void inline Vehicle::Run<19>(void* param_data, uint8_t i);
    void inline Vehicle::Run<20>(void* param_data, uint8_t i);
    void inline Vehicle::Run<21>();
    // uint8_t AraModel<U>::IntersectionTest();
    // param_data(position vector, speed vector, accel vector, trajectory polynomials)
    void inline Vehicle::Run<22>();
    void inline Vehicle::Run<23>(void* param_data);
    void inline Vehicle::Run<24>(void* param_data);
    void inline Vehicle::Run<25>(void* param_data);
    void inline Vehicle::Run<26>(void* param_data);
    void inline Vehicle::Run<27>();
    void inline Vehicle::Run<28>();
    void inline Vehicle::Run<29>(uint8_t i);
    void inline Vehicle::Run<30>(uint8_t i);
    void inline Vehicle::Run<31>();
    // end of control loop
    void inline Vehicle::Run<32>();
    // Error management branch
    void inline Vehicle::Run<33>(uint8_t err);
    void inline Vehicle::Run<34>();
    
    
private:    
    std::vector<BaseModule*> error_manager_container_;
    
    // vehicle components
    SystemEventLog* system_log_;
    BeepSpeaker* status_beep_speaker_;
    
    SerialDriver* sensor_controller_comm_;
    SerialDriver* actuator_controller_comm_;
    BatteryManager* battery_0_manager_;
    uint8_t num_of_actuator_drivers_;
    ActuatorDriver** actuator_drivers_;
    InertialMeasurementUnit* central_IMU_sensor_;
    EnvironmentalSensor* env_temp_hum_sensor_;
    uint8_t num_of_distance_sensors_;
    DistanceSensor** distance_sensors_;
    
    
    AreaModel<Vector>* metric_point_area_model_;
    //AreaModel* thermal_point_are_model_;
    TCPDriver* metric_point_area_comm_;
    //TCPDriver* thermal_point_area_comm_;
    
    MechanicalModel* mechanical_model_;
    TCPDriver* user_realtime_control_comm_;
    
    uint8_t vehicle_id_;
    uint8_t vehicle_right_;
    TCPDriver** vehicle_group_;
    
    bool all_commands_executed_;
    
    // timing control and operation synchronization
    long elapsed_operation_time_;
    
    
    // task section
    Command** operation_tasks_;
    
    
    
    
    // error management
    ErrorType current_error_status_;
    
    
    // supervisory system
    uint8_t num_of_crashes_;
   
};

struct ErrorType{
    ErrorType();
    uint8_t current_error_status_;
    bool inline operator=(uint8_t k);
    bool inline operator!=(uint8_t k);
    bool inline operator==(uint8_t k);
};

struct VehicleParameter{
    char* log_file_name_;
    
    char* sensor_controller_comm_port_;
    long sensor_controller_comm_timeout_;
    uint8_t sensor_controller_comm_establishment_attemption_limit_;
    
    uint8_t beep_speaker_port_;
    
    char* actuator_controller_comm_port_;
    long actuator_controller_comm_timeout_;
    uint8_t actuator_controller_comm_establishment_attemption_limit_;
    
    uint8_t battery_cell_number_;
    double battery_capacity_;
    double battery_discharge_rate_;
    double battery_full_lvl_;
    double battery_warning_lvl_;
    double battery_critical_lvl_;
    
    uint8_t num_of_actuator_drivers_;
    uint8_t* actuator_driver_ports_;
    double* pid_control_section_lower_bounds_;
    double* pid_control_section_upper_bounds_;
    struct ActuatorParams{
        uint8_t* esc_comm_pins_;
        uint64_t calibration_delay_;
        uint64_t pwm_signal_frequency_;
        uint64_t lower_pulse_bound_;
        uint64_t upper_pulse_bound_;
        double offset_pwm_deg_;
        double max_BEC_output_;
         double bearing_efficiency_;
        double max_torque_;
        uint64_t spin_up_of_unit_deg_inc_;
        uint64_t motor_kv_rate_;
        double blade_mass_;
        double blade_length_;
        double blade_width_;
        double blade_efficiency_;
        double max_thrust_;
        double max_consumption_;
    }actuator_params_;
        
    uint8_t* central_IMU_sensor_ports_;
    long central_IMU_sensor_samling_rate_;
    Vector<double> central_IMU_sensor_position_offset_;
    
    uint8_t* env_temp_hum_sensor_ports_;
    long env_temp_hum_sensor_sampling_rate_;
    
    uint8_t num_of_distance_sensors_;
    uint8_t** distance_sensor_ports_;
    long distance_sensor_sampling_rate_;
    Vector<double>* distance_sensor_position_offsets_;
    
    char* metric_point_area_comm_address_;
    uint32_t metric_point_area_comm_port_;
    long metric_point_area_comm_timeout_;
    
    struct MechanicalParams{
        double vehicle_weight_;
        
        Vector<double>** external_forces_;
        Vector<double>** internal_forces_;
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
    }mechanical_params_;
    
        
    char* user_realtime_control_comm_address_;
    uint32_t user_realtime_control_comm_port_;
    long user_realtime_control_comm_timeout_;
    uint8_t vehicle_id_;
    uint8_t vehicle_right_;
};

#endif /* VEHICLE_H */

