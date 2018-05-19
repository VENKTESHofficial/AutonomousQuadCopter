#ifndef SENSORBASE_H
#define SENSORBASE_H
#include <stdint.h>
template <class U>
class SensorBase{
	protected:
		uint8_t* comm_pins_;
	public:
		uint8_t* GetCommPins(){return comm_pins_;}
		virtual uint8_t SignalConditioner() = 0;
		virtual uint8_t ReadValue() = 0;
		virtual uint8_t WriteValue() = 0;
		virtual uint8_t ReceiveData() = 0;
		virtual U TransmitData(void* param_data) = 0;
};
#endif // SENSORBASE_H
