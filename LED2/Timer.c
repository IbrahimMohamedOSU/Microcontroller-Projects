//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 12.4.0
// Timer.c or .h
// This module contains files necessary to blink LEDs as part of Lab 2
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/
#include <driverlib.h>
#include "stdio.h"
#include "string.h"

/***************************** Function Definition ***********************************/

void Init_Timer_A0(void) {

        // initialize TA0CTL to the correct hexadecimal value
        TA0CTL = 0x0110;

        // Enable the Comparator 0 interrupt for Timer A0 by setting CCIE bit
        TA0CCTL0 = 0x0010;

        // Set Reset/Set mode in the OUTMOD field (OUTMOD=111)
        TA0CCTL1 = 0x00E0;

        // Set the TA0CCR0 Comparator Register for a 10 Hz frequency
        TA0CCR0 = 0x0CCE;

        // Set the TA0CCR1 Comparator Register for a 50% duty cycle
        TA0CCR1 = 0x0667;

}
