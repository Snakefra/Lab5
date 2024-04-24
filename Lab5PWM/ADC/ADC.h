/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: ADC.h
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_init(void);					//Prototipo configurar el ADC

uint16_t ADC_read(uint8_t canal);		//Prototipo leer los canales del ADC


#endif /* ADC_H_ */