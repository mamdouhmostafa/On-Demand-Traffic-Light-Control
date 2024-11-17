/*
 * Application.h
 *
 * Created: 10/11/2022 3:19:36 PM
 *  Author: Ramzy
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/LED_Driver/Led.h"
#include "../ECUAL/Button_Driver/Button.h"

// LED CAR PINS AND PORT
#define CARS_PORT			PORT_A
#define RED_CARS_PIN		PIN2
#define YELLOW_CARS_PIN		PIN1
#define GREEN_CARS_PIN		PIN0
//PEDESTERIAN LEDS PINS AND PORT
#define PED_PORT			PORT_B
#define RED_PED_PIN			PIN0
#define YELLOW_PED_PIN		PIN1
#define GREEN_PED_PIN		PIN2
//BUTTON PORT AND PIN
#define BUTTON_PORT		PORT_D
#define BUTTON_PIN		PIN2

void App_INIT();
void App_START();
void PEDESTRIAN_MODE();
void NORMAL_MODE();

#endif /* APPLICATION_H_ */