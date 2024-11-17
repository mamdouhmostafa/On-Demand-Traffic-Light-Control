/*
 * Interrupt.h
 *
 * Created: 10/11/2022 11:58:24 AM
 *  Author: Ramzy
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/Bit_Math_Operations.h"
#include "../../Utilities/Registers.h"

#define MCUCR_ISC00       0
#define MCUCR_ISC01       1
#define MCUCR_ISC10       2
#define MCUCR_ISC11       3

#define MCUCSR_ISC2       6

#define GICR_INT2         5
#define GICR_INT0         6
#define GICR_INT1         7

#define GIFR_INTF2        5
#define GIFR_INTF0        6
#define GIFR_INTF1        7

#define SREG_I            7

typedef enum
{
	Int_NotOK,Int_OK
}INT_State;

INT_State INT0_INIT();


#endif /* INTERRUPT_H_ */