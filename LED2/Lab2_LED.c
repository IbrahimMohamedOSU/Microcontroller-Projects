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
// Lab2_LED.c or .h
// This module contains files necessary to blink LEDs as part of Lab 2
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

/******************************** Variables *************************************/
volatile unsigned int ISR_Counter; // Used to count to 10 in order to delay exactly 1 second
volatile unsigned char ISR_Flag = 0; // Flag to tell main() that a Timer A0 interrupt occurred
volatile unsigned char ISR_Flag_10 = 0; // Flag to tell main() that a Timer A0 interrupt occurred 10 times


/***************************** Main Function ***********************************/
void main (void) {
    // Initializations go here including Init_GPIO(), Init_Timer_A0(), etc
    // Disable the watchdog timer and release all pins on MCU
        WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);
        PMM_unlockLPM5();

        Init_GPIO();    // Configure GPIO pins as outputs
        Init_Timer_A0();    // Configure the control and compare registers

        P9OUT |= BIT7;  // Turn ON the GREEN LED
        P1OUT &= ~BIT0; // Turn OFF the RED LED

        __enable_interrupt(); // enable all configured interrupts

    while(1) {
        if(ISR_Flag==1) // Timer A0 has occurred.
        {
            ISR_Flag = 0;
        }
        if(ISR_Flag_10 ==1) // 1 Sec interval
        {
            ISR_Flag_10 = 0;
            // MOVE YOUR LED XORs HERE
            P9OUT ^= BIT7;  // Toggle the GREEN LED
            P1OUT ^= BIT0;  // Toggle the RED LED
            }
        }
   }

/***************************** Interrupt Service Routine ***********************************/
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
    {

    // Set the ISR_Flag to 1
        ISR_Flag = 1;

        // Increment the ISR_Counter
        ISR_Counter++;

        // Check if ISR_Counter is greater than or equal to 10
        if (ISR_Counter >= 10) {
            // Set the ISR_Flag_10
                    ISR_Flag_10 = 1;

            // Reset ISR_Counter to 0
            ISR_Counter = 0;
        }

return;
    }

/***************************** END OF CODE ***********************************/
