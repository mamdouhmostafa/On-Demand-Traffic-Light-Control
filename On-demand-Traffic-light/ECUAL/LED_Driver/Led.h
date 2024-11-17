/*
 * Led.h
 *
 * Created: 10/11/2022 2:39:04 PM
 *  Author: Ramzy
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/DIO.h"
#include "../../MCAL/Timer_Driver/Timer.h"
#include "../../ECUAL/Button_Driver/Button.h"


#define GREEN_LED               PIN0
#define CARS_LEDs_PORT          PORTA
#define pedestrian_LEDs_PORT    PORTB



typedef enum
{
	LED_NotOk,LED_Ok
}LED_State;

LED_State LED_INIT(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN);

LED_State LED_ON_OFF(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN, EN_Pinvalue_t State);

void LED_TOG(EN_PortNo_t LED_PORT , EN_PinNo_t LED_PIN);

void LEDs_Blink();  

void LED_CARS_YELLOW_Blink();

void LED_PEDS_YELLOW_Blink();


#endif /* LED_H_ */