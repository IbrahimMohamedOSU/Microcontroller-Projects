//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Spring Semester 2020
// Instructor: Prof. Gregg Chapman
// Group # 40
// Raevin McQueen
// Austin Wilson
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.1.0
// MyGPio.c
// This module contains files necessary to MyGpio.c as part of Lab 2
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

void Init_GPIO() {
  P9DIR |= BIT7; // Set Green LED
    P9OUT |= BIT7; //Turn on Green LED

    P1DIR |= BIT0; // Set Red LED
    P1OUT &= ~(BIT0); //Turn off Red LED
}
/******************************** END OF CODE **********************************/
