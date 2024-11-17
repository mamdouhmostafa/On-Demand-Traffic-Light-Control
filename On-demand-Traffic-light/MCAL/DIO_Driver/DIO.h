/*
 * DIO.h
 *
 * Created: 10/11/2022 11:57:49 AM
 *  Author: Ramzy
 */ 


#ifndef DIO_H_
#define DIO_H_
//Include registers.h
#include "../../Utilities/Registers.h"
//Include Math Operations.h
#include "../../Utilities/Bit_Math_Operations.h"

//All internal driver typedefs
//all driver macros
typedef enum{
	PORT_A, PORT_B, PORT_C, PORT_D
} EN_PortNo_t;

// all pin macros
typedef enum{
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} EN_PinNo_t;

// All Pin mode macros 
typedef enum{
	LOW,
	HIGH
} EN_Pinvalue_t;

typedef enum
{
	INPUT,
	OUTPUT
}DIO_PinMode_t;

typedef enum
{
	PinMode_NotOk,PinMode_Ok,PinDir_NotOk,PinDir_Ok
}DIO_Functions_State;

//all driver function prototype
DIO_Functions_State DIO_init(EN_PortNo_t portNumber, EN_PinNo_t pinNumber, DIO_PinMode_t direction); // Initialize DIO Direction
DIO_Functions_State DIO_write(EN_PortNo_t portNumber, EN_PinNo_t pinNumber, EN_Pinvalue_t value); // Write data to DIO
DIO_Functions_State DIO_toggle(EN_PortNo_t portNumber, EN_PinNo_t pinNumber);	// Toggle value in DIO
EN_Pinvalue_t DIO_read(EN_PortNo_t portNumber, EN_PinNo_t pinNumber);	// Read DIO value

#endif /* DIO_H_ */