#include <Servo.h>

Servo pwm_ch1;

int analog_ch1 = A1;
int analog_ch1_1 = A2;

uint16_t input[3];
uint16_t output[3];

void setup() 
{
  //initial ESC PWM output pin
  pwm_ch1.attach(2);

}

void loop() 
{
  //Read ADC
  input[0] = (analogRead(analog_ch1)+analogRead(analog_ch1_1))>>1;
  
  
  //Calculate output value
  output[0]=map(input[0],0,1023,1090,1900);
  
  //Output PWM
  pwm_ch1.writeMicroseconds(output[0]);
  
}
