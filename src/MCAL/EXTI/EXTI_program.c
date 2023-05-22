/*
 * NVIC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: ziad
 */


#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"



void EXTI_voidEnableInterrupt(u8 Copy_u8InterruptID, void(*CopyPtrToFunc)(void))
{
	SET_BIT(EXTI->IMR , Copy_u8InterruptID);

}
void EXTI_voidDisableInterrupt(u8 Copy_u8InterruptID)
{
	CLR_BIT(EXTI->IMR , Copy_u8InterruptID);

}
void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal, u8 Copy_u8InterruptID)
{
	switch(Copy_u8SenseSignal)
	{
	case FALLING_EDGE:
		CLR_BIT(EXTI->FTSR ,Copy_u8InterruptID);
		SET_BIT(EXTI->RTSR ,Copy_u8InterruptID);
		break;
	case RISING_EDGE:
		CLR_BIT(EXTI->RTSR ,Copy_u8InterruptID);
		SET_BIT(EXTI->FTSR ,Copy_u8InterruptID);
			break;
	case ON_CHANGE:
		SET_BIT(EXTI->RTSR ,Copy_u8InterruptID);
		SET_BIT(EXTI->FTSR ,Copy_u8InterruptID);
			break;
	}


}

void EXTI_voidSetLinePort(u8 Copy_u8InterruptID, u8 Copy_u8PortID)
{


}
