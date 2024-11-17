/*
 * Timer.h
 *
 * Created: 10/11/2022 11:58:36 AM
 *  Author: Ramzy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//Include registers.h
#include "../../Utilities/Registers.h"
//Include Math Operations.h
#include "../../Utilities/Bit_Math_Operations.h"
//Include DIO.h
#include "../../MCAL/DIO_Driver/DIO.h"

#define TCCR0_WGM00      6
#define TCCR0_WGM01      3

#define TCCR0_CS00		 0
#define TCCR0_CS01		 1
#define TCCR0_CS02		 2

#define TIMSK_TOIE0      0
#define TIMSK_OCIE		 1

#define SREG_I           7

#define TIFR_TOV0		 0


typedef enum
{
	Timer_NotOk,Timer_Ok
	
}Timer_State;

Timer_State Timer0_INIT();					// Timer0 Initialization Function
void GIE_Global_Enable();			// Global Interrupt Enable Function
void Timer0_Delay_250mSec();			// Delay 250 m Seconds using Timer0



#endif /* TIMER_H_ */