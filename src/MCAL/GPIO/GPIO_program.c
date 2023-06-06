/*
 * RCC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: ziads
 */


#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_cfg.h"



void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8PinType
		, u8 Copy_u8PinSpeed)
{


	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		if((Copy_u8PinID==PIN13)||(Copy_u8PinID==PIN14)||(Copy_u8PinID==PIN15))
		{


		}
		else
		{
			/*Set Direction of The Pin to be Output by Bit Masking */
			GPIOA->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
			GPIOA->GPIO_MODER|=(0b01<<(Copy_u8PinID*2));

			/*Set Speed of The Pin By Bit Masking */
			GPIOA->GPIO_OSPEEDR&=~(0b11<<(Copy_u8PinID*2));
			GPIOA->GPIO_OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/* Set Type of Output Pin*/
			WRITE_BIT(GPIOA->GPIO_OTYPER,Copy_u8PinID,Copy_u8PinType);
		}
		break;

	case GPIO_PORTB:
		if((Copy_u8PinID==PIN2)||(Copy_u8PinID==PIN3)||(Copy_u8PinID==PIN4))
		{

		}
		else
		{
			/*Set Direction of The Pin to be Output by Bit Masking */
			GPIOB->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
			GPIOB->GPIO_MODER|=(0b01<<(Copy_u8PinID*2));

			/*Set Speed of The Pin By Bit Masking */
			GPIOB->GPIO_OSPEEDR&=~(0b11<<(Copy_u8PinID*2));
			GPIOB->GPIO_OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/* Set Type of Output Pin*/
			WRITE_BIT(GPIOB->GPIO_OTYPER,Copy_u8PinID,Copy_u8PinType);
		}
		break;

	case GPIO_PORTC:
		/*Set Direction of The Pin to be Output by Bit Masking */
		GPIOC->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		GPIOC->GPIO_MODER|=(0b01<<(Copy_u8PinID*2));

		/*Set Speed of The Pin By Bit Masking */
		GPIOC->GPIO_OSPEEDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOC->GPIO_OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));

		/* Set Type of Output Pin*/
		WRITE_BIT(GPIOC->GPIO_OTYPER,Copy_u8PinID,Copy_u8PinType);

		break;

	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8PullMode)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		/*Set Direction of The Pin to be input Pin by Bit Masking */
		GPIOA->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		//GPIOA->GPIO_MODER|=(0b00<<(Copy_u8PinID*2));

		/*Set the Mode of input pin */
		GPIOA->GPIO_PUPDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOA->GPIO_PUPDR|=(Copy_u8PullMode<<(Copy_u8PinID*2));

		/* Set Type of input Pin*/
		//WRITE_BIT(GPIOA->GPIO_PUPDR,Copy_u8PinID,Copy_u8PullMode);

		break;

	case GPIO_PORTB:
		/*Set Direction of The Pin to be input Pin by Bit Masking */
		GPIOB->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		//GPIOB->GPIO_MODER|=(0b00<<(Copy_u8PinID*2));

		/*Set the Mode of input pin */
		GPIOB->GPIO_PUPDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOB->GPIO_PUPDR|=(Copy_u8PullMode<<(Copy_u8PinID*2));

		/* Set Type of input Pin*/
		//WRITE_BIT(GPIOA->GPIO_PUPDR,Copy_u8PinID,Copy_u8PullMode);

		break;

	case GPIO_PORTC:
		/*Set Direction of The Pin to be input Pin by Bit Masking */
		GPIOC->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		//GPIOC->GPIO_MODER|=(0b00<<(Copy_u8PinID*2));

		/*Set the Mode of input pin */
		GPIOC->GPIO_PUPDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOC->GPIO_PUPDR|=(Copy_u8PullMode<<(Copy_u8PinID*2));

		/* Set Type of input Pin*/
		//WRITE_BIT(GPIOA->GPIO_PUPDR,Copy_u8PinID,Copy_u8PullMode);

		break;

	}
}

void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		WRITE_BIT(GPIOA->GPIO_ODR,Copy_u8PinID,Copy_u8Value );
		break;
	case GPIO_PORTB:
		WRITE_BIT(GPIOB->GPIO_ODR,Copy_u8PinID,Copy_u8Value );
		break;

	case GPIO_PORTC:
		WRITE_BIT(GPIOC->GPIO_ODR,Copy_u8PinID,Copy_u8Value );
		break;

	}

}

u8 GPIO_voidGetInputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	u8 Local_u8ReturnValue = 0;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		Local_u8ReturnValue=READ_BIT(GPIOA->GPIO_IDR,Copy_u8PinID);
		break;
	case GPIO_PORTB:
		Local_u8ReturnValue=READ_BIT(GPIOB->GPIO_IDR,Copy_u8PinID);
		break;

	case GPIO_PORTC:
		Local_u8ReturnValue=READ_BIT(GPIOC->GPIO_IDR,Copy_u8PinID);
		break;

	}

	return Local_u8ReturnValue;
}

void GPIO_voidSetOutputPinValueFast(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value)
{
	u32 Local_u32RegisterValue;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		switch(Copy_u8Value)
		{/*Set The Pin Value*/
		/*Access bits from 0 to 15 */
		case GPIO_OUTPUT_HIGH:
			Local_u32RegisterValue=1<<(Copy_u8PinID);
			break;
			/*Set The Pin Value*/
			/*Access bits from 16 to 31 */
		case GPIO_OUTPUT_LOW:
			Local_u32RegisterValue=1<<(Copy_u8PinID+16);
			break;
		}
		GPIOA->GPIO_BSRR = Local_u32RegisterValue;
		break;

		case GPIO_PORTB:
			switch(Copy_u8Value)
			{/*Set The Pin Value*/
			/*Access bits from 0 to 15 */
			case GPIO_OUTPUT_HIGH:
				Local_u32RegisterValue=1<<(Copy_u8PinID);
				break;
				/*Set The Pin Value*/
				/*Access bits from 16 to 31 */
			case GPIO_OUTPUT_LOW:
				Local_u32RegisterValue=1<<(Copy_u8PinID+16);
				break;
			}
			GPIOB->GPIO_BSRR = Local_u32RegisterValue;
			break;
			case GPIO_PORTC:
				switch(Copy_u8Value)
				{/*Set The Pin Value*/
				/*Access bits from 0 to 15 */
				case GPIO_OUTPUT_HIGH:
					Local_u32RegisterValue=1<<(Copy_u8PinID);
					break;
					/*Set The Pin Value*/
					/*Access bits from 16 to 31 */
				case GPIO_OUTPUT_LOW:
					Local_u32RegisterValue=1<<(Copy_u8PinID+16);
					break;
				}
				GPIOC->GPIO_BSRR = Local_u32RegisterValue;
				break;

	}

}


void GPIO_voidInitOutputPort(u8 Copy_u8PortID, u8 Copy_u8PortType, u8 Copy_u8PortSpeed)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->GPIO_MODER=0x55555555;   /* Output Port */
		switch(Copy_u8PortType)
		{
		case GPIO_PUSH_PULL:
			GPIOA->GPIO_OTYPER&=0xFFFF0000;  /*PushPull Type*/
			switch(Copy_u8PortSpeed)
			{
			case GPIO_LOW_SPEED:
				GPIOA->GPIO_OSPEEDR=0;    // LOW Speed
				break;
			case GPIO_HIGH_SPEED:
				GPIOA->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
				break;
			case GPIO_MID_SPEED:
				GPIOA->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
				break;
			case GPIO_VERY_HIGH_SPEED:
				GPIOA->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
				break;
			}
			break;

			case GPIO_OPEN_DRAIN:
				GPIOA->GPIO_OTYPER=0;
				GPIOA->GPIO_OTYPER|=0x0000FFFF;  /*Opendrain */
				switch(Copy_u8PortSpeed)
				{
				case GPIO_LOW_SPEED:
					GPIOA->GPIO_OSPEEDR=0;    // LOW Speed
					break;
				case GPIO_HIGH_SPEED:
					GPIOA->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
					break;
				case GPIO_MID_SPEED:
					GPIOA->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
					break;
				case GPIO_VERY_HIGH_SPEED:
					GPIOA->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
					break;
				}
				break;

		}
		break;

		case GPIO_PORTB:
			GPIOB->GPIO_MODER=0x55555555;   /* Output Port */
			switch(Copy_u8PortType)
			{
			case GPIO_PUSH_PULL:
				GPIOB->GPIO_OTYPER&=0xFFFF0000;  /*PushPull Type*/
				switch(Copy_u8PortSpeed)
				{
				case GPIO_LOW_SPEED:
					GPIOB->GPIO_OSPEEDR=0;    // LOW Speed
					break;
				case GPIO_HIGH_SPEED:
					GPIOB->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
					break;
				case GPIO_MID_SPEED:
					GPIOB->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
					break;
				case GPIO_VERY_HIGH_SPEED:
					GPIOB->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
					break;
				}
				break;

				case GPIO_OPEN_DRAIN:
					GPIOB->GPIO_OTYPER=0;
					GPIOB->GPIO_OTYPER|=0x0000FFFF;  /*Opendrain */
					switch(Copy_u8PortSpeed)
					{
					case GPIO_LOW_SPEED:
						GPIOB->GPIO_OSPEEDR=0;    // LOW Speed
						break;
					case GPIO_HIGH_SPEED:
						GPIOB->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
						break;
					case GPIO_MID_SPEED:
						GPIOB->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
						break;
					case GPIO_VERY_HIGH_SPEED:
						GPIOB->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
						break;
					}
					break;

			}
			break;


			case GPIO_PORTC:
				GPIOC->GPIO_MODER=0x55555555;   /* Output Port*/
				switch(Copy_u8PortType)
				{
				case GPIO_PUSH_PULL:
					GPIOC->GPIO_OTYPER&=0xFFFF0000;  /*PushPull Type*/
					switch(Copy_u8PortSpeed)
					{
					case GPIO_LOW_SPEED:
						GPIOC->GPIO_OSPEEDR=0;    // LOW Speed
						break;
					case GPIO_HIGH_SPEED:
						GPIOC->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
						break;
					case GPIO_MID_SPEED:
						GPIOC->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
						break;
					case GPIO_VERY_HIGH_SPEED:
						GPIOC->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
						break;
					}
					break;

					case GPIO_OPEN_DRAIN:
						GPIOC->GPIO_OTYPER=0;
						GPIOC->GPIO_OTYPER|=0x0000FFFF;  /*Opendrain */
						switch(Copy_u8PortSpeed)
						{
						case GPIO_LOW_SPEED:
							GPIOC->GPIO_OSPEEDR=0;    // LOW Speed
							break;
						case GPIO_HIGH_SPEED:
							GPIOC->GPIO_OSPEEDR=0x55555555;    // HIGH Speed
							break;
						case GPIO_MID_SPEED:
							GPIOC->GPIO_OSPEEDR=0xAAAAAAAA;    // Midium Speed
							break;
						case GPIO_VERY_HIGH_SPEED:
							GPIOC->GPIO_OSPEEDR=0xFFFFFFFF;    // Very HIGH Speed
							break;
						}
						break;

				}
				break;

	}


}


void GPIO_voidSetOutputPortValue(u8 Copy_u8PortID, u16 Copy_u16PortValue)
{
	u16 Local_u16MAXValue = 8191; /* 0b0001111111111111 */
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		if(Copy_u16PortValue<=Local_u16MAXValue)
		{
			GPIOA->GPIO_ODR = Copy_u16PortValue;
		}
		else
		{
			GPIOA->GPIO_ODR = Local_u16MAXValue;
		}
		break;

	case GPIO_PORTB:
		if(Copy_u16PortValue<=Local_u16MAXValue)
		{
			GPIOB->GPIO_ODR = Copy_u16PortValue;
		}
		else
		{
			GPIOB->GPIO_ODR = Local_u16MAXValue;
		}
		break;

	case GPIO_PORTC:
		if(Copy_u16PortValue<=Local_u16MAXValue)
		{
			GPIOC->GPIO_ODR = Copy_u16PortValue;
		}
		else
		{
			GPIOC->GPIO_ODR = Local_u16MAXValue;
		}
		break;

	}

}


void GPIO_voidSetAlternativeFunction(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copyu8AlternativeFunction)
{
	switch (Copy_u8PortID){
	case GPIO_PORTA:
		/* Set Pin Mode to Be Alternative Function */
		GPIOA->GPIO_MODER &=~(0b11<<(Copy_u8PinID*2));
		GPIOA->GPIO_MODER |=(0b10<<(Copy_u8PinID*2));
		/* Check for the First 8 Pins */
		if(Copy_u8PinID>=0 && Copy_u8PinID<8)
		{
			/* Set Alternative Function value at ARFL*/
			/* Bit Masking */
			GPIOA->GPIO_AFRL &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOA->GPIO_AFRL|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);
		}
		else if(Copy_u8PinID>=8 && Copy_u8PinID<16)
		{
			/* Set Alternative Function value at ARFH*/
			/* Bit Masking */
			Copy_u8PinID -=8;
			GPIOA->GPIO_AFRH &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOA->GPIO_AFRH|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);

		}

		break;
	case GPIO_PORTB:
		/* Set Pin Mode to Be Alternative Function */
		GPIOB->GPIO_MODER &=~(0b11<<(Copy_u8PinID*2));
		GPIOB->GPIO_MODER |=(0b10<<(Copy_u8PinID*2));
		/* Check for the First 8 Pins */
		if(Copy_u8PinID>=0 && Copy_u8PinID<8)
		{
			/* Set Alternative Function value at ARFL*/
			/* Bit Masking */
			GPIOB->GPIO_AFRL &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOB->GPIO_AFRL|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);
		}
		else if(Copy_u8PinID>=8 && Copy_u8PinID<16)
		{
			/* Set Alternative Function value at ARFH*/
			/* Bit Masking */
			Copy_u8PinID -=8;
			GPIOB->GPIO_AFRH &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOB->GPIO_AFRH|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);

		}
		break;
	case GPIO_PORTC:
		/* Set Pin Mode to Be Alternative Function */
		GPIOC->GPIO_MODER &=~(0b11<<(Copy_u8PinID*2));
		GPIOC->GPIO_MODER |=(0b10<<(Copy_u8PinID*2));
		/* Check for the First 8 Pins */
		if(Copy_u8PinID>=0 && Copy_u8PinID<8)
		{
			/* Set Alternative Function value at ARFL*/
			/* Bit Masking */
			GPIOC->GPIO_AFRL &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOC->GPIO_AFRL|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);
		}
		else if(Copy_u8PinID>=8 && Copy_u8PinID<16)
		{
			/* Set Alternative Function value at ARFH*/
			/* Bit Masking */
			Copy_u8PinID -=8;
			GPIOC->GPIO_AFRH &=~(0b1111 <<(Copy_u8PinID*4));
			GPIOC->GPIO_AFRH|=(Copyu8AlternativeFunction <<Copy_u8PinID*4);

		}
		break;
	}


}

