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

/********************************** Global variables ************************************/
/*global pointer to set callback for EXTI0 */
//void(*Global_PtrToFunc_EXTI0)(void) = NULL;

/*global pointer to set callback for EXTI1 */
//void(*Global_PtrToFunc_EXTI1)(void) = NULL;

/* Array of global  Pointer to function to set callBack fo external interrupt   */
void(*Global_PtrToFunc_EXTI[16])(void) = {NULL};

/************************************ Function Implementation ***********/
void EXTI_voidEnableInterrupt(u8 Copy_u8InterruptID, void(*CopyPtrToFunc)(void))
{
	/*set call back Function */
	//Global_PtrToFunc_EXTI0=CopyPtrToFunc;
	if(CopyPtrToFunc!=NULL)
	{
	Global_PtrToFunc_EXTI[Copy_u8InterruptID]=CopyPtrToFunc;
	}
	else
	{
		/*do nothing */
	}
	/*Enable Interrupt */
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
	u8 Local_u8IndexNumber=Copy_u8InterruptID/4;
	u8 Local_u8BitNumber=((Copy_u8InterruptID%4)*4);

	/* System Configuration peripheral */
	/*1) Clear Target bits to set the new configuration (bit masking)*/
	SYSCFG->EXTICR[Local_u8IndexNumber] &=~(0b1111<<Local_u8BitNumber);

	/*2) Set the new Configuration  */
	SYSCFG->EXTICR[Local_u8IndexNumber] |= Copy_u8PortID<<Local_u8BitNumber;
}

static void EXTI_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	/*Clear Interrupt Flag after executing the Interrupt ISR*/
	SET_BIT(EXTI->PR,Copy_u8InterruptID);
}


/************************************ ISRs**************************************************/

/*ISR for External Interrupt 0  */
void EXTI0_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[0]();
	EXTI_voidClearPendingFlag(EXTI_LINE0);
}
/*ISR for External Interrupt 1  */
void EXTI1_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[1]();
	EXTI_voidClearPendingFlag(EXTI_LINE1);
}
/*ISR for External Interrupt 2  */
void EXTI2_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[2]();
	EXTI_voidClearPendingFlag(EXTI_LINE2);
}
/*ISR for External Interrupt 3  */
void EXTI3_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[3]();
	EXTI_voidClearPendingFlag(EXTI_LINE3);
}
/*ISR for External Interrupt 4  */
void EXTI4_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[4]();
	EXTI_voidClearPendingFlag(EXTI_LINE4);

}

