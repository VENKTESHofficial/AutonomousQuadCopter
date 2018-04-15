#include "Vehicle.h"
#include "Vector.h"


Vehicle::Vehicle(){

}

Vehicle::Vehicle(uint8_t* hw_pin_layout, uint8_t vehicle_id, uint8_t vehicle_right) {
    central_IMU_sensor_ = hw_pin_layout[0];
    motor_ESC_0_ = hw_pin_layout[1];
    motor_ESC_1_ = hw_pin_layout[2];
    motor_ESC_2_ = hw_pin_layout[3];
    motor_ESC_3_ = hw_pin_layout[4];
    env_temp_hum_sensor_ = hw_pin_layout[5];
    voltage_meter_0_ = hw_pin_layout[6];
    voltage_meter_1_ = hw_pin_layout[7];
    voltage_meter_2_ = hw_pin_layout[8];
    distance_sensor_0_ = hw_pin_layout[9];
    distance_sensor_1_ = hw_pin_layout[10];
    distance_sensor_2_ = hw_pin_layout[11];
    distance_sensor_3_ = hw_pin_layout[12];
    
    
    
    
    vehicle_id_ = vehicle_id;
    vehicle_right_ = vehicle_right;
    
    elapsed_operation_time_ = 0;
    
    num_of_crashes_ = 0;
    
    axial_position_ = new Vector(0.0, 0.0, 0.0);
    angular_position_ = new Vector(0.0, 0.0, 0.0);
    axial_speed_ = new Vector(0.0, 0.0, 0.0);
    angular_speed_ = new Vector(0.0, 0.0, 0.0);
    axial_acceleration_ = new Vector(0.0, 0.0, 0.0);
    angular_acceleration_ = new Vector(0.0, 0.0, 0.0);
    circumference_speed_ = 0.0;
    circumference_acceleration_ = 0.0;
    
    
    
}

Vehicle::Vehicle(const Vehicle& orig) {
}

Vehicle::~Vehicle() {
}



