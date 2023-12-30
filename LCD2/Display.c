// ----------------------------------------------------------------------------
/*******************************************************************************/
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 12.4.0
// Display.c or .h
// This module contains files necessary to manipulate LEDs and LCD display as part of lab 5
//*******************************************************************************

//*************************************** Header Files ********************************************
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"



void displayString(char *Str, unsigned int n)
{
    unsigned char i;
    int k;
    char j;
    unsigned int position[6] = {pos1,pos2,pos3,pos4,pos5,pos6};

    clearLCD();
    for(i=0;i<n;i++)
    {
        j  = Str[i];
        k = position[i];
        showChar(j, k);

        }
        return;
}

void displayNumber(unsigned int display_number)
{

    clearLCD();

    // Decimal point
//    LCDMEM[pos3+1] |= 0x01;
    return;
}

void displayTemp() {

    unsigned int num;
    num = deg;
    char val;
    clearLCD();

        // display thousands digit
        if (num >= 1000) {
        val = (num / 1000) + '0';
        showChar(val, pos2);
        }

        // display hundreds digit
        if (num >= 100) {
        val = ((num / 100) % 10) + '0';
        showChar(val, pos3);
        }

        // display tens digit
        if (num >= 10) {
        val = ((num / 10) % 10) + '0';
        showChar(val, pos4);
        }

        // display units digit
        if (num >= 1) {
        val = (num % 10) + '0';
        showChar(val, pos5);
        }

    showChar('F',pos6);
    // Decimal point
    LCDMEM[pos4+1] |= 0x01;
    // Degree symbol
    LCDMEM[pos5+1] |= 0x04;
    return;
}

void displayVolts() {

    unsigned int num;
    num = volts;
    char val;
    clearLCD();

        // display thousands digit
        if (num >= 1000) {
        val = (num / 1000) + '0';
        showChar(val, pos3);
        }

        // display hundreds digit
        if (num >= 100) {
        val = ((num / 100) % 10) + '0';
        showChar(val, pos4);
        }

        // display tens digit
        if (num >= 10) {
        val = ((num / 10) % 10) + '0';
        showChar(val, pos5);
        }

        // Decimal point
        LCDMEM[pos3+1] |= 0x01;
        showChar('V', pos6);
        return;
}
