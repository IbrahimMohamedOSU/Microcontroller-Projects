//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.0.1
// (Filename)Timers.c or .h
// This module contains files necessary to Initialize Timer A0 for Lab 9
// Timer A0 is used for a periodic interrupt. The PWM output for CCR1 is
// configured to be present on P1.6
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

/********************* Compiler Directives and Definitions **********************/


/******************************** Variables *************************************/

// Consider placing global variables in a header file, e.g. ECE3567.h

/*************************** Function Prototypes *******************************/
// Consider placing function prototypes in a header file, e.g. ECE3567.h


/***************************** First Function***********************************/

void Init_Timer_A0(void)
{
    //***********************  Configure Timer A0 for a 10 Hz interrupt ***************************
       TA0CTL = 0x0110;     // Set ACLK, UP MODE for Timer_0
      TA0CCTL0 |= CCIE;    // Enable interrupt for Timer_0 (0x0010)
      TA0CCTL1 = 0x04E0;   // CCR1 reset/set
      TA0CCR0 = 0x0CCE;    // for 10 Hz=100 ms and count is 3278
      TA0CCR1 = 0x0667;    // CCR1 PWM at 50 % duty cycle, on TA0.1

      return;
}

/****************************** Set up P1.6 for CCR1 Output (TA0.1)  ****************************/

void Init_PWM(void)
{
    P1DIR  |= BIT6;      // Set BIT6 (0x40) as an Output on Port 1
    P1SEL0 |= BIT6;      // Set BIT6 in both select registers
    P1SEL1 |= BIT6;      // is Tertiary is TA0.1 (CCR1) output on P1.6
    return;
}

/******************************** END OF CODE **********************************/
