#include <Arduino.h>
#include <Servo.h>

Servo CH[8];
uint16_t ch_us[8] = {1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050};

void servo_set(uint8_t channel, uint16_t input)
{
  if(channel >= 8)
  {
    return;
  }

  if(input >= 2500)
  {
    input = 2500;
  }
  ch_us[channel] = input;

  //Print Result
  Serial.print(" CH ");
  Serial.print(channel);
  Serial.print(" pwm ");
  Serial.print(ch_us[channel]);
  Serial.print("\n");
}

void servo_init(void)
{
    //initial ESC PWM output pin
  CH[0].attach(2);
  CH[1].attach(3);
  CH[2].attach(5);
  CH[3].attach(6);
  CH[4].attach(7);
  CH[5].attach(8);
  CH[6].attach(9);
  CH[7].attach(10);

  for (uint8_t i = 0; i<8 ; i++)
  {
    CH[i].writeMicroseconds(ch_us[i]);
  }
}

void servo_process(void)
{
  for (uint8_t i = 0; i<8 ; i++)
  {
    CH[i].writeMicroseconds(ch_us[i]);
  }
}
