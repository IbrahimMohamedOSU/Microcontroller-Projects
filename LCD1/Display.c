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
// Display.c or .h
// This module contains files necessary to manipulate an LCD display as part of lab 4
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/

#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

/******************************** Variables *************************************/
volatile unsigned int display_number = 8765;
volatile char Str[6] = {'I', 'B', 'R', 'A','H', 'I'};
volatile unsigned int n = sizeof(Str);

/***************************** Function Definitions ***********************************/
void displayNumber(unsigned int display_number)
{

    unsigned int num;
    char val;
    num = display_number;
    clearLCD();

        // display thousands digit
        if (num >= 1000) {
            val = (num / 1000) + '0';
        showChar(val, pos1);
        }

        if (num >= 100) {
        // display hundreds digit
            val = ((num / 100) % 10) + '0';
        showChar(val, pos2);
        }

        if (num >= 10) {
        // display tens digit
            val = ((num / 10) % 10) + '0';
        showChar(val, pos3);
        }

        if (num >= 1) {
        // display units digit
            val = (num % 10) + '0';
        showChar(val, pos4);
        }

return;

}

void displayString(char *Str, unsigned int n)
{
    unsigned char i;
    char j;
    unsigned int k;
    unsigned int position[6] = {pos1,pos2,pos3,pos4,pos5,pos6};

    clearLCD();

    // loop through string and display each letter
    for (i = 0; i < n; i++) {
            showChar(Str[i], position[i]);
        }




return;
}











