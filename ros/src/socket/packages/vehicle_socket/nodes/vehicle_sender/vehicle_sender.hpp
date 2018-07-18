#ifndef __VEHICLE_SENDER_HPP
#define __VEHICLE_SENDER_HPP

struct CommandData {
  double linear_x;
  double angular_z;
  int modeValue;
  int gearValue;
  int lampValue;
  int accellValue;
  int brakeValue;
  int steerValue;
  double linear_velocity;
  double steering_angle;

  void reset();
};

void CommandData::reset()
{
  linear_x      = 0;
  angular_z     = 0;
  modeValue     = 0;
  gearValue     = 0;
  lampValue     = 0;
  accellValue   = 0;
  brakeValue    = 0;
  steerValue    = 0;
  linear_velocity = -1;
  steering_angle = 0;
}

static CommandData command_data;

#endif
