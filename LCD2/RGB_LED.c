/*******************************************************************************/
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 12.4.0
// RGB_LED.c or .h
// This module contains files necessary to manipulate an LCD display as part of lab 5
//*******************************************************************************

//*************************************** Header Files ********************************************
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"



/**********************************************************************/

void Init_PWM(void){

    duty_cycle_red= 0x00B0;          // WHITE LED
    duty_cycle_green= 0x0090;
    duty_cycle_blue= 0x00D0;


    P2DIR |= 0x04;              // Set P2.2  to output
    P2SEL1 |= 0x04;             // Set P2.2 to SECONDARY OUTPUT, TB0.4, (10) RED
    P2SEL0 &= 0xFB;             // Set P2.2 to SECONDARY OUTPUT, TB0.4, (10)

    P3DIR |= 0xc0;              // Set P3.6 and P3.7 to output
    P3SEL1 |= 0xc0;             // Set P3.6 and P3.7  to SECONDARY OUTPUT, TB0.2 and TB0.3, (10)
    P3SEL0 &=0x3F;              // Set P3.6 and P3.7  to SECONDARY OUTPUT, TB0.2 and TB0.3, (10)

    TB0CCR0 = RGB_Period;       // PWM Period
    TB0CTL = 0x0110;            // ACLK, up mode
    TB0CCTL2 = 0x00E0;          // CCR2 reset/set
    TB0CCR2 = duty_cycle_blue;  // CCR2 PWM duty cycle, TB0.2
    TB0CCTL3 = 0x00E0;          // CCR2 reset/set
    TB0CCR3 = duty_cycle_green; // CCR2 PWM duty cycle, TB0.3
    TB0CCTL4 = 0x00E0;          // CCR5 reset/set
    TB0CCR4 = duty_cycle_red;   // CCR5 PWM duty cycle, TB0.4
    LED_Color = Violet;
    return;
}

/**************************** Lab #3 Part 3 ***************************/

void update_RGB()
{
//    LED_Color++;
//    if(LED_Color > White)
//        LED_Color = Red;
     switch(LED_Color)
              {
            case Red:                       //  Red element only
                duty_cycle_red = 0x070;
                duty_cycle_green = 0x000;
                duty_cycle_blue = 0x000;
            break;

            case Orange:                    // Green and Red can make Orange
                duty_cycle_red = 0x0C4;
                duty_cycle_green = 0x024;
                duty_cycle_blue = 0x000;
                break;

            case Yellow:                    //  Green and Red make Yellow too!
              duty_cycle_red = 0x0C4;
               duty_cycle_green = 0x0AB;
                duty_cycle_blue = 0x000;
                break;

            case Green:                     // Green element only
                duty_cycle_red = 0x000;
                duty_cycle_green = 0x04A;
                duty_cycle_blue = 0x000;
                break;

           case Blue:                      // Blue element only
               duty_cycle_red = 0x000;
                duty_cycle_green = 0x000;
                duty_cycle_blue = 0x07A;
               break;
             case Violet:                   // Red and Blue make Purple
                duty_cycle_red = 0x026;
                duty_cycle_green = 0x000;
                duty_cycle_blue = 0x07A;
                break;

             case White:                   // Turn off LED
                duty_cycle_red = 0x0D0;
                duty_cycle_green = 0x00B0;
                duty_cycle_blue = 0x00A0;
                break;

             case No_Color:                   // Turn off LED
                duty_cycle_red = 0x000;
                duty_cycle_green = 0x000;
                duty_cycle_blue = 0x000;
                break;

             default:                    // Turn off LED
                duty_cycle_red = 0x000;
                duty_cycle_green = 0x000;
                duty_cycle_blue = 0x000;
                break;

                }
    TB0CCR2 = duty_cycle_blue;   // CCR2 PWM duty cycle
    TB0CCR3 = duty_cycle_green;   // CCR2 PWM duty cycle
    TB0CCR4 = duty_cycle_red; // CCR5 PWM duty cycle
    return;
    }
///********************************************************************************************/
void PWM_null()
{
    duty_cycle_red = 0x000;
    duty_cycle_green = 0x000;
    duty_cycle_blue = 0x000;
    TB0CCR2 = 0000;   // CCR2 PWM duty cycle
    TB0CCR3 = 0000;   // CCR2 PWM duty cycle
    TB0CCR4 = 0000; // CCR5 PWM duty cycle
    return;
}
//************************************************** END OF CODE **********************************

