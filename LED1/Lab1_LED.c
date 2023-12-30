//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.1.0
// Lab1_LED.c or .h
// This module contains files necessary to blink LEDs as part of Lab 1
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

/********************* Compiler Directives and Definitions **********************/


/******************************** Variables *************************************/

const unsigned long delay_count = 1000; // declaring delay variable


/*************************** Function Prototypes *******************************/

void delay(unsigned long delay_count);

/***************************** Function Definitions ***********************************/

void delay(unsigned long delay_count) {
    while (delay_count > 0) { // set loop for delay duration
        __delay_cycles(1000); // Delay for 1ms
        delay_count--;
    }
}

/***************************** Main Function ***********************************/
int main(void) {
    // Disable the watchdog timer and release all pins on MCU
    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);
    PMM_unlockLPM5();

    // Configure GPIO pins as outputs
    P1DIR |= BIT0; // RED LED (P1.0)
    P9DIR |= BIT7; // GREEN LED (P9.7)
    P9OUT |= BIT7;  // Turn ON the GREEN LED
    P1OUT &= ~BIT0; // Turn OFF the RED LED

    while (1) {

        delay(delay_count); // Delay for 1 second

        P9OUT ^= BIT7;  // Toggle the GREEN LED
        P1OUT ^= BIT0;  // Toggle the RED LED

    }

}
