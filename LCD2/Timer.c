/*
 * Timer.c
 *
 *  Created on: Feb 14, 2020
 *      Author: gchap
 */

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"
void Init_Timer_A0(void)
{
//***********************  Configure Timer A0 for a 10 Hz interrupt ***************************//
      TA0CCR0 = 0x0CCE;    // for 10 Hz=100 ms and count is 3278
      TA0CTL = 0x0110;    // Set ACLK, UP MODE for Timer_0
      TA0CCTL0 |= CCIE;   // Enable interrupt for Timer_0
      TA0CCTL1 = 0x04E0;  // CCR1 reset/set
      TA0CCR1 = 0x0667;    // CCR1 PWM at 50 % duty cycle, on TA0.1
      P1DIR  |= 0x40;
      P1SEL0 |=0x40;
      P1SEL1 |= 0x40;
      return;
}
/******************************* END of CODE ********************************/
