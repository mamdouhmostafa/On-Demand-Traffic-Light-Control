/*
 * Button.h
 *
 * Created: 10/11/2022 2:16:06 PM
 *  Author: Ramzy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_Driver/DIO.h"

#define Button_2_PORT PORT_D
#define Button_2_PIN PIN2


typedef enum
{
	Button_NotOk,Button_Ok
}Button_State;

//initialize
Button_State Button_init(EN_PortNo_t buttonPort, EN_PinNo_t buttonPin);

//button read
EN_Pinvalue_t Button_read(EN_PortNo_t buttonPort, EN_PinNo_t buttonPin);


#endif /* BUTTON_H_ */