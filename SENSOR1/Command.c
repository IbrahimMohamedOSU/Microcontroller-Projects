// ----------------------------------------------------------------------------
// main.c  (for myUart project) ('FR6989 Launchpad)
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>
#include <ECE3567.h>
#include "stdio.h"
#include "string.h"

//***** Global Variables ******************************************************
// All globals have been moved to 3567.h  NO EXTERNS NECESSARY
/**********************************************************************/

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


void parse_Command()
{
	 if(val[0] == L)				// LED Test Mode Commands
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
     if(Command == NULL)
     {
         myUart_writeBuf( BACKCHANNEL_UART, "UNKNOWN COMMAND ", NULL, CRLF );
         New_Data=0;
         myUart_writeBuf( BACKCHANNEL_UART, "", NULL, CRLF );
      }
     if(length >=5)
     {
        New_Data = 0;
        New_Data = (val[2]-48)*100 + (val[3]-48)*10 + (val[4]-48);
        length = 2;
        val[2]=0;
        val[3]=0;
        val[4]=0;
     }


    /************************************************** Act on the Command *************************************************/

    switch(Command)
    {
    		case LE:                    // Enable RGB LED
                LED_Test_Mode = TRUE;
                RC_Voltage_Mode = FALSE;
                Temp_Mode = FALSE;
                PWM_null();
                clearLCD();
                Flash = FALSE;
                LED_Color = No_Color;
                break;
            case LH:                    // Hot!  Flash LED Red
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Red;
                    Flash = TRUE;
                }
                break;
            case LR:                    // Red
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Red;
                    Flash = FALSE;
                }
                   break;
            case LO:                    // Orange
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Orange;
                    Flash = FALSE;
                }
                break;
            case LY:                    // Yellow
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Yellow;
                    Flash = FALSE;
                }
                break;
            case LG:                    // Green
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Green;
                    Flash = FALSE;
                }
                break;
            case LB:                    // Blue
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Blue;
                    Flash = FALSE;
                }
                break;
            case LV:                    // Violet
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Violet;
                    Flash = FALSE;
                }
                break;
            case LC:                    // COLD! Flash Purple
                if(LED_Test_Mode == TRUE)
                {
                    LED_Color = Violet;
                    Flash = TRUE;
                }
                break;
            case TE:                    // Enable Temperature Measurement
				Temp_Mode = TRUE;
				RC_Voltage_Mode = FALSE;
				LED_Test_Mode = FALSE;
				PWM_null();
				k=0;
				sum=0;
				deg = 0;
				break;
			case RE:                        // Enable RC Control
				Temp_Mode = FALSE;
				RC_Voltage_Mode = TRUE;
				LED_Test_Mode = FALSE;
				PWM_null();                 // Clear the current LED color
				TB0CCR5 =  0;  // Initial duty cycle for 1.65V
				k2=0;
				sum2=0;
				tempRC = 0;
				volts = 0;
				break;

			default:
				break;
    }
    Command = NULL;
    myUart_writeBuf( BACKCHANNEL_UART, "Please enter the next Command Code: ", NULL, CRLF );
    return;
}
/************************************************** END OF CODE *************************************************/




