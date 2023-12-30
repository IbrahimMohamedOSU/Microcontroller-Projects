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
// Lab4_main.c or .h
// This module contains files necessary to manipulate an LCD display as part of lab 4
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"



/******************************** Variables *************************************/
extern volatile unsigned int display_number;
extern volatile char Str[6];
extern volatile unsigned int n;



/***************************** Main Function ***********************************/
void main (void) {
    // Initializations go here including Init_GPIO(), Init_Timer_A0(), etc
    // Disable the watchdog timer and release all pins on MCU
        WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);
        PMM_unlockLPM5();

        Init_GPIO();        // Lab 1
        Init_Timer_A0();    // Lab 2
        Init_PWM();     //  Lab 3
        Init_LCD();     // Lab 4

        displayString(Str,n);   // checkpoint 2 lab 4

        __enable_interrupt(); // enable all configured interrupts

        while(1) {
            if(ISR_Flag==1) // Timer A0 has occurred.
                   {
                       ISR_Flag = 0;
            //  update_RGB();  // PART 2 (lab 3)

                   }
                   if(ISR_Flag_10 ==1) // 1 Sec interval
                   {

                    //   update_RGB();  // PART 3 (lab 3)

                    //   displayNumber(display_number); // checkpoint 1 lab 4
                    //   display_number++;  // checkpoint 1 lab 4


                       P9OUT ^= BIT7;  // Toggle the GREEN LED
                       P1OUT ^= BIT0;  // Toggle the RED LED
                       ISR_Flag_10 = 0;
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
            }

/***************************** END OF CODE ***********************************/
