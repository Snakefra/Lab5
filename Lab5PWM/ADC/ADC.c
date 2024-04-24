/*****************************************************************************
 * Universidad del Valle de Guatemala
 * IE2023: Programación de microcontroladores
 * Autor: Oscar Melchor
 * Proyecto: PWM y Librerias
 * Archivo: ADC.c
 * Hardware : ATMEGA328P
 * Created: 17/04/2024 08:41:07
 *****************************************************************************/
#include "ADC.h"
#include <avr/io.h>

void ADC_init(void)
{
	ADMUX |= (1<<REFS0);	//Seleccionar el voltaje de referencia
	ADMUX &= ~(1<<REFS1);
	ADMUX &= ~(1<<ADLAR);	// Se define que se trabajara con 10 bits
	
	// Configuración Prescaler de 128 16M/128 = 125KHz
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADCSRA |= (1<<ADEN);	// Se enceinde el ADC y se activa su interruptor de igual forma
	
	//Entradas para los potenciometros
	DIDR0 |= (1 << ADC0D);		// Desabilitar la entrada digital PC0
	DIDR0 |= (1 << ADC1D);		// Desabilitar la entrada digital PC1
	DIDR0 |= (1 << ADC4D);		// Desabilitar la entrada digital PC4
}
uint16_t ADC_read(uint8_t canal){
	ADMUX = (ADMUX & 0xF0)|canal;			//Seleccionar el canal del ADC
	ADCSRA |= (1<<ADSC);					// Se inicia la conversión de lo valores
	while((ADCSRA)&(1<<ADSC));				//Se espera hasta que la conversión se haya completado
	return(ADC);							//Regresa el valor de ADC
}