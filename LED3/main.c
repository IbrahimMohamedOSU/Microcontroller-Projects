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
// main.c
// This module contains files necessary to Main.c  as part of Lab 3
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

 volatile unsigned int ISR_Counter;     // Used to count to 10 in order to delay exactly 1 sec
 volatile unsigned char ISR_Flag=0;      // Flag to tell main() That a Timer A0 interrupt occurred
 volatile unsigned char ISR_Flag_10=0;   // Flag to tell main() That a Timer A0 interrupt occurred 10 times

void main(void) {

    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__); //Disable watchdog timer
    PMM_unlockLPM5();                         //Release pins on all MCU

    Init_GPIO();
    Init_Timer_A0();
    Init_PWM();
    __enable_interrupt();

    State = 1;
    while(1){
      if(ISR_Flag==1) //Timer A0 has occurred
            {
              //Part 2
//                update_RGB();
                ISR_Flag=0;
            }
            if(ISR_Flag_10==1)
            {
                //Part 3
                update_RGB();
                P1OUT ^= BIT0; //Toggle Red LED
                P9OUT ^= BIT7; //Toggle Green LED
                ISR_Flag_10=0;
            }
    }
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
  ISR_Flag = 1;
  ISR_Counter ++;

      if(ISR_Counter >= 10)
      {
          ISR_Flag_10 =1; //Set ISR Flag
          ISR_Counter =0; // Reset ISR Counter
      }
      return;
}

