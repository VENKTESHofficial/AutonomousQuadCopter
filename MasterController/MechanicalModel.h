#ifndef MECHANICALMODEL_H
#define MECHANICALMODEL_H
#include <stdint.h>
//#include <stdio.h>
#include <stdint.h>
#include "BaseModule.h"
class Vehicle;
//#include "Vehicle.h"
#include "Matrix.h"
#include "Vector.h"
#include "Polynomial.h"
#include "Command.h"

// Dependencies
//  MotorDriver
//  EnvironmentalSensor
//  AreaModel
//  SerialDriver
//  Matrix
//  Vector
//  BeepSpeaker
//  Command
//  BatteryManager
//  InertialMeasurementUnit

// MechanicalModel class
// Designs the operation path looking for the incoming restrictions like obstacles
// boundary constraints(position, speed, acceleration, time, etc..)
class MechanicalModel : public BaseModule{
public:
    MechanicalModel();
    MechanicalModel(MechanicalParams mechanical_params,
        BaseModule** module_dependencies);
    MechanicalModel(const MechanicalModel& orig);
    virtual ~MechanicalModel();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();

    int8_t UpdatePositionVector();// return with the op. status
    int8_t UpdateSpeedVector();
    int8_t UpdateAccelVector(Vector<double>* param_data);
    
    bool Evaluate();
    
    
private:
    double calculation_requirement_;// percent-base time requirement
    Command** command_list_;// computed actuator instructions
    uint8_t atomic_trajectory_limit_;
    bool trajectory_generation_mode_;// true:less exec. time; false:less consumption
    double ax_acc_step_;// strict axial acceleration step
    double an_acc_step_;// strict angular acceleration step
    
    ActuatorDriver** actuator_drivers_;
    Vector<double>* error_thresholds_;// target difference toleration
    double current_max_torque_;
    uint64_t current_spin_up_of_unit_deg_inc_;
    double current_maximal_thrust_;
    uint64_t trajectory_execution_time_limit_;
    
    
    Matrix<double>* translation_matrix_;
    Matrix<double>* rotation_matrix_;
    Matrix<double>* scaling_matrix_;
    
    // global(point-represented) vehicle attributes
    Vector<double>* axial_position_;// x, y, z
    Vector<double>* angular_position_;// pitch, roll, yaw
    Vector<double>* axial_speed_;
    Vector<double>* angular_speed_;
    Vector<double>* axial_acceleration_;
    Vector<double>* angular_acceleration_;
    
    double circumference_speed_;
    double circumference_acceleration_;
    
    
    double vehicle_weight_;
    Vector<double>** external_forces_;
    Vector<double>** internal_forces_;
    bool discretization_sampling_mode_;
    long actuator_time_sampling_rate_;
    uint64_t actuator_dist_sampling_rate_;
    Vector<double>* met_pos_up_bnds_;// metric position upper bounds
    Vector<double>* met_pos_lo_bnds_;// metric position lower bounds
    Vector<double>* met_spd_up_bnds_;// metric speed upper bounds
    Vector<double>* met_spd_lo_bnds_;// metric speed lower bounds
    Vector<double>* met_acc_up_bnds_;// metric acceleration upper bounds
    Vector<double>* met_acc_lo_bnds_;// metric acceleration lower bounds
    Vector<double>* ang_pos_up_bnds_;// angular position upper bounds
    Vector<double>* ang_pos_lo_bnds_;// angular position lower bounds
    Vector<double>* ang_spd_up_bnds_;// angular speed upper bounds
    Vector<double>* ang_spd_lo_bnds_;// angular speed lower bounds
    Vector<double>* ang_acc_up_bnds_;// angular acceleration upper bounds
    Vector<double>* ang_acc_lo_bnds_;// angular acceleration lower bounds
    Vector<double>* pos_traj_exec_err_bounds_;// position trajectory execution error bounds
};

#endif /* MECHANICALMODEL_H */

