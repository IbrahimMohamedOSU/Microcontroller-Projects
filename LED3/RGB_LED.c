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
// This module contains files necessary to Main.c  as part of Lab 2
// ----------------------------------------------------------------------------

#include <driverlib.h>
#include <ECE3567.h>
#include "stdio.h"
#include "string.h"

unsigned int red_count = 0;
unsigned int step_size = 2;

//Part 1
void Init_PWM(void){

//    duty_cycle_red = 0x007A;
//    duty_cycle_green = 0x004A;
//    duty_cycle_blue = 0x0070;

    duty_cycle_red = 0x0070;
    duty_cycle_green = 0x0000;
    duty_cycle_blue = 0x0000;

    TB0CCR0 = RGB_Period;

    P3DIR |= BIT6;
    P3DIR |= BIT7;
    P2DIR |= BIT2;

    P3SEL1 |= BIT6;
    P3SEL1 |= BIT7;
    P3SEL1 |= BIT2;


    P3SEL0 &= ~(BIT6);
    P3SEL0 &= ~(BIT7);
    P3SEL0 &= ~(BIT2);

    TB0CTL = 0X0110;
    TB0CCTL2 = 0x00E0;
    TB0CCTL3 = 0x00E0;
    TB0CCTL4 = 0x00E0;

    TB0CCR2 = duty_cycle_blue;
    TB0CCR3 = duty_cycle_green;
    TB0CCR4 = duty_cycle_red;

    State = 1;
    LED_Color = Red;
}
//Part 2
//void update_RGB(void){
//        switch(State){
//        case 1:
//            red_count++;
//            if(red_count >= 15){
//                red_count = 0;
//                State = 2;
//            }
//            break;
//
//        case 2:
//            if(duty_cycle_green < MAX_Green){
//                duty_cycle_green += step_size;
//            } else{
//                State = 3;
//            }
//            break;
//
//        case 3:
//            if(duty_cycle_red > step_size){
//                duty_cycle_red -= step_size;
//            } else{
//                State = 4;
//            }
//            break;
//
//        case 4:
//            if(duty_cycle_blue < MAX_Blue){
//                duty_cycle_blue += step_size;
//            } else {
//                State = 5;
//            }
//        case 5:
//            if(duty_cycle_green > step_size){
//                duty_cycle_green -= step_size;
//            } else{
//                State = 6;
//            }
//            break;
//
//        case 6:
//            if(duty_cycle_red < MAX_Red){
//                duty_cycle_red += step_size;
//            } else {
//                State = 7;
//            }
//            break;
//
//        case 7:
//            if(duty_cycle_blue >step_size){
//                duty_cycle_blue -= step_size;
//            } else{
//                State = 1;
//            }
//            break;
//        }
//
//        TB0CCR2 = duty_cycle_blue;
//        TB0CCR3 = duty_cycle_green;
//        TB0CCR4 = duty_cycle_red;
//        return;
//
//}

//Part 3
void update_RGB(void){
    LED_Color++;
    if(LED_Color > White){
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
            duty_cycle_red = 0x006A;
            duty_cycle_green = 0x004A;
            duty_cycle_blue = 0x0065;
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

}



