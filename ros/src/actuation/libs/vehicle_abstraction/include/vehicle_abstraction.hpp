#ifndef VEHICLE_ABSTRACTION_H
#define VEHICLE_ABSTRACTION_H

#include "can_msg.hpp"
#include "can_driver.hpp"

namespace vehicle_abstraction
{
class VehicleAbstraction
{
public:
	CanDriver *can_driver;
	CanMsg *outgoing_msg;
	CanMsg *incoming_msg;

	// Functions manipulating the CAN Messages
	virtual void setGearCmd(uint8_t gear) = 0;
	virtual void setRoadWheelCmd(double angle_rad) = 0;
	virtual void setAxCmd(double ax_mps2) = 0;
	virtual uint8_t getGearState() = 0;
	virtual double getWheelSpeed(uint8_t wheel) = 0;
	virtual double getRoadWheelAngle() = 0;
};
}  // vehicle_abstraction

#endif  // VEHICLE_ABSTRACTION_H
