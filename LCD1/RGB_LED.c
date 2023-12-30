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
// RGB_LED.c or .h
// This module contains files necessary to manipulate an LCD display as part of Lab 4
// ----------------------------------------------------------------------------
/*******************************************************************************/
//***** Header Files ***********************************************************/
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"
#define step_size 2




/******************************** Variables *************************************/
unsigned int red_count;
volatile short LED_Color;


/***************************** Function Definitions ***********************************/

void Init_PWM(void) {
    State = 1;
    red_count = 0;
    LED_Color = Red;

        // set values to produce pure WHITE light (PART 1)
       //  duty_cycle_blue = 0x0070;
       //  duty_cycle_green = 0x004A;
       //  duty_cycle_red = 0x0070;

        // set values for PART 2 and 3
           duty_cycle_blue = 0x0000;
           duty_cycle_green = 0x0000;
           duty_cycle_red = 0x0070;

        // Set the pin direction to output for the relevant pins
            P3DIR |= BIT6; // P3.6 (Blue)
            P3DIR |= BIT7; // P3.7 (Green)
            P2DIR |= BIT2; // P2.2 (Red)

      // Configure the pin function as SECONDARY
            P3SEL1 |= BIT6; // P3.6 (Blue)
            P3SEL0 &= ~BIT6;
            P3SEL1 |= BIT7; // P3.7 (Green)
            P3SEL0 &= ~BIT7;
            P2SEL1 |= BIT2; // P2.2 (Red)
            P2SEL0 &= ~BIT2;

          // initialize TA0CTL to the correct hexadecimal value
          // Timer B0 control register
          TB0CTL = 0x0110;

          // Enable the Comparator 0 interrupt for Timer B0 by setting CCIE bit
          TB0CCTL0 = CCIE; // 0x0010

          // Set Comparator Control Registers
          TB0CCTL2 = 0x00E0;
          TB0CCTL3 = 0x00E0;
          TB0CCTL4 = 0x00E0;

          // Set Comparator Registers
          TB0CCR0 = 0x00D0;

          TB0CCR2 = duty_cycle_blue;
          TB0CCR3 = duty_cycle_green;
          TB0CCR4 = duty_cycle_red;

}


// PART 2
//void update_RGB(void) {
//      // a 7-state machine that smoothly transitions through each color
//    switch (State) {
//                case 1:
//                    red_count++;
//                    if (red_count >= 15) {
//                        red_count = 0;
//                        State = 2;
//                    }
//                    break;
//
//                  // loop for orange state
//                case 2:
//                    if (duty_cycle_green < MAX_Green) {
//                        duty_cycle_green += step_size;
//                    } else {
//                        State = 3;
//                    }
//                    break;
//
//                  // loop for yellow state
//                case 3:
//                    if (duty_cycle_red >= step_size) {
//                        duty_cycle_red -= step_size;
//                    } else {
//                        State = 4;
//                    }
//                    break;
//
//                    // loop for green state
//                case 4:
//                    if (duty_cycle_blue < MAX_Blue) {
//                        duty_cycle_blue += step_size;
//                    } else {
//                        State = 5;
//                    }
//                    break;
//
//                  // loop for blue state
//                case 5:
//                    if (duty_cycle_green >= step_size) {
//                        duty_cycle_green -= step_size;
//                    } else {
//                        State = 6;
//                    }
//                    break;
//
//                  // loop for violet state
//                case 6:
//                    if (duty_cycle_red < MAX_Red) {
//                        duty_cycle_red += step_size;
//                    } else {
//                        State = 7;
//                    }
//                    break;
//
//                  // loop for red state
//                case 7:
//                    if (duty_cycle_blue >= step_size) {
//                        duty_cycle_blue -= step_size;
//                    } else {
//                        State = 1;
//                    }
//                    break;
//        }
//
//
//
//        TB0CCR2 = duty_cycle_blue;
//        TB0CCR3 = duty_cycle_green;
//        TB0CCR4 = duty_cycle_red;
//        return;
//}

// PART 3
// a 7-state machine that transitions through each color
void update_RGB(void) {

    LED_Color++; // Change color
    if(LED_Color > White) {// Loop back to Red from White
    LED_Color = Red;
}

switch(LED_Color){
        case Red:
            duty_cycle_red = 0x0070;
            duty_cycle_green = 0x0000;
            duty_cycle_blue = 0x0000;
            break;

        case Orange:
            duty_cycle_red = 0x00C4;
            duty_cycle_green = 0x0024;
            duty_cycle_blue = 0x0000;
            break;

        case Yellow:
            duty_cycle_red = 0x00C4;
            duty_cycle_green = 0x00AB;
            duty_cycle_blue = 0x0000;
            break;

        case Green:
            duty_cycle_red = 0x0000;
            duty_cycle_green = 0x004A;
            duty_cycle_blue = 0x0000;
            break;

        case Blue:
            duty_cycle_red = 0x0000;
            duty_cycle_green = 0x0000;
            duty_cycle_blue = 0x007A;
            break;

        case Violet:
            duty_cycle_red = 0x0026;
            duty_cycle_green = 0x0000;
            duty_cycle_blue = 0x007A;
            break;

        case White:
            duty_cycle_red = 0x0070;
            duty_cycle_green = 0x004A;
            duty_cycle_blue = 0x0070;
            break;

        case No_Color:
            duty_cycle_red = 0x0000;
            duty_cycle_green = 0x0000;
            duty_cycle_blue = 0x0000;
            break;

        default:
            duty_cycle_red = 0x0000;
            duty_cycle_green = 0x0000;
            duty_cycle_blue = 0x0000;
            break;

    }

TB0CCR2 = duty_cycle_blue;
TB0CCR3 = duty_cycle_green;
TB0CCR4 = duty_cycle_red;
return;

}

void PWM_null(void) {
    // clear all CCR duty cycle registers and duty_cycle_xxxx variables.
    TB0CCR2 = 0;
    TB0CCR3 = 0;
    TB0CCR4 = 0;

    duty_cycle_red = 0;
    duty_cycle_green = 0;
    duty_cycle_blue = 0;

    return;
}


