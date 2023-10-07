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
	DDRA |= (1<<0);
	while(1)
	{
				PORTA|=(1<<0);
				_delay_ms(1000);
				PORTA&=~(1<<0);
				_delay_ms(1000);
	}

}


