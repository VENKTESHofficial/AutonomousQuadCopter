#include "Command.h"

Command::Command() {
}

Command::Command(Vector<Polynomial<double>**>* motor_thrust_time_polynomials,
        Vector<Polynomial<double>**>* axial_position_time_polynomials,
        Vector<Polynomial<double>**>* angular_position_time_polynomials)
: motor_thrust_time_polynomials_(motor_thrust_time_polynomials),
        axial_position_time_polynomials_(axial_position_time_polynomials),
        angular_position_time_polynomials_(angular_position_time_polynomials){

}
    

Command::Command(const Command& orig) {
}

Command::~Command() {
}

uint8_t Command::ReceiveData(){

}

void* Command::TransmitData(){

}

template <uint8_t k>
uint8_t Command::ReceiveData(void* param_data){

}

// updating motor thrust time polynomial values
uint8_t Command::ReceiveData<1>(void* param_data){
    return 0;
}

// updating axial position time polynomial values
uint8_t Command::ReceiveData<2>(void* param_data){
    return 0;
}

// updating angular position time polynomials
uint8_t Command::ReceiveData<3>(void* param_data){
    return 0;
}

template <uint8_t k>
void* Command::TransmitData(){

}



