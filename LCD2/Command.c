/*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Autumn Semester 2023
// Instructor: Prof. Gregg Chapman
// Group # 32
// Ibrahim Mohamed
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 12.4.0
// Command.c or .h
// This module contains files necessary to manipulate LEDs and LCD display as part of lab 5
// ----------------------------------------------------------------------------
/*******************************************************************************/
//***** Header Files **********************************************************
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"

//***** Global Variables ******************************************************


//*****************  Use the UART to R/W from the "Dumb Terminal"  *********************************

void Command_Handler(uint16_t length)
{
    length = Full_Array;   //DEFAULT size which means use the full array
    // Read a character from the terminal (we don't validate it's between 1 and 5)
    myUart_readBuf( BACKCHANNEL_UART, (unsigned char *)val, &length );
    myUart_writeBuf( BACKCHANNEL_UART, "", NULL, CRLF );
    myUart_writeBuf( BACKCHANNEL_UART, "Command: ", NULL, CRLF );
    myUart_writeBuf( BACKCHANNEL_UART, (unsigned char *)val,length,CRLF);
    length = 2;
    Command_Flag = 0;
    EUSCI_A_UART_clearInterrupt( EUSCI_A1, EUSCI_A_UART_RECEIVE_INTERRUPT);
    EUSCI_A_UART_enableInterrupt( EUSCI_A1, EUSCI_A_UART_RECEIVE_INTERRUPT);
    return;
}


//*******************************  Decode the Command  ********************************************
void parse_Command()
{


/*********************** 1) Read in 2 Letter Command *********************/

    // loops for commands with the first letter 'L'
    if(val[0] == L)
    {
    if(val[1] == E )
        Command = LE;
    else if(val[1] == H)
        Command = LH;
    else if(val[1] == R)
        Command = LR;
    else if(val[1] == O)
        Command = LO;
    else if(val[1] == Y)
        Command = LY;
    else if(val[1] == G)
        Command = LG;
    else if(val[1] == B)
        Command = LB;
    else if(val[1] == V)
        Command = LV;
    else if(val[1] == C)
        Command = LC;
    }

    // loops for RE and TE commands
    else if(val[0] == R)
    {
         if(val[1] == E )
        Command = RE;
    }
    else if(val[0] == T)
    {
        if(val[1] == E )
        Command = TE;
    }

    else
      {
            Command = NULL;
              myUart_writeBuf( BACKCHANNEL_UART, "UNKNOWN COMMAND ", NULL, CRLF );
              myUart_writeBuf( BACKCHANNEL_UART, "", NULL, CRLF );
              // Ask for the next Command
      }

    /*********************** 2) If there is Data Load up to a 4-digit number,  CLEAR BUFFER  *********************/

    if(length >=5)
    {
        New_Data = 0;
        New_Data = (val[2]-48)*1000 + (val[3]-48)*100 + (val[4]-48)*10 + (val[5]-48);

  /*********************************** 3) Clear the val[] array ********************************************/
        length = 2;
        val[2]=0;
        val[3]=0;
        val[4]=0;
        val[5]=0;
    }
    /************************************* 4) Act on the Command *************************************************/

    switch(Command)
    {

    	case LE:                    // Act on Command LE
    	    // enable LED test mode and disable all other modes
    	    Temp_Mode = FALSE;
    	    RC_Voltage_Mode = FALSE;
    	    Flash = FALSE;
    	    LED_Test_Mode = TRUE;
    	    // reset the values
    	    clearLCD();
    	    PWM_null();
    	    LED_Color = No_Color;

        break;

        case LH:                    // Act on Command LH, Hot!  Flash LED Red
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Red;
                Flash = TRUE;
            }

                break;

        case LR:                    // Act on Command LR, Red
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Red;
                Flash = FALSE;
            }
               break;

        case LO:               // Act on Command LO, Orange
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Orange;
                Flash = FALSE;
            }
                break;

        case LY:               // Act on Command LY, Yellow
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Yellow;
                Flash = FALSE;
            }
                break;

        case LG:               // Act on Command LG, Green
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Green;
                Flash = FALSE;
            }
                break;

        case LB:               // Act on Command LB, Blue
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Blue;
                Flash = FALSE;
            }
                break;

        case LV:               // Act on Command LV, Violet
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Violet;
                Flash = FALSE;
            }
                break;

        case LC:                    // Act on Command LC, COLD! Flash Purple
            if(LED_Test_Mode == TRUE)
            {
                LED_Color = Violet;
                Flash = TRUE;
            }

               break;

        case RE:                    // Act on Command RE, RC voltage mode, 2.50V
            // enable RC Voltage mode and disable all other modes
                Temp_Mode = FALSE;
                RC_Voltage_Mode = TRUE;
                Flash = FALSE;
                LED_Test_Mode = FALSE;
                // reset the values
                clearLCD();
                PWM_null();
                LED_Color = No_Color;
                // set voltage to 2.5 and display it
                volts = 2500;
                displayVolts();
          	   break;

        case TE:                    // Act on Command TE, Temperature mode, 75.0F
            // enable Temperature mode and disable all other modes
                Temp_Mode = TRUE;
                RC_Voltage_Mode = FALSE;
                Flash = FALSE;
                LED_Test_Mode = FALSE;
                // reset the values
                clearLCD();
                PWM_null();
                LED_Color = No_Color;
                // set temperature to 75 degrees and display it
                deg = 750;
                displayTemp();
          	   break;

        default:
                break;
    }
    /******************************************** Clear Command and Ask for the next one ********************/
    Command = NULL;
    myUart_writeBuf( BACKCHANNEL_UART, "Please enter the next Command Code: ", NULL, CRLF );
}


/************************************************** END OF CODE *************************************************/




