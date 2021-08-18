/********************************************************************/
 /******************************************************************/
 /* 		Title : KEYPAD Program File                            */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 18 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_private.h"

#include <avr/delay.h>  //for delay

void KEYPAD_void_Init(void)
{
	#if KEYPAD_u8_MODE == KEYPAD_u8_IN_PULL
	DIO_void_SetPinValue(KEYPAD_u8_R1, DIO_u8HIGH);
	DIO_void_SetPinValue(KEYPAD_u8_R2, DIO_u8HIGH);
 	DIO_void_SetPinValue(KEYPAD_u8_R3, DIO_u8HIGH);
	DIO_void_SetPinValue(KEYPAD_u8_R4, DIO_u8HIGH);
	
	#elif KEYPAD_u8_MODE == KEYPAD_u8_EX_PULL
	#endif

}

u8 KEYPAD_void_GetButton(void)
{
	u8 Local_u8_Button = '\0';
	u8 Local_u8_Flag = 0;
	
	if(Local_u8_Flag == 0)
	{
		DIO_void_SetPinValue(KEYPAD_u8_C1, DIO_u8LOW);
		DIO_void_SetPinValue(KEYPAD_u8_C2, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C3, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C4, DIO_u8HIGH);
	
		Local_u8_Button = KEYPAD_void_CheckRow(KEYPAD_u8_C1);
	    if(Local_u8_Button != '\0')
		Local_u8_Flag = 1;

	}
	
	if(Local_u8_Flag == 0)
	{
		DIO_void_SetPinValue(KEYPAD_u8_C1, DIO_u8HIGH);
	    DIO_void_SetPinValue(KEYPAD_u8_C2, DIO_u8LOW);
		DIO_void_SetPinValue(KEYPAD_u8_C3, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C4, DIO_u8HIGH);
	
		Local_u8_Button = KEYPAD_void_CheckRow(KEYPAD_u8_C2);
		if(Local_u8_Button != '\0')
        Local_u8_Flag = 1;
	}
	
	if(Local_u8_Flag == 0)
	{
		DIO_void_SetPinValue(KEYPAD_u8_C1, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C2, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C3, DIO_u8LOW);
		DIO_void_SetPinValue(KEYPAD_u8_C4, DIO_u8HIGH);
	
		Local_u8_Button = KEYPAD_void_CheckRow(KEYPAD_u8_C3);
		if(Local_u8_Button != '\0')
		Local_u8_Flag = 1;
	}
	
	if(Local_u8_Flag == 0)
	{
		DIO_void_SetPinValue(KEYPAD_u8_C1, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C2, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C3, DIO_u8HIGH);
		DIO_void_SetPinValue(KEYPAD_u8_C4, DIO_u8LOW);
	
		Local_u8_Button = KEYPAD_void_CheckRow(KEYPAD_u8_C4);
		if(Local_u8_Button != '\0')
        Local_u8_Flag = 1;
	}
	
    return	Local_u8_Button;	
}

static u8 KEYPAD_void_CheckRow(u8 Copy_u8_Col)
{
	u8 Local_u8_Data= '\0';
	
	if(DIO_u8_GetPinValue(KEYPAD_u8_R1) == DIO_u8LOW)
	{
		switch(Copy_u8_Col)
		{
			case KEYPAD_u8_C1:
			Local_u8_Data = KeyPad_Sw0;
			break;	
			
			case KEYPAD_u8_C2:
			Local_u8_Data = KeyPad_Sw1;
			break;
			
			case KEYPAD_u8_C3:
			Local_u8_Data = KeyPad_Sw2;
			break;
			
			case KEYPAD_u8_C4:
			Local_u8_Data = KeyPad_Sw3;
			break;
		}	
		
	}
	
	if(DIO_u8_GetPinValue(KEYPAD_u8_R2) == DIO_u8LOW)
	{
		switch(Copy_u8_Col)
		{
			case KEYPAD_u8_C1:
			Local_u8_Data = KeyPad_Sw4;
			break;	
			
			case KEYPAD_u8_C2:
			Local_u8_Data = KeyPad_Sw5;
			break;
			
			case KEYPAD_u8_C3:
			Local_u8_Data = KeyPad_Sw6;
			break;
			
			case KEYPAD_u8_C4:
			Local_u8_Data = KeyPad_Sw7;
			break;
		}	
	}

    if(DIO_u8_GetPinValue(KEYPAD_u8_R3) == DIO_u8LOW)
	{
		switch(Copy_u8_Col)
		{
			case KEYPAD_u8_C1:
			Local_u8_Data = KeyPad_Sw8;
			break;	
			
			case KEYPAD_u8_C2:
			Local_u8_Data = KeyPad_Sw9;
			break;
			
			case KEYPAD_u8_C3:
			Local_u8_Data = KeyPad_Sw10;
			break;
			
			case KEYPAD_u8_C4:
			Local_u8_Data = KeyPad_Sw11;
			break;
		}	
	}

	if(DIO_u8_GetPinValue(KEYPAD_u8_R4) == DIO_u8LOW)
	{
		switch(Copy_u8_Col)
		{
			case KEYPAD_u8_C1:
			Local_u8_Data = KeyPad_Sw12;
			break;	
			
			case KEYPAD_u8_C2:
			Local_u8_Data = KeyPad_Sw13;
			break;
			
			case KEYPAD_u8_C3:
			Local_u8_Data = KeyPad_Sw14;
			break;
			
			case KEYPAD_u8_C4:
			Local_u8_Data = KeyPad_Sw15;
			break;
		}	
	}

	return Local_u8_Data;
}
