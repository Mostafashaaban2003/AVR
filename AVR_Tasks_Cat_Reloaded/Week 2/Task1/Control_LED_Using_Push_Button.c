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
	 u8 swState = 0;
	// sws is input
	DDRB = 0;
	DDRA = 0;
	// sws is pulled up
	SET_BIT(PORTB, 0);
	SET_BIT(PORTB, 1);
	SET_BIT(PORTB, 2);

	// leds is output ,low at start
	SET_BIT(DDRA, 0);
	SET_BIT(DDRA, 1);

	// to make leds off
	CLR_BIT(PORTA, 0);
	CLR_BIT(PORTA, 1);



	while(1)
	{
		// to make the results logical
			swState = ~PINB;

		if(GET_BIT(swState, 0)) // switch 1 is on
		{
			SET_BIT(PORTA, 0); // red led is on
			CLR_BIT(PORTA, 1); // green led is off
		}

		if(GET_BIT(swState, 1)) // switch 2 is on
		{
			SET_BIT(PORTA, 1); // green led is on
			CLR_BIT(PORTA, 0); // red led is off
		}

		if(GET_BIT(swState, 2)) // switch 3 is on
		{
			SET_BIT(PORTA, 0); // red led is on
			SET_BIT(PORTA, 1); // green led is on
		}

		else // all switches is off
		{
			CLR_BIT(PORTA, 0); // red led is off
			CLR_BIT(PORTA, 1); // green led is off
		}
	}
	return 0;
}
