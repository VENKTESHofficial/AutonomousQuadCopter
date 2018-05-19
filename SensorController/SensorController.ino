// Sensor controller slave device - SensorController
// System components(this device)
//  BatteryManager
//  CrystalOscillator
//  EnvironmentalSensorDriver
//  SensorController
//  SerialDriver
//  UltrasonicSensorDriver
//  VoltageMeterDriver
// 
// Pin layout
//
// 
// 
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "BatteryManager.h"
#include "CrystalOscillator.h"
#include "EnvironmentalSensorDriver.h"
#include "SerialDriver.h"
#include "UltrasonicSensorDriver.h"
#include "VoltageMeterDriver.h"

uint8_t voltage_meter_driver_pin_;
VoltageMeterDriver* voltage_meter_driver_;
uint8_t batter_manger_pin_;
BatteryManager* battery_manager_;
uint32_t measurement_cycle_delay_;// usec
uint8_t num_of_hw_elements_;// all types of hardwares count
int8_t component_error_status_;
SerialDriver* serial_comm_;
EnvironmentalSensorDriver* environmental_sensor_;
uint8_t num_of_distance_sensors_;
UltrasonicSensorDriver** distance_sensors_;


void setup() {
	comp_err_stat_ = 0;
	
	// First priority battery charge level check by voltage sensor
	voltage_meter_driver_ = new VoltageMeterDriver(voltage_meter_driver_pin_);
	battery_manager_ = new BatteryManager(batter_manger_pin_);
	
	if(comp_err_stat_ = voltage_meter_driver_->ReceiveData<0>()){
		measurement_cycle_delay_ = 100;
		
		// 1 pc environmental sensor
		// 1 pc voltage meter sensor
		// 4 pcs ultrasonic sensor
		// 1 pc beep speaker
		// 1 pc serial(USB) communication
		num_of_hw_elements_ = 9;
		
		
		
		environmental_sensor_ = new EnvironmentalSensorDriver();
		
		num_of_distance_sensors_ = 4;
		distance_sensors_ = (UltrasonicSensorDriver**)
			malloc(sizeof(UltrasonicSensorDriver*) * num_of_distance_sensors_);
		
		for(uint8_t i = 0; i < num_of_distance_sensors_; ++i){
			distance_sensors_[i] = new UltrasonicSensorDriver();
		}
		
		
		serial_comm_ = new SerialDriver(9600);
		comp_err_stat_ = serial_comm_->ReceiveData<0>();// init routine
	}
}


template <uint8_t k>
inline void Run();

// init check
inline void Run<0>(){
	if(comp_err_stat_)Run<1>();
	else Run</*error routine*/>();
}

// object init check(conversion, conditional requirements)
inline void Run<1>(){
	if(comp_err_stat_ = serial_comm_->ReceiveData())Run<2>();
	else Run</*error routine*/>();
}

// environmental sensor read
inline void Run<2>(){
	if(comp_err_stat_ = environmental_sensor_->ReceiveData())Run<3>();
}

// distance sensor 0 read
inline void Run<3>(){
	
}

// distance sensor 1 read
inline void Run<4>(){
	
}

// distance sensor 2 read
inline void Run<5>(){
	
}

// distance sensor 3 read
inline void Run<6>(){
	
}




void loop() {
	Run<0>();
	
}
