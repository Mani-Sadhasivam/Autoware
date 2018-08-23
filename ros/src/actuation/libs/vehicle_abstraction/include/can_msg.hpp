#ifndef CAN_MSG_H
#define CAN_MSG_H

namespace vehicle_abstraction
{
class CanMsg
{
public:
	uint16_t id;
	uint8_t dlc;
	uint64_t cycle_time;
	uint64_t timestamp;

	typedef enum wheel {
		FRONT_RIGHT,
		FRONT_LEFT,
		REAR_RIGHT,
		REAR_LEFT,
	} WHEEL_ENUM;

	typedef enum gear {
  		GEAR_N,
		GEAR_1,
		GEAR_2,
		GEAR_3,
		GEAR_4,
		GEAR_5,
  	} GEAR_ENUM;

	struct _raw_msg {
		uint16_t accel: 9;
		uint16_t steer_angle: 7;
		uint8_t gear: 3;
		uint8_t padding: 5;
	} raw_msg;

	struct _phys_msg {
		double accel;
		double steer_angle;
		double wheel_speed_fr;
		double wheel_speed_fl;
		double wheel_speed_rr;
		double wheel_speed_rl;
	} phys_msg;

	virtual struct _raw_msg getRawMsg() = 0;
	virtual void setRawMsg(struct _raw_msg) = 0;
	virtual void readyToSend(uint64_t current_time) = 0;
	virtual void isTimedOut(uint64_t current_time) = 0;
};
}

#endif
