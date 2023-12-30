/*******************************************************************************/
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
// (Timer).c
// This module contains files necessary to Timer.c as part of Lab 2
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include <ECE3567.h>
#include "stdio.h"
#include "string.h"

/********************* Compiler Directives and Definitions **********************/


/******************************** Variables *************************************/
// Consider placing global variables in a header file, e.g. ECE3567.h

/*************************** Function Prototypes *******************************/
// Consider placing function prototypes in a header file, e.g. ECE3567.h


/***************************** First Function***********************************/
void Init_Timer_A0(){
    TA0CTL = 0X0110;
    TA0CCTL0 |= CCIE;
    TA0CCTL1 = 0X00E0;
    TA0CCR0 = 0x0CCE;
    TA0CCR1 = 0x0667;
}

