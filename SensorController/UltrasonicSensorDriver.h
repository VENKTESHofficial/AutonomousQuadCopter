#ifndef ULTRASONICSENSORDRIVER_H
#define ULTRASONICSENSORDRIVER_H
#include <stdint.h>
#include "SensorBase.h"
class UltrasonicSensorDriver : public SensorBase<float>{
	private:
		uint32_t distance_sensor_delay;// usec
	public:
};
#endif // ULTRASONICSENSORDRIVER_H
