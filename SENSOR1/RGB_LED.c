// ----------------------------------------------------------------------------
// RGB_LED.c  ('FR6989 Launchpad)
// Gregg Chapman, The Ohio State University, February 2018
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

// All globals have been moved to 3567.h  NO EXTERNS NECESSARY


/**********************************************************************/



void Init_PWM(void){

    unsigned int period  = 0x148;
    duty_cycle_red = 0x100;
    duty_cycle_green = 0x120;
    duty_cycle_blue = 0x120;

    P2DIR |= 0x04;              // Set P2.2 as an output
    P2SEL1 |= 0x04;             // Set P2.2 to SECONDARY OUTPUT, TB0.4, (10)
    P2SEL0 &= 0xFB;             // Set P2.2 to SECONDARY OUTPUT, TB0.4, (10)

    P3DIR |= 0xc0;              // Set P3.6 and P3.7 to output
    P3SEL1 |= 0xc0;             // Set P3.6 and P3.7  to SECONDARY OUTPUT, TB0.2 and TB0.3, (10)
    P3SEL0 &=0x3F;              // Set P3.6 and P3.7  to SECONDARY OUTPUT, TB0.2 and TB0.3, (10)

    TB0CCR0 = period;           // PWM Period
    TB0CTL = 0x0110;            // ACLK, up mode

    TB0CCTL2 = 0x00E0;          // CCR2 reset/set
    TB0CCR2 = duty_cycle_blue;  // CCR2 PWM duty cycle, TB0.2
    TB0CCTL3 = 0x00E0;          // CCR2 reset/set
    TB0CCR3 = duty_cycle_green; // CCR2 PWM duty cycle, TB0.3
    TB0CCTL4 = 0x00E0;          // CCR5 reset/set
    TB0CCR4 = duty_cycle_red;   // CCR5 PWM duty cycle, TB0.4
    LED_Color = White;

    return;
}



void update_RGB()
{


    {
        if(LED_Color == Red)                // Red.  Includes Flash
        {

            duty_cycle_red = 0x070;
            duty_cycle_green = 0x000;
            duty_cycle_blue = 0x000;

        }
        else if(LED_Color == Orange)    // Orange
        {
            duty_cycle_red = 0x0C4;     //FF
            duty_cycle_green = 0x024;   // 30
            duty_cycle_blue = 0x000;
        }
        else if(LED_Color == Yellow)    // Yellow
        {
            duty_cycle_red = 0x0C4;     //FF
            duty_cycle_green = 0x0AB;   // D7
            duty_cycle_blue = 0x000;
        }
        else if(LED_Color == Green)     // Green
        {
            duty_cycle_red = 0x000;     //FF
             duty_cycle_green = 0x0030;   // 30
             duty_cycle_blue = 0x000;
        }
        else if(LED_Color == Blue)      // Blue
        {
            duty_cycle_red = 0x000;
            duty_cycle_green = 0x000;
            duty_cycle_blue = 0x07A;
        }
        else if(LED_Color == Violet)    // Purple. Includes Flash
        {
            duty_cycle_red = 0x020;     // 020
            duty_cycle_green = 0x000;
            duty_cycle_blue = 0x07A;    //080
        }
        else if(LED_Color == White)      // Off
        {
            duty_cycle_red = 0x100;
            duty_cycle_green = 0x120;
            duty_cycle_blue = 0x120;
        }
        else if(LED_Color == No_Color)      // Off
        {
            duty_cycle_red = 0x000;
            duty_cycle_green = 0x000;
            duty_cycle_blue = 0x000;
        }
        else                            // LED OFF by default
        {
            duty_cycle_red = 0x000;
            duty_cycle_green = 0x000;
            duty_cycle_blue = 0x000;
        }

    }
    TB0CCR2 = duty_cycle_blue;   // CCR2 PWM duty cycle
    TB0CCR3 = duty_cycle_green;   // CCR2 PWM duty cycle
    TB0CCR4 = duty_cycle_red; // CCR5 PWM duty cycle
    return;
}

/*************************************** Turns off the LED ***********************************************/
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


/*********************************************** END OF CODE ******************************************/

