/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Shaaban
 * @brief          : Control LED using push button.
 * @date           : 10/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../stdTypes.h"
#include <util/delay.h>

/* registers of PORTA */
#define PORTA			*((u8 *)0x3B)
#define DDRA			*((u8 *)0x3A)
#define PINA			*((volatile u8 *)0x39)

/* registers of PORTB */
#define PORTB			*((u8 *)0x38)
#define DDRB 			*((u8 *)0x37)
#define PINB 			*((volatile u8 *)0x36)

/* some functions we need */
#define SET_BIT(VAR, BIT_NO)	(VAR|= (1<<BIT_NO))
#define CLR_BIT(VAR, BIT_NO)	(VAR&= ~(1<<BIT_NO))
#define TOGGLE_BIT(VAR, BIT_NO)		(VAR^=(1<<BIT_NO))
#define GET_BIT(VAR, BIT_NO)	((VAR>>BIT_NO) & 0x01)

int main()
{
	u8 SegChde[] = {0X3F, 0X06, 0X5B,
						0X4F, 0X66, 0X6D,
						0X7D, 0X07, 0X7F,
						0X6F};
	 u8 counter = 0;
	// sws is input
	DDRA = 0;

	// sws is pulled up
	SET_BIT(PORTA, 0);
	SET_BIT(PORTA, 1);

	// 7SEG is output ,low at start
	DDRB = 0XFF;

	// start
	PORTB = SegChde[0];



	while(1)
	{
			if(GET_BIT(~PINA, 0) && counter < 9) // switch 1 is on
			{
				PORTB = SegChde[++counter];
				while(GET_BIT(~PINA, 0));
			}
			if(GET_BIT(~PINA, 1) && counter > 0) // switch 2 is on
			{
				PORTB = SegChde[--counter];
				while(GET_BIT(~PINA, 1));
			}

	}
	return 0;
}


