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
// myGpio.c or .h
// This module contains files necessary to blink LEDs as part of Lab 2
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/
#include <driverlib.h>
#include "stdio.h"
#include "string.h"

/***************************** Function Definition ***********************************/

void Init_GPIO(void) {
    // Configure P1.0 (red LED) and P9.7 (green LED) as output pins
    P1DIR |= BIT0;
    P9DIR |= BIT7;

}
