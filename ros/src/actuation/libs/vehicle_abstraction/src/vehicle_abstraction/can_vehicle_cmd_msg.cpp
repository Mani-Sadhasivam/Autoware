#include <iostream>

#include "can_msg.hpp"

using namespace std;

namespace vehicle_abstraction
{
class VehicleCmdMsg: public CanMsg
{
public:
	void setRawAxCommand(uint32_t ax)
	{
		raw_msg.accel = ax;
		phys_msg.accel = ax * 0.01 + 5;
	}

	void setPhysAxCommand(double ax_mps2)
	{
		phys_msg.accel = ax_mps2;
		raw_msg.accel = (ax_mps2 - 5) / 0.01;
	}

	void setRawSteerAngle(uint32_t st)
	{
		raw_msg.steer_angle = st;
		phys_msg.steer_angle = st * 0.01 + 5;
	}

	void setPhysSteerAngle(double st_phys)
	{
		phys_msg.steer_angle = st_phys;
		raw_msg.steer_angle = (st_phys - 5) / 0.01;
	}

	void setGear(GEAR_ENUM gear)
	{
		cout << "Setting gear to: " << gear << endl;
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
