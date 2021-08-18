/********************************************************************/
 /******************************************************************/
 /* 		Title : KEYPAD Cofigration File                        */
 /*		Author: Ahmed Mohamed Fathy (Ahmed Omda)				   */	
 /* 		Last Update: 18 Aug 2021						       */
 /******************************************************************/
/********************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_u8_R1	DIO_u8Pin16  //input 
#define KEYPAD_u8_R2    DIO_u8Pin17
#define KEYPAD_u8_R3	DIO_u8Pin18
#define KEYPAD_u8_R4	DIO_u8Pin19

#define KEYPAD_u8_C1	DIO_u8Pin20  //output
#define KEYPAD_u8_C2	DIO_u8Pin21
#define KEYPAD_u8_C3	DIO_u8Pin22
#define KEYPAD_u8_C4	DIO_u8Pin23


#define KEYPAD_u8_MODE  KEYPAD_u8_IN_PULL 


/*each switch which number */
#define KeyPad_Sw0	  '7'
#define KeyPad_Sw1	  '8'
#define KeyPad_Sw2	  '9'
#define KeyPad_Sw3	  '/'

#define KeyPad_Sw4	  '4'
#define KeyPad_Sw5	  '5'
#define KeyPad_Sw6	  '6'
#define KeyPad_Sw7	  '*'
 
#define KeyPad_Sw8	  '1'
#define KeyPad_Sw9	  '2'
#define KeyPad_Sw10	  '3'
#define KeyPad_Sw11	  '-'

#define KeyPad_Sw12	  ' '
#define KeyPad_Sw13	  '0'
#define KeyPad_Sw14	  '='
#define KeyPad_Sw15	  '+'

#endif  //KEYPAD_CONFIG_H_
