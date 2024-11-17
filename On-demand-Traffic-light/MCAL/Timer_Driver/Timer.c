/*
 * Timer.c
 *
 * Created: 10/11/2022 11:58:46 AM
 *  Author: Ramzy
 */ 

#include "Timer.h"

Timer_State Timer0_INIT(){
	/* Select normal mode */
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);

	/* Select prescaler 1024 */
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS02);

	/*Set preload value to reach 0.25 sec*/
	TCNT0 = 12;		
	
	if(GET_BIT(TCCR0,TCCR0_WGM00) != 0 && GET_BIT(TCCR0,TCCR0_WGM01) !=0)
	{
		return Timer_NotOk;
	}
	else
	{
		return Timer_Ok;
	}			
		
	
	return Timer_Ok;
}


void GIE_Global_Enable()
{
	/*Enable the global Interrupt */
	SET_BIT(SREG , SREG_I);
}


void Timer0_Delay_250mSec()
{
	static uint8_t OverFlowCounter = 0;
	
	while(OverFlowCounter <= 1)
	{
		if(GET_BIT(TIFR, TIFR_TOV0) == HIGH)
		{
			OverFlowCounter++;
			SET_BIT(TIFR, TIFR_TOV0);
		}
		else{}
	}
	OverFlowCounter = 0;
	TCNT0 = 12;
}