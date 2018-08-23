#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include "can_msg.hpp"

namespace vehicle_abstraction
{
class CanDriver
{
public:
	virtual void connect() = 0;
	virtual void disconnect() = 0;
	virtual void isConnected() = 0;
	virtual void sendMsg(CanMsg&) = 0;
	virtual void receiveMsg(CanMsg&) = 0;
};
}

#endif
