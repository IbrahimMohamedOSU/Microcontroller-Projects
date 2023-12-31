# Microcontroller-Projects
A collection of my microcontroller-based projects. Completed using a combination of C and assembly language.
These programs were designed for and tested on a MSP430FR6989 microcontroller. 

Project Descriptions:

LCD1 - a program that utilizes a function (Display.c, implemented with modulo division) to display the first 6 letters of my name on the microcontroller LCD. 

LCD2 - a program that employs UART serial communication commands to allow a user to modify the temperature, voltage level, LEDs, LCD, and outputs of a microcontroller. The chosen temperature and voltage level is shown on the LCD.

LED1 - a program that will illuminate the red and green LEDs on the MSP430FR6989 Launchpad board.
• The illumination alternates between LEDs at approximately one second intervals.
• This project does not use timers or interrupts. Instead, I wrote a delay function and call it in
the main loop for the 1 second delay.

LED2 - a program that will illuminate the red and green LEDs on the MSP430FR6989 Launchpad board.
• The illumination alternates between LEDs at approximately one second intervals.
• This project does utilize timers and interrupts to achieve the desired outcome. 

LED3 - a program that utilizes a 7-state state machine that ramps pulse widths in modulation to achieve a smooth transition between colors. There are 7 colors in total, and each one is illuminated on the microcontroller at a frequency of 1 Hz. 

SENSOR1 - a program that:
1. Utilizes a TWO channel conversion sequence, one channel for the RC_Voltage, and a second channel for the internal Temperature Sensor.
2. Displays the temperature in Fahrenheit on the Liquid Crystal Display.
3. Uses a channel (PWM) and ramps the RC Voltage by incrementing the duty cycle from 0-100%.
4. Displays the RC Voltage on the Liquid Crystal Display
5. Configures main() to switch between the Temperature Sensor, RC_Voltage, and LED Test
Mode using TE, RE, and LE commands.

SENSOR2 - this program is a continuation of SENSOR1 and implements the following modifications:
1) Flash additions to main() results in 4Hz flash when temp is <67F or >79F.
2) Modified and added UART commands for TE, TC, TF, TS, TT, and TK.
3) Color mapping for temperature ranges in update_RGB().
4) tempSensorModeInit() has added the heating element initialization.

SENSOR3 - this program is a continuation of SENSOR2 and implements the following modifications:
1) The RE Command results in a stable 1.65V output on the LED Display, and the LED remains Green.
2) The RS Command is parse correctly, and the RC Voltage controller converges.
3) The controller converges to all set point values between 0.25 volts and 3.25 volts in 9 iterations or less.
4) The controller keeps the output voltage within the GREEN LED range, once the algorithm has converged.

TimerA - Part 1 of a 2-part project. a program that uses the Watchdog timer to illuminate the red and green LEDs at a frequency of 1 Hz.

TimerB - Part 2 of a 2-part project. a program that uses Interval Timer Mode to illuminate the red and green LEDs at a frequency of 1 Hz.
