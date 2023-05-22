/*
 * NVIC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: ziad
 */


#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_cfg.h"


void NVIC_voidInit(void)
{
	/*local variable for the value of AIRCR Register */
	u32 Local_u32RegisterValue;

	/* Set Configuration of System Software Priorities */
	Local_u32RegisterValue= VECT_KEY | (PRIORITY_CONFIG<<8);

	/* Assign the value to AIRCR Register */
	SCB_AIRCR = Local_u32RegisterValue;

}


void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptID)
{
	u8 Local_u8RegisterNumber=Copy_u8InterruptID/32;
	u8 Local_u8BitNumber=Copy_u8InterruptID%32;
	NVIC->ISER[Local_u8RegisterNumber]=1<<(Local_u8BitNumber);

}

void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptID)
{
	u8 Local_u8RegisterNumber=Copy_u8InterruptID/32;
	u8 Local_u8BitNumber=Copy_u8InterruptID%32;
	NVIC->ICER[Local_u8RegisterNumber]=1<<(Local_u8BitNumber);

}


void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	u8 Local_u8RegisterNumber=Copy_u8InterruptID/32;
	u8 Local_u8BitNumber=Copy_u8InterruptID%32;
	NVIC->ISPR[Local_u8RegisterNumber]=1<<(Local_u8BitNumber);

}


void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	u8 Local_u8RegisterNumber=Copy_u8InterruptID/32;
	u8 Local_u8BitNumber=Copy_u8InterruptID%32;
	NVIC->ICPR[Local_u8RegisterNumber]=1<<(Local_u8BitNumber);
}


u8 NVIC_voidReadActiveFlag(u8 Copy_u8InterruptID)
{
	u8 Local_u8RegisterNumber=Copy_u8InterruptID/32;
	u8 Local_u8BitNumber=Copy_u8InterruptID%32;
	u8 Local_u8ActiveFlag;
	//Local_u8ActiveFlag=NVIC->IABR[Local_u8RegisterNumber]>>(Local_u8BitNumber);
	Local_u8ActiveFlag=READ_BIT(NVIC->IABR[Local_u8RegisterNumber],Local_u8BitNumber);
	return Local_u8ActiveFlag;
}


void NVIC_voidSetSWPriority(u8 Copy_u8SWPriority , u8 Copy_u8InterruptID)
{
	/* Setting Both group and Sub-Priority into the High 4 bits  */
	NVIC->IPR[Copy_u8InterruptID]=Copy_u8SWPriority<<4 ;

	/*TODO enhance the function  group and sub */

}
