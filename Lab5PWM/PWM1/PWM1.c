/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: PWM1.c
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/
#include "PWM1.h"
#include <avr/io.h>

void PWM1_initial(void){
	DDRB |= (1<<DDB1)|(1<<DDB2);
	
	TCNT1 = 0;				//RESET
	ICR1 = 39999;			//TOP
	
	TCCR1A =  (1 << COM1A1) | (1 << COM1B1) | (0 << COM1A0) ;		//Salida en nivel bajo
	TCCR1A |=  (1 << WGM11) | (0 << WGM10) ; // Configuración PWM MODO:Fast TOP ICR1
	TCCR1B = (1 << WGM13) | (1 << WGM12); // Modo Fast PWM TOP 
	
	// Prescaler 8
	TCCR1B |= (1 << CS11);
}

void servo_moA1(float adc_Value){					//Configuración servo A
	
	OCR1A = map(adc_Value, 0, 1024, 1000, 4800);  // Mapeo
}

void servo_moB1(float adc_Value){					//Configuración servo B
	OCR1B = map(adc_Value, 0, 1024, 1000, 4800);
}

uint16_t map(float x, float in_min, float in_max, float out_min, float out_max){
	return ((x - in_min)*(out_max - out_min)/(in_max - in_min)) + out_min;
}