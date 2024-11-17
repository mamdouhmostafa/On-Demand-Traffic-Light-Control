/*
 * Interrupt.c
 *
 * Created: 10/11/2022 11:58:11 AM
 *  Author: Ramzy
 */ 


#include "Interrupt.h"


INT_State INT0_INIT()
{
	/*Set the sense control for rising edge to INT0 */
	SET_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);
	
	/*Enable INT0*/
	SET_BIT(GICR , GICR_INT0);
	return Int_OK;
}



