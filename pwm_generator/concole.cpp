#include <Arduino.h>
#include "console.h"

#include "servo_ctrl.h"

uint8_t cons_data_cnt = 0;
uint8_t buf[MAX_DATA_LENGTH];

void console_sort(uint8_t *buf)
{
  const char * const divider = " ";
  char *dupstr = strdup(buf);
  char *CMD = NULL;
  char *Ch_str = NULL;

  CMD = strsep(&dupstr, divider);
  Ch_str = strsep(&dupstr, divider);

  if (strcmp(CMD, "CH") == 0)
  {
   uint8_t channel = atoi(Ch_str);
   uint16_t pwm =  atoi(dupstr);

   servo_set(channel,pwm);
  }

//  free(dupstr);
}

void console_parser(uint8_t data)
{
  //找到換行
  if (data == CONSOLE_LF)
  {
    //do some "things"
    //    Serial.write(buf,cons_data_cnt);
    console_sort(buf);


    //clear buffer and cnt
    memset( buf, 0, sizeof(buf));
    cons_data_cnt = 0;
    return;
  }

  buf[cons_data_cnt] = data;

  cons_data_cnt++;

  //buffer滿了
  if (cons_data_cnt >= MAX_DATA_LENGTH)
  {
    memset( buf, 0, sizeof(buf));
    cons_data_cnt = 0;
  }
  else
  {

  }
}

void console_init(void)
{


}

void console_loop(void)
{

  if (Serial.available())
  {

    console_parser(Serial.read());
  }
  else
  {
    //跳出
  }
}
