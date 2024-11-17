/*
 * Button.c
 *
 * Created: 10/11/2022 2:16:18 PM
 *  Author: Ramzy
 */ 


#include "Button.h"

//initialize
Button_State Button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	
	DIO_Functions_State ButtonState;
	
	ButtonState = DIO_init(buttonPort,buttonPin,INPUT);   // Set Button Pin Direction as Input Pin
	if(ButtonState == PinDir_Ok)
	{
		return Button_Ok;
	}
	else
	{
		return Button_NotOk;
	}
}


//button read
EN_Pinvalue_t Button_read(EN_PortNo_t buttonPort, EN_PinNo_t buttonPin)
{
	EN_Pinvalue_t Button_State = DIO_read(buttonPort,buttonPin);
	return Button_State;
}