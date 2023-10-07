/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Shaaban
 * @brief          : turn on the LED for 1 second and then turn it off.
 * @date           : 10/7/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../stdTypes.h"
#include <util/delay.h>

/* registers of PORTA */
#define PORTA			*((u8 *)0x3B)
#define DDRA			*((u8 *)0x3A)
#define PINA			*((volatile u8 *)0x39)

int main()
{
	int i;
	DDRA = 0XFF;
	PORTA = 0;
		while(1)
		{
			for (i = 0; i <= 7; i++)
			{
				PORTA |= (1<<i);
				_delay_ms(100);
				PORTA &= ~(1<<i);
				_delay_ms(100);
			}
		}
}
