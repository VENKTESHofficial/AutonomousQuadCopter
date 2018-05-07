#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H
#include <stdint.h>
#include "BaseModule.h"
#include "DriverBase.h"
// DistanceSensor class
// Distance measurement sensor driver class
// Generalized operation(laser, ultrasonic, etc..)
class DistanceSensor : public BaseModule, DriverBase{
public:
    DistanceSensor();
    DistanceSensor(const DistanceSensor& orig);
    virtual ~DistanceSensor();
    
    uint8_t ReceiveData();
    void* TransmitData();
    template <uint8_t k>
    uint8_t ReceiveData(void* param_data);
    template <uint8_t k>
    void* TransmitData();
    
    bool InitComponent();
    
    bool SignalConditioner();
    
    uint8_t* GetDistanceSensorCommPins();
    uint64_t GetAbsoroptionWeeknessTimeout();
    double GetLowerPulseBounds();
    double GetUpperPulseBound();
    uint64_t GetSamplingRate();
    uint8_t GetErrotNumberThreshold();
    double GetRelativeRadarXPos();
    double GetRelativeRadarYPos();
    double GetRelatieRadarZPos();
    
    struct BoundaryIntExclusion{
        bool operator();
    }bound_int_excl_;
private:
    // correction of crystal oscillator sampling rate fluctuation
    double crystal_oscillation_correction_;
    // this is according to local temperature value of environmental sensor
    // -> live correction
    
    uint8_t* distance_sensor_comm_pins_;
    uint64_t absorption_weekness_timout_;
    double lower_pulse_bound_;
    double upper_pulse_bound_;
    uint64_t sampling_rate_;
    uint8_t error_number_threshold_;
    double relative_radar_x_pos_;
    double relative_radar_y_pos_;
    double relative_radar_z_pos_;
    
    
    
};

#endif /* DISTANCESENSOR_H */

