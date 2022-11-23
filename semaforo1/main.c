/*
 * semaforo1.c
 *
 * Created: 8/11/2022 12:20:51 p. m.
 * Author : Martin
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0b00100111; //C1 C2 C3 como salidas
	PORTC = 0b00000000;

	while (1)
	{
		PORTC |= (1<<PORTC0);   //Rojo en alto
		PORTC &= ~(1<<PORTC1); //Amarillo en bajo
		PORTC &= ~(1<<PORTC2);  // Verde en bajo
		_delay_ms(10000);
		PORTC |= (1<<PORTC1); //Amarillo en alto
		PORTC &= ~(1<<PORTC0); //Rojo en bajo
		PORTC &= ~(1<<PORTC2); // Verde en bajo
		_delay_ms(5000);
		PORTC |= (1<<PORTC2); //Verde en alto
		PORTC &= ~(1<<PORTC0); //Rojo en bajo
		PORTC &= ~(1<<PORTC1);  //Amarillo en bajo
		_delay_ms(10000);

	}
}

