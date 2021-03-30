#include "console.h"
#include "servo_ctrl.h"

void setup()
{
  //Initial UART
  Serial.begin(115200);
  Serial.print("GGININ\n");

  servo_init();
}

void loop()
{
  console_loop();
  servo_process();
}
