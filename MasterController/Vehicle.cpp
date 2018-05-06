#include "Vehicle.h"
#include "Vector.h"

// TRAJCTORYMODEL CLASS implementation
// to implement MechanicalModel class
// the math library implmenentation preceeds it
Vehicle::Vehicle(){

}

Vehicle::Vehicle(VehicleParameter v_params) {
    
    // Structured architecture
    // The slave control devices initialize by the master signals/commands
    // at instantiation
    
    system_log_ = new SystemEventLog(v_params.log_file_name_);
    error_manager_container_.push_back(system_log_);
    
    sensor_controller_comm_ = new SerialDriver(
        v_params.sensor_controller_comm_port_,
        v_params.sensor_controller_comm_timeout_,
        v_params.sensor_controller_comm_establishment_attemption_limit_);
    error_manager_container_.push_back(sensor_controller_comm_);
    
    status_beep_speaker_ = new BeepSpeaker(v_params.beep_speaker_port_);
    error_manager_container_.push_back(status_beep_speaker_);
    
    actuator_controller_comm_ = new SerialDriver(
        v_params.actuator_controller_comm_port_,
        v_params.actuator_controller_comm_timeout_,
        v_params.actuator_controller_comm_establishment_attemption_limit_);
    error_manager_container_.push_back(actuator_controller_comm_);
    
    battery_0_manager_ = new BatteryManager(
        v_params.battery_cell_number_,
        v_params.battery_capacity_,
        v_params.battery_discharge_rate_,
        v_params.battery_full_lvl_,
        v_params.battery_warning_lvl_,
        v_params.battery_critical_lvl_);
    error_manager_container_.push_back(battery_0_manager_);
    
    num_of_motor_drivers_ = v_params.num_of_motor_drivers_;
    motor_drivers_ =
        (MotorDriver*)malloc(sizeof(MotorDriver*) * num_of_motor_drivers_);
    for(uint8_t i = 0; i < num_of_motor_drivers_; ++i){
        motor_drivers_[i] = new MotorDriver(
            v_params.motor_driver_ports_[i],
            v_params.pid_control_section_lower_bounds_,
            v_params.pid_control_section_upper_bounds_);
        error_manager_container_.push_back(motor_drivers_[i]);
    }
    
    central_IMU_sensor_ = new InertialMeasurementUnit(
        v_params.central_IMU_sensor_ports_,
        v_params.central_IMU_sensor_samling_rate_,
        v_params.central_IMU_sensor_position_offset_);
    error_manager_container_.push_back(central_IMU_sensor_);
    
    env_temp_hum_sensor_ = new EnvironmentalSensor(
        v_params.env_temp_hum_sensor_ports_,
        v_params.env_temp_hum_sensor_sampling_rate_);
    error_manager_container_.push_back(env_temp_hum_sensor_);
    
    num_of_distance_sensors_ = v_params.num_of_distance_sensors_;
    distance_sensors_ =
        (DistanceSensor*)malloc(sizeof(DistanceSensor*) * num_of_distance_sensors_);
    for(uint8_t i = 0; i < num_of_distance_sensors_; ++i){
        distance_sensors_[i] = new DistanceSensor(
            new uint8_t*{v_params.distance_sensor_ports_[i][0],
                v_params.distance_sensor_ports_[i][1]},
                v_params.distance_sensor_sampling_rate_,
                v_params.distance_sensor_position_offsets_[i]);
    }
            
    metric_point_area_model_ = new AreaModel<Vector>();
    error_manager_container_.push_back(metric_point_area_model_);
    
    metric_point_area_comm_ = new TCPDriver(
        v_params.metric_point_area_comm_address_,
        v_params.metric_point_area_comm_port_,
        v_params.metric_point_area_comm_timeout_);
    error_manager_container_.push_back(metric_point_area_comm_);
    
    mechanical_model_ = new MechanicalModel(v_params.mechanical_params_);
    error_manager_container_.push_back(mechanical_model_);
    
    user_realtime_control_comm_ = new TCPDriver(
        v_params.user_realtime_control_comm_address_,
        v_params.user_realtime_control_comm_port_,
        v_params.user_realtime_control_comm_timeout_);
    error_manager_container_.push_back(user_realtime_control_comm_);
    
    vehicle_id_ = v_params.vehicle_id_;
    vehicle_right_ = v_params.vehicle_right_;
    vehicle_group_ = new TCPDriver(vehicle_id_, vehicle_right_);
    error_manager_container_.push_back(vehicle_group_);
    
    elapsed_operation_time_ = 0;
    
    current_error_status_ = ErrorType();
    
    num_of_crashes_ = 0; 

}

Vehicle::Vehicle(const Vehicle& orig) {
}

Vehicle::~Vehicle() {
}

// CONTROL CHAIN SEQUENCE
void Vehicle::Run<0>(){
    if(current_error_status_ = this->InitVehicle())this->Run<1>();
}

void inline Vehicle::Run<1>(){
    if(current_error_status_= system_log_
    ->ReceiveData((void*)("Initialization was successful.\n")))this->Run<2>();
}

void inline Vehicle::Run<2>(){
    if(current_error_status_ = system_log_
    ->ReceiveData((void*)("Constructing the first trajectory.")))
    this->Run<3>();
}

void inline Vehicle::Run<3>(){
    if(current_error_status_ = mechanical_model_
    ->ReceiveData<2>((void*)(NULL)))this->Run<4>();
}

void inline Vehicle::Run<4>(){
    if(!current_error_status_ != 1 && !current_error_status_ = system_log_->
            ReceiveData((void*)("Initial trajectory was not available. System has stopped.\n"))){
        this->Run<5>();
    }
}

// begining of control loop
void Vehicle::Run<5>(){
    if(current_error_status_ == 0)this->Run<6>();
}

void inline Vehicle::Run<6>(){
    //metric_point_area_comm_->ReceiveData<1>();// automatic telemetry broadcast
    if(current_error_status_ =
        system_log_->ReceiveData((void*)("Getting IMU raw datas.\n")))
        this->Run<7>();
}

void inline Vehicle::Run<7>(){
    if(current_error_status_ = central_IMU_sensor_
        ->ReceiveData<1>(actuator_controller_comm_->TransmitData<1>()))
        this->Run<8>();
}

void inline Vehicle::Run<8>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Updating vehicle position vectors.\n")))
        this->Run<9>();
}

void inline Vehicle::Run<10>(){
    if(current_error_status_ =
        mechanical_model_->ReceiveData<1>(central_IMU_sensor_->TransmitData<1>()))
        this->Run<11>();
}

void inline Vehicle::Run<11>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Updating environmental values.\n")))
        this->Run<12>();
}

void inline Vehicle::Run<12>(){
    if(current_error_status_ = env_temp_hum_sensor_
        ->ReceiveData<1>(sensor_controller_comm_->TransmitData<1>()))
        this->Run<13>();
}

void inline Vehicle::Run<13>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Updating distance vals(vectors).\n")))
        this->Run<14>();
}

// beginig of distance sensor loop
void Vehicle::Run<14>(){
    Vector<void*>* param_data;
    if(current_error_status_ = param_data->PushBack(&num_of_distance_sensors_))
        this->Run<15>((void*)param_data, 0);
}

void inline Vehicle::Run<15>(void* param_data, uint8_t i){
    if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)(env_temp_hum_sensor_->TransmitData<1>())))
        this->Run<16>(param_data, i);
}

void inline Vehicle::Run<16>(void* param_data, uint8_t i){
    if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)(sensor_controller_comm_->TransmitData<2>())))
        this->Run<17>();
}

// RECURSIVE NESTING??
void inline Vehicle::Run<17>(void* param_data, uint8_t i){
    if(current_error_status_ = distance_sensors_[i]->ReceiveData<1>((void*)param_data)){
        delete param_data;
        if(++i < num_of_distance_sensors_)this->Run<14>();
        else this->Run<18>();
    }
}
// end of distance sensor loop

void inline Vehicle::Run<18>(){
    if(current_error_status_ =
        system_log_->ReceiveData((void*)("Updating metric point area model.\n"))){
        Vector<void*>* param_data;
        this->Run<19>((void*)param_data, 0);
    }
}

void inline Vehicle::Run<19>(void* param_data, uint8_t i){
   if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)(distance_sensors_[i]->TransmitData<1>())))
        if(i < num_of_distance_sensors_)
            this->Run<19>((void*)param_data, uint8_t ++i);
        else
            this->Run<20>();
}

void inline Vehicle::Run<20>(void* param_data, uint8_t i){
    if(current_error_status_ = metric_point_area_model_
        ->ReceiveData<1>((void*)param_data)){
        delete param_data;
        this->Run<21>();
    }
}

void inline Vehicle::Run<21>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Testing for trajectorial collision.\n")))
        this->Run<22>();
}

// uint8_t AraModel<U>::IntersectionTest();
// param_data(position vector, speed vector, accel vector, trajectory polynomials)
void inline Vehicle::Run<22>(){
    Vector<void*>* param_data;
    if(current_error_status_ = param_data
        ->PushBack((void*)mechancial_model_->TransmitData<1>()))
        this->Run<23>((void*)param_data);
}

void inline Vehicle::Run<23>(void* param_data){
    if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)mechanical_model_->TransmitData<2>()))
        this->Run<24>((void*)param_data);
}

void inline Vehicle::Run<24>(void* param_data){
    if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)mechanical_model_->TransmitData<3>()))
        this->Run<25>((void*)param_data);
}


void inline Vehicle::Run<25>(void* param_data){
    if(current_error_status_ = ((Vector<void*>*)param_data)
        ->PushBack((void*)mechanical_model_->TransmitData<4>()))
        this->Run<26>();
}

void inline Vehicle::Run<26>(void* param_data){
    if(!current_error_status_ = metric_point_area_model_
        ->ReceiveData<2>((void*)param_data) && current_error_status_ == 1)
        this->Run<27>();
    else if(current_error_status_ > 0) this->Run<31>();// isolated area
    
}

void inline Vehicle::Run<27>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Trajectorial collision. Searching for new flight pathway.\n")))
        this->Run<28>();
}

void inline Vehicle::Run<28>(){
    if(current_error_status_ = mechanical_model_
        ->ReceiveData<2>((void*)metric_point_area_model_->TransmitData<1>()))
        this->Run<29>(0);
    if(current_error_status_ > 2)
        this->Run<31>();// isolated area due to vehicle conditions
}

void inline Vehicle::Run<29>(uint8_t i){
    if(current_error_status_ = motor_drivers_[i]
                    ->ReceiveData<1>((void*)(mechanical_model_->TransmitData<5>())))
        this->Run<30>(i);
}

void inline Vehicle::Run<30>(uint8_t i){
    if(current_error_status_ = actuator_controller_comm_
        ->ReceiveData<1>((void*)(motor_drivers_[i]->TransmitData<1>()))){
        if(i < num_of_motor_drivers_)
            this->Run<29>(++i);
        else
            this->Run<5>();
    }
}

void inline Vehicle::Run<31>(){
    if(current_error_status_ = system_log_
        ->ReceiveData((void*)("Could not design new pathway. System stop.\n")))
        this->Run<32>();
}
// end of control loop

void inline Vehicle::Run<32>(){
    uint8_t err = current_error_status_.current_error_status_;
    if(current_error_status_ = system_log_
        ->TransmitData("Error at execution, error id: " + err + "\n"))
        this->Run<33>(err);
}

// Error management branch
void inline Vehicle::Run<33>(uint8_t err){
    if(current_error_status_ = status_beep_speaker_->ReceiveData<0>((void*)err))
        this->Run<34>();
}

void inline Vehicle::Run<34>(){
    
}
// END OF CONTROL CHAIN SEQUENCE


int8_t Vehicle::InitVehicle(){
    
    // startup module tests including dependent tests
    int8_t status = 0;
    for(uint8_t i = 0; i < sizeof(error_manager_container_); ++i){
        for(uint8_t j = 0; j < error_manager_container_[i]; ++j){
            status = *(error_manager_container_[i]->InitComponent());
            if(status != 0){
                status += (i * 100);
                
                return status;
            }
        }
    }
    
    return 0;
}

uint8_t Vehicle::ReceiveData(){
    return 0;
}

void* Vehicle::TransmitData(){
    return NULL;
}

template <uint8_t k>
uint8_t Vehicle::ReceiveData(void* param_data){
    return 0;
}

template <uint8_t k>
void* Vehicle::TransmitData(){
    return NULL;
}

void Vehicle::SetCurrentErrorStatus(int8_t error_id){
    current_error_status_ = error_id;
}

ErrorType::ErrorType(){
}

bool inline ErrorType::operator=(uint8_t k){
    current_error_status_ = k;
    if(k)return true;
    else return false;
}

bool inline ErrorType::operator!=(uint8_t k){
    if(current_error_status_ != k) return true;
    else return false;
}

bool inline ErrorType::operator==(uint8_t k){
    if(current_error_status_)return true;
    else return false;
}