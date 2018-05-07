#ifndef COMMAND_H
#define COMMAND_H
#include <stdint.h>
#include "BaseModule.h"
// Command class
// Contains one multiple layer instruction unit
class Command : public BaseModule{
public:
    Command();
    Command(Vector<Polynomial<double>**>* motor_thrust_time_polynomials,
        Vector<Polynomial<double>**>* axial_position_time_polynomials,
        Vector<Polynomial<double>**>* angular_position_time_polynomials);
    Command(const Command& orig);
    virtual ~Command();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    // command data structure connectors
    Command* preceeding_command_;
    Command* succeeding_command_;
    
    
    
    
private:
    Vector<Polynomial<double>**>* motor_thrust_time_polynomials_;
    Vector<Polynomial<double>**>* axial_position_time_polynomials_;
    Vector<Polynomial<double>**>* angular_position_time_polynomials_;
};

#endif /* COMMAND_H */

