/*
 * DIO.c
 *
 * Created: 10/11/2022 11:57:59 AM
 *  Author: Ramzy
 */ 
//include .h files
#include "DIO.h"

DIO_Functions_State DIO_init(EN_PortNo_t portNumber, EN_PinNo_t pinNumber, DIO_PinMode_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		if(OUTPUT == direction){
		SET_BIT(DDRA,pinNumber);
		return PinDir_Ok;
		}
		else
		{
		CLEAR_BIT(DDRA,pinNumber);
		return PinDir_NotOk;
		break;	
		}
		
		case PORT_B:
		if(OUTPUT == direction){
			SET_BIT(DDRB,pinNumber);
			return PinDir_Ok;
		}
		else
		{
			CLEAR_BIT(DDRB,pinNumber);
			return PinDir_NotOk;
			break;
		}
		
		case PORT_C:
		if(OUTPUT == direction){
			SET_BIT(DDRC,pinNumber);
			return PinDir_Ok;
		}
		else
		{
			CLEAR_BIT(DDRC,pinNumber);
			return PinDir_NotOk;
			break;
		}
		
		case PORT_D:
		if(OUTPUT == direction){
			SET_BIT(DDRD,pinNumber);
			return PinDir_Ok;
		}
		else
		{
			CLEAR_BIT(DDRD,pinNumber);
			return PinDir_NotOk;
			break;
		}
		default:
		break;
	}
}

DIO_Functions_State DIO_write(EN_PortNo_t portNumber, EN_PinNo_t pinNumber, EN_Pinvalue_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if(HIGH == value){
			SET_BIT(PORTA,pinNumber);
			return PinMode_Ok;
		}
		else
		{
			CLEAR_BIT(PORTA,pinNumber);
			return PinMode_NotOk;
			break;
		}
		
		case PORT_B:
		if(HIGH == value){
			SET_BIT(PORTB,pinNumber);
			return PinMode_Ok;
		}
		else
		{
			CLEAR_BIT(PORTB,pinNumber);
			return PinMode_NotOk;
			break;
		}
		
		case PORT_C:
		if(HIGH == value){
			SET_BIT(PORTC,pinNumber);
			return PinMode_Ok;
		}
		else
		{
			CLEAR_BIT(PORTC,pinNumber);
			return PinMode_NotOk;
			break;
		}
		
		case PORT_D:
		if(HIGH == value){
			SET_BIT(PORTD,pinNumber);
			return PinMode_Ok;
		}
		else
		{
			CLEAR_BIT(PORTD,pinNumber);
			return PinMode_NotOk;
			break;
		}
		default:
		break;
	}
}
DIO_Functions_State DIO_toggle(EN_PortNo_t portNumber, EN_PinNo_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNumber); 
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
		default    :  break;

	}
}
EN_Pinvalue_t DIO_read(EN_PortNo_t portNumber, EN_PinNo_t pinNumber)
{	
	EN_Pinvalue_t Pin_Output;
	switch(portNumber)
	{
		case PORT_A:
		Pin_Output = GET_BIT(PINA,pinNumber);
		break;
		case PORT_B:
		Pin_Output = GET_BIT(PINB,pinNumber);
		break;
		case PORT_C:
		Pin_Output = GET_BIT(PINC,pinNumber);
		break;
		case PORT_D:
		Pin_Output = GET_BIT(PIND,pinNumber);
		break;
	}
	return Pin_Output;
}
