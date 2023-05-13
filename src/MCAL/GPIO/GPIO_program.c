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
		/*Set Direction of The Pin to be Output by Bit Masking */
		GPIOA->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		GPIOA->GPIO_MODER|=(0b01<<(Copy_u8PinID*2));

		/*Set Speed of The Pin By Bit Masking */
		GPIOA->GPIO_OSPEEDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOA->GPIO_OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));

		/* Set Type of Output Pin*/
		WRITE_BIT(GPIOA->GPIO_OTYPER,Copy_u8PinID,Copy_u8PinType);

		break;

	case GPIO_PORTB:
		/*Set Direction of The Pin to be Output by Bit Masking */
		GPIOB->GPIO_MODER&=~(0b11<<(Copy_u8PinID*2));
		GPIOB->GPIO_MODER|=(0b01<<(Copy_u8PinID*2));

		/*Set Speed of The Pin By Bit Masking */
		GPIOB->GPIO_OSPEEDR&=~(0b11<<(Copy_u8PinID*2));
		GPIOB->GPIO_OSPEEDR|=(Copy_u8PinSpeed<<(Copy_u8PinID*2));

		/* Set Type of Output Pin*/
		WRITE_BIT(GPIOB->GPIO_OTYPER,Copy_u8PinID,Copy_u8PinType);

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
