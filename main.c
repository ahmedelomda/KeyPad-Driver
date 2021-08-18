#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include <avr/delay.h>

#define F_CPU 8000000   //define CPU 8Mega frequency Hertz

int main(void)
{
	DIO_void_Init();
	LCD_void_Init();
	KEYPAD_void_Init();

	u8 x ='\0';
	while(1)
	{
		x = KEYPAD_void_GetButton();
		while(x != '\0')
		{
			LCD_void_GoToRowCol(0,0);
			LCD_void_WriteCharacter(x);
			x = KEYPAD_void_GetButton();

			if(x == '7')
			{
				DIO_void_SetPinValue(11,1);
			}

			if(x == '8')
			{
				DIO_void_SetPinValue(11,0);
			}
		}
	}

	return 0;
}


