/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: PWM2.c
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/
#include "PWM2.h"
#include <avr/io.h>

void PWM2_initial(uint8_t inverted, uint16_t prescaler){			//Canal A
	//Salidas
	DDRB |= (1 << DDB3); //Se define el pin PB3 como salida
	
	//Configuración modo Fast
	TCCR2A |= (1 << WGM21)|(1 << WGM20);
	
	//C PWM INVERTIDO
	if (inverted) {
		TCCR2A |= (1 << COM2A1)|(1 << COM2A0);
		} else	 {	//PWM NO INVERTIDO
		TCCR2A |= (1 << COM2A1);
	}

	//Prescaler 1024
	if (prescaler == 1024) {
		TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20);
		} else {
		TCCR2B |= (1 << CS20);
	}
}

void servo_mo2(uint8_t duty){		//Mapeo canal A
	OCR2A = map1(duty,0,200,6,36);
}

//Mapeo
float map1(float x, float in_min, float in_max, float out_min, float out_max){
	return ((x - in_min)*(out_max - out_min)/(in_max - in_min)) + out_min;
}