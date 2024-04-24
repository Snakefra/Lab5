/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: main.c
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/ 
#define F_CPU 16000000UL	 // Frecuencia de reloj de 16 MHz

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "PWM0/PWM0.h"
#include "PWM1/PWM1.h"
#include "PWM2/PWM2.h"
#include "ADC/ADC.h"



//ADC y DUTY cicle
float ADC_V1 = 0;			//Valor del PIN PC0

uint8_t ADC_V2 = 0;			//Valor del PIN PC1

float ADC_V3 = 0;			//Valor del PIN PC4

int main(void)
{
	cli();
	DDRD = 0xFF;			//Configuración del puerto D
	
	TCCR2A = 0;
	TCCR2B = 0;
	

	ADC_init();
	PWM0_init();
	PWM1_initial();
	PWM2_initial(NO_INVERTIDO,1024);

	sei();

	while (1)
	{
		//Servo
		ADC_V1 = ADC_read(0);		//Lee canal 0
		servo_moA1(ADC_V1);			//Toogle señal canal A
		_delay_ms(10);				//Delay
		
		ADC_V2 = ADC_read(1);		//Lee canal 1
		servo_mo2(ADC_V2);			//Toogle señal canal A
		_delay_ms(10);				//Delay
		
		ADC_V3 = ADC_read(4);					//Lee canal 4
		ADC_V3 = (ADC_V3 * 100)/1023;			//ADC de 10 Bits 
		PWM0_dca((uint8_t)ADC_V3, NO_INVERTIDO);
		_delay_ms(10);

	}
}

ISR(ADC_vect){
	ADCSRA |= (1 << ADIF);	
}