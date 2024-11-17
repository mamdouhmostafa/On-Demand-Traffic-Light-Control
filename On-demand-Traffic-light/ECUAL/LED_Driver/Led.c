/*
 * Led.c
 *
 * Created: 10/11/2022 2:38:54 PM
 *  Author: Ramzy
 */ 


#include "Led.h"


LED_State LED_INIT(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN)
{
	DIO_Functions_State LEDState;
	LEDState = 	DIO_init(LED_PORT, LED_PIN, OUTPUT);   // Initializing LED Pin Direction as OUTPUT Pin
	if(LEDState == PinDir_Ok)
	{
		return LED_Ok;
	}
	else
	{
		return LED_NotOk;
	}
}

LED_State LED_ON_OFF(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN, EN_Pinvalue_t State)
{
	DIO_Functions_State LEDState;
	LEDState = 		DIO_write(LED_PORT, LED_PIN, State);
	if(LEDState == PinDir_Ok)
	{
		return LED_Ok;
	}
	else
	{
		return LED_NotOk;
	}
}

void LED_TOG(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN)
{
	DIO_toggle(LED_PORT,LED_PIN);   // Toggle LED
}

void LEDs_Blink()
{
	static uint8_t Counter = 0;  
	
	while(Counter <= 4)
	{
		LED_ON_OFF(PORT_A,PIN1,HIGH);
		LED_ON_OFF(PORT_B,PIN1,HIGH);
		Timer0_Delay_250mSec();
		
		LED_ON_OFF(PORT_A,PIN1,LOW);
		LED_ON_OFF(PORT_B,PIN1,LOW);
		Timer0_Delay_250mSec();
		
		Counter++;
	}
	Counter = 0;
}

void LED_PEDS_YELLOW_Blink()
{
	static uint8_t Counter = 0;
	
	while(Counter <= 4)
	{
		LED_ON_OFF(PORT_B,PIN1, HIGH);
		Timer0_Delay_250mSec();
		
		LED_ON_OFF(PORT_B, PIN1,LOW);
		Timer0_Delay_250mSec();
		
		Counter++;
	}
	Counter = 0;
}

void LED_CARS_YELLOW_Blink()
{
	static uint8_t Counter = 0;  
	while(Counter <= 4)
	{
		if (Button_read(Button_2_PORT, Button_2_PIN) == HIGH)
		{
			LEDs_Blink();
			break;
		}
		else
		{
			LED_ON_OFF(PORT_A,PIN1, HIGH);
			Timer0_Delay_250mSec();
			
			LED_ON_OFF(PORT_A,PIN1, LOW);
			Timer0_Delay_250mSec();
			
			Counter++;
		}
	}
	Counter = 0;
}

