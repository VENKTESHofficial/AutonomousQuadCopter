#ifndef ACTUATORDRIVER_H
#define ACTUATORDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
class Vehicle;
#include "PID.h"
// ActuatorDriver class
// Drives electric speed controller, that belongs to electric motor
// Uses PWM method(conversion is defined)
// The PID stabilization, correction routines are here
class ActuatorDriver : public BaseModule{
public:
    ActuatorDriver();
    ActuatorDriver(ActuatorParams actuator_params);
    ActuatorDriver(const ActuatorDriver& orig);
    virtual ~ActuatorDriver();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    bool InitComponent();
    
    static bool calibration_mode_;
    
    
private:
    
    uint8_t* esc_comm_pins_;
    uint64_t calibration_delay_;
    uint64_t pwm_signal_frequency_;
    uint64_t lower_pulse_bound_;// changes dynamically according to battery level
    uint64_t upper_pulse_bound_;// changes dynamically according to battery level
    double offset_pwm_deg_;
    // double environmental_temperature_;// <- in environmental sensor
    // double environmental_humidity_;// <- in environmental sensor
    // double environmental_pressure_;// <- in environmental sensor
    // double gas_internal_energy_;
    double max_BEC_output_;
    // lubrication of bearings, axial revolution resistance
    double bearing_efficiency_;
    double max_torque_;// according to payload
    double recent_max_torque_;
    // maximal spin up(acceleration seek) time at 1 deg inc.
    uint64_t spin_up_of_unit_deg_inc_;
    uint64_t motor_kv_rate_;// certain rpm of application of one volt
    double blade_mass_;
    double blade_length_;// even length(e.g. 11.4 in)
    double blade_width_;// e.g. 4.7 in
    /// relative maximal revolution speed
    double blade_efficiency_;
    double max_thrust_;// derived from max torque and blade characteristics
    double max_consumption_;
    
    
    PID* pitch_pid_controller_;
    PID* roll_pid_controller_;
    PID* yaw_pid_controller_;
    PID* elevation_pid_controller_;
    
    // for init thrust depends on mass and thruster characteristic
    uint64_t init_pulse_;
    
};



#endif /* ACTUATORDRIVER_H */

