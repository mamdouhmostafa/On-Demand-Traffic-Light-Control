/*
 * Application.c
 *
 * Created: 10/11/2022 3:24:11 PM
 *  Author: Ramzy
 */ 
#include "Application.h"

void App_INIT()
{
	// CAR LEDs Initialization
	LED_INIT(CARS_PORT,RED_CARS_PIN);
	LED_INIT(CARS_PORT,YELLOW_CARS_PIN);
	LED_INIT(CARS_PORT,GREEN_CARS_PIN);
	
	// PED LEDs Initialization
	LED_INIT(PED_PORT,RED_PED_PIN);
	LED_INIT(PED_PORT,YELLOW_PED_PIN);
	LED_INIT(PED_PORT,GREEN_PED_PIN);

	// Button Initialization
	DIO_init(BUTTON_PORT,BUTTON_PIN,INPUT);
	
	//Timer Initialization 
	Timer0_INIT();
	GIE_Global_Enable();
	
	//Interrupt Initialization 
	INT0_INIT();
}

//////////////////////////////////////////////////////////////////////////
//NORMAL MODE															//
//////////////////////////////////////////////////////////////////////////
void NORMAL_MODE()
{
	//Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
	LED_ON_OFF(CARS_PORT,GREEN_CARS_PIN, HIGH);
	LED_ON_OFF(PED_PORT,RED_PED_PIN, HIGH);
	//Delay for 5 seconds 
	for(int i =0 ; i <= 9; i++)
	{
		Timer0_Delay_250mSec();		
	}
	
	// Car GREEN LED IS off and yellow Blink 
	LED_ON_OFF(CARS_PORT,GREEN_CARS_PIN, LOW);
	LED_CARS_YELLOW_Blink();
	
	//Cars' RED LEDs ON and PED Green Led ON
	LED_ON_OFF(CARS_PORT,RED_CARS_PIN, HIGH);
	LED_ON_OFF(PED_PORT,RED_PED_PIN, LOW);
	LED_ON_OFF(PED_PORT,GREEN_PED_PIN, HIGH);
	//Delay for 5 seconds
	for(int i =0 ; i <= 9; i++)
	{
		Timer0_Delay_250mSec();
	}

	// PED GREEN LED IS off and yellow Blink
	LED_ON_OFF(PED_PORT,GREEN_PED_PIN, LOW);
	LED_CARS_YELLOW_Blink();
	LED_ON_OFF(CARS_PORT,RED_CARS_PIN, LOW);
}


//////////////////////////////////////////////////////////////////////////
//Interrupt Service Routine 											//
//////////////////////////////////////////////////////////////////////////
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	Timer0_Delay_250mSec();  // Wait for De bouncing  and  Long  Press Detection
	
	if(Button_read(Button_2_PORT, Button_2_PIN) == LOW)   // To Handle Button Long Press
	{
		PEDESTRIAN_MODE();
	}
}

//////////////////////////////////////////////////////////////////////////
//Pedestrian  MODE														//
//////////////////////////////////////////////////////////////////////////

void PEDESTRIAN_MODE()
{
	//If pressed when the cars' Red LED is on
	if(DIO_read(CARS_PORT,RED_CARS_PIN) == HIGH)
	{
		for(int i =0 ; i <= 9; i++)
		{
			Timer0_Delay_250mSec();
		}
		LED_PEDS_YELLOW_Blink();
		LED_ON_OFF(PED_PORT,GREEN_PED_PIN, LOW);
		LED_ON_OFF(CARS_PORT,RED_CARS_PIN, LOW);
		
	}
	//If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking
	else if(DIO_read(CARS_PORT,GREEN_CARS_PIN) || (DIO_read(CARS_PORT,YELLOW_CARS_PIN) == HIGH && DIO_read(PED_PORT,RED_PED_PIN) == LOW))
	{
		LED_ON_OFF(PED_PORT,RED_PED_PIN, HIGH);
		LEDs_Blink();
		
		LED_ON_OFF(CARS_PORT,GREEN_CARS_PIN, LOW);		
		LED_ON_OFF(CARS_PORT,RED_CARS_PIN, HIGH);			
		LED_ON_OFF(PED_PORT,RED_PED_PIN, LOW);
		LED_ON_OFF(PED_PORT,GREEN_PED_PIN, HIGH);
		//Delay for 5 seconds
		for(int i =0 ; i <= 9; i++)
		{
			Timer0_Delay_250mSec();
		}		
		
		LEDs_Blink();
		LED_ON_OFF(CARS_PORT,RED_CARS_PIN, LOW);
		LED_ON_OFF(PED_PORT,GREEN_PED_PIN, LOW);
	}
	//  if BUTTON  PRESSED WHILE CARS GREEN LED IS OFF AND RED PED LED IS ON --> (CARS YELLOW LED IS BLINKING)
	else if (DIO_read(CARS_PORT, GREEN_CARS_PIN) == LOW && DIO_read(PED_PORT, RED_PED_PIN) == HIGH)
	{
		LEDs_Blink();
		
		LED_ON_OFF(CARS_PORT,RED_CARS_PIN, HIGH);
		LED_ON_OFF(PED_PORT, RED_PED_PIN, LOW);
		LED_ON_OFF(PED_PORT,GREEN_PED_PIN, HIGH);
		LED_ON_OFF(CARS_PORT,GREEN_CARS_PIN, LOW);
		
		//Delay for 5 seconds
		for(int i =0 ; i <= 9; i++)
		{
			Timer0_Delay_250mSec();
		}		
		LEDs_Blink();
		LED_ON_OFF(PED_PORT,GREEN_PED_PIN, LOW);
		LED_ON_OFF(CARS_PORT,RED_CARS_PIN, LOW);

	}
	
	LED_ON_OFF(PED_PORT,RED_PED_PIN, HIGH);
	LED_ON_OFF(CARS_PORT,GREEN_CARS_PIN, HIGH);

}

//////////////////////////////////////////////////////////////////////////
//APP Start																//
//////////////////////////////////////////////////////////////////////////
void App_START()
{
	while(1)
	{
		NORMAL_MODE();
	}
}