/*
 *  Copyright (c) 2015, Nagoya University
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither the name of Autoware nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>

#include "vehicle_sender.hpp"

#define CUS_CTRL_1_ID 0x101

static int alive = 0;

std::string packageCommand(struct CommandData command_data)
{
  std::ostringstream oss;
  int str_accel_auto = 0x03;
  int msg_id = CUS_CTRL_1_ID;

  /*
   * Frame Format:
   *
   * Message ID, Alive Bit, Steer Value, Accel Value, Res, Res, Res, Steer Accel Automation
   */
  
  oss << msg_id << ",";
  oss << alive << ",";
  oss << command_data.steerValue << ",";
  oss << command_data.accellValue << ",";
  oss << 0 << ",";
  oss << 0 << ",";
  oss << 0 << ",";
  oss << str_accel_auto ;

  std::string cmd(oss.str());

  alive++;

  // Wrap around to 0 after reaching 255
  if (alive > 255)
    alive = 0

  return cmd;
}
