#include <iostream>

#include "can_msg.hpp"

using namespace std;

namespace vehicle_abstraction
{
class VehicleStateMsg: public CanMsg
{
	double getWheelSpeed(WHEEL_ENUM wheel)
	{
		switch(wheel) {
		case FRONT_RIGHT:
			return phys_msg.wheel_speed_fr;
		case FRONT_LEFT:
			return phys_msg.wheel_speed_fl;
		case REAR_RIGHT:
			return phys_msg.wheel_speed_rr;
		case REAR_LEFT:
			return phys_msg.wheel_speed_rl;
		}
	}

	double getPhysSteerAngle(void) {
		return phys_msg.steer_angle;
	}

	struct _raw_msg getRawMsg(void)
	{
		return raw_msg;
	}

	void setRawMsg(struct _raw_msg)
	{
		//TODO
	}

	void readyToSend(uint64_t current_time)
	{
		//TODO
	}
	void isTimedOut(uint64_t current_time)
	{
		//TODO
	}
};
}
