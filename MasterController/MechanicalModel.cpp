#include "MechanicalModel.h"

MechanicalModel::MechanicalModel() {
    axial_position_ = new Vector(0.0, 0.0, 0.0);
    angular_position_ = new Vector(0.0, 0.0, 0.0);
    axial_speed_ = new Vector(0.0, 0.0, 0.0);
    angular_speed_ = new Vector(0.0, 0.0, 0.0);
    axial_acceleration_ = new Vector(0.0, 0.0, 0.0);
    angular_acceleration_ = new Vector(0.0, 0.0, 0.0);
    circumference_speed_ = 0.0;
    circumference_acceleration_ = 0.0;
}

MechanicalModel::MechanicalModel(MechanicalParams mechanical_params,
    BaseModule** module_dependencies)
    : external_forces_(mechanical_params.external_forces_),
    internal_forces_(mechanical_params.internal_forces_),
    discretization_sampling_mode_(mechanical_params.discretization_sampling_mode_),
    actuator_time_sampling_rate_(mechanical_params.actuator_time_sampling_rate_),
    actuator_dist_sampling_rate_(mechanical_params.actuator_dist_sampling_rate_),
    met_pos_up_bnds_(mechanical_params.metric_position_upper_bounds_),
    met_pos_lo_bnds_(mechanical_params.metric_position_lower_bounds_),
    met_spd_up_bnds_(mechanical_params.metric_speed_upper_bounds_),
    met_spd_lo_bnds_(mechanical_params.metric_speed_lower_bounds_),
    met_acc_up_bnds_(mechanical_params.metric_accel_upper_bounds_),
    met_acc_lo_bnds_(mechanical_params.metric_accel_lower_bounds_),
    pos_traj_exec_err_bounds_(mechanical_params.pos_traj_exec_err_bounds_){
   
    command_list_ = (Command**)malloc(sizeof(Command*));
    axial_position_ = new Vector(0.0, 0.0, 0.0);
    angular_position_ = new Vector(0.0, 0.0, 0.0);
    axial_speed_ = new Vector(0.0, 0.0, 0.0);
    angular_speed_ = new Vector(0.0, 0.0, 0.0);
    axial_acceleration_ = new Vector(0.0, 0.0, 0.0);
    angular_acceleration_ = new Vector(0.0, 0.0, 0.0);
    circumference_speed_ = 0.0;
    circumference_acceleration_ = 0.0; 
}

MechanicalModel::MechanicalModel(const MechanicalModel& orig) {
}

MechanicalModel::~MechanicalModel() {
}

uint8_t MechanicalModel::ReceiveData(){
    return 0;
}

void* MechanicalModel::TransmitData(){
    return NULL;
}

template <uint8_t k>
uint8_t MechanicalModel::ReceiveData(void* param_data){
    return 0;
}

// updating position vectors
uint8_t MechanicalModel::ReceiveData<1>(void* param_data){
    uint8_t error_val = 0;
    if(!(this->UpdateAccelVector((Vector<double>*)param_data))){
        return 1;
    }else if(!(this->UpdateSpeedVector(axial_acceleration_))){
        return 2;
    }else if(!(this->UpdatePositionVector(axial_speed_))){
        return 3;
    }
    return 0;
}


// unoptimized code

// constructing pathway
uint8_t MechanicalModel::ReceiveData<2>(void* param_data){
    Vector<double>** target_vectors = (Vector<double>**)param_data;
    uint8_t num_of_target_vectors = sizeof(target_vectors);
    
    // checking metric boundary conditions
    for(uint8_t i = 0; i < num_of_target_vectors; ++i){
        if(*target_vectors[i] > met_pos_up_bnds_
            ||  *target_vectors[i] < met_pos_lo_bnds_){
            return 4;
        }
    }
    
    // calculation of future position
    // (the position displacement during the calculation time)
    Vector<double>* advanced_speed_vector =
        (*axial_speed_) + (axial_acceleration_ * calculation_requirement_);
    Vector<double>* advanced_position_vector =
        (*axial_position_) + (advanced_speed_vector * calculation_requirement_);
    
    // mode-based atomic trajectory generations
    
    return 0;
}



template <uint8_t k>
void* MechanicalModel::TransmitData(){
    return NULL;
}

int8_t MechanicalModel::UpdatePositionVector(){
    *axial_position_ = (*axial_position_) + axial_speed_;
    if(*axial_position_ > met_pos_up_bnds_
        || * axial_position_ < met_pos_lo_bnds_){
        return 3;
    }
    return 0;
}

int8_t MechanicalModel::UpdateSpeedVector(){
    *axial_speed_ = (*axial_speed_) + axial_acceleration_;
    if(*axial_speed_ > met_spd_up_bnds_
        || *axial_speed_ < met_spd_lo_bnds_){
        return 2;
    }
    return 0;
}

int8_t MechanicalModel::UpdateAccelVector(Vector<double>* param_data){
    *axial_acceleration_ = (*axial_acceleration_) + param_data;
    if(*axial_acceleration_ > met_acc_up_bnds_
        || *axial_acceleration_ < met_acc_lo_bnds_){
        return 1;
    }
    return 0;
}

// optimal trajectory evaluating function
bool MechanicalModel::Evaluate(){
    return true;
}