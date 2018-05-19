#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
class SerialDriver{
	private:
		baud_rate_;
	public:
		SerialDriver();
		
		SerialDriver(uint16_t baud_rate);
		
		template <uint8_t k>
		void void* TransmitData();
		
		template <uint8_t k>
		uint8_t ReceiveData();
		
};
#endif // SERIALDRIVER_H
