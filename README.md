# RCTool_PWM_Generator
Generate RC(Remote control) PWM signal by Arduino board that can provide PWM signal to control servo motor or ESC, etc.

This project provide 8 channel output and 1 Serial port for input.

# Usage
Send `CH ? width\n` to serial 1  
- `?` mean the channel number  
- `width` mean pwm width in us, ex: 1500
- `\n` carriage return is necessary for indicator

# Example 
Send `CH 0 1500\n` to serial 1 @ 115200:8:n:1
