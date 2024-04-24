/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: PWM0.h
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/


#ifndef PWM0_H_
#define PWM0_H_

#include <avr/io.h>

#define NO_INVERTIDO	1
#define INVERTIDO		0

void PWM0_init(void);						//Duty cycle PWM
void PWM0_dca(uint8_t dc, uint8_t modo);	//Salida invertida o no invertida  
void PWM0_dcb(uint8_t dc, uint8_t modo);	//Salida invertida o no invertida  



#endif /* PWM0_H_ */