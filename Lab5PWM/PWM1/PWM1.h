/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: PWM1.h
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/


#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h>

void PWM1_initial(void);				//Prototipo PWM1

void servo_moA1(float valADC);			//Prototipo servo A

void servo_moB1(float valADC);			//Prototipo servo B


uint16_t map(float x, float in_min, float in_max, float out_min, float out_max);  //Mapeo



#endif /* PWM1_H_ */