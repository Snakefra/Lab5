/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: PWM2.h
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/


#ifndef PWM2_H_
#define PWM2_H_

#include <avr/io.h>
#include <stdint.h>

#define NO_INVERTIDO 1
#define INVERTIDO 0

float map1(float, float, float, float, float);				//Prototipo mapeo

void PWM2_initial(uint8_t inverted, uint16_t prescaler);	//Prototipo PWM2 A

void servo_mo2(uint8_t duty);							//Prototipo Servo



#endif /* PWM2_H_ */