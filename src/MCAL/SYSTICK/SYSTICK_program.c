/*
 * NVIC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: ziad
 */


#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_cfg.h"

/********************************** Global variables ************************************/
/*global pointer to set callback for Systick  */
void(*Global_PtrToFunc_SYSTICK)(void) = NULL;

u8 Global_u8AsyncRepition = SINGLE;


/************************************ Function Implementation ***********/

void SYSTICK_voidSystickInit(void)
{
	/* Disable Interrupt , Clock Source = AHB/8 */
	/* System Clock = HSI  -> tick time = 0.5 microsecond*/
	SYSTICK->CTRL =0;

	/* Reset LOAD and VAL Registers */
	SYSTICK->LOAD = 0;
	SYSTICK->VAL = 0;

}

void SYSTICK_voidRunSystick(void)
{
	/* Start Timer / Run SYSTICK  */
		SET_BIT(SYSTICK->CTRL,STK_ENABLE);
}

void SYSTICK_voidStopSystick(void)
{
	/*Stop Timer  */
		CLR_BIT(SYSTICK->CTRL,STK_ENABLE);

		/* Reset LOAD and VAL Registers */
			SYSTICK->LOAD = 0;
			SYSTICK->VAL = 0;

}

void SYSTICK_voidDelaySync(u32 Copy_u32Delay_us)
{
	/* Disable Interrupt */
	CLR_BIT(SYSTICK->CTRL,STK_TICKINT);

	/* Set LOAD Register Value to get the Target Delay */
	SYSTICK->LOAD = Copy_u32Delay_us*2;    // register value = total dealy / tick time

	/* Start Timer / Run SYSTICK  */
//	SET_BIT(SYSTICK->CTRL,STK_ENABLE);
	SYSTICK_voidRunSystick();
	/* Polling till the end of target time */
	/* Clear Flag*/
	while(READ_BIT(SYSTICK->CTRL,STK_COUNTFLAG)==0);

	/*Stop Timer  */
//	CLR_BIT(SYSTICK->CTRL,STK_ENABLE);
//
//	/* Reset LOAD and VAL Registers */
//		SYSTICK->LOAD = 0;
//		SYSTICK->VAL = 0;
	SYSTICK_voidStopSystick();
}


void SYSTICK_voidDelaySyncMilliSecond(u32 Copy_u32Delay_ms)
{
	u32 Local_u32Value = Copy_u32Delay_ms*1000;
	SYSTICK_voidDelaySync(Local_u32Value);

}


void SYSTICK_voidDelayAsyncSingle(u32 Copy_u32Delay_us, void(*Copy_PtrToFunction)(void))
{
	/*Set Global Flag Value */
	Global_u8AsyncRepition = SINGLE;
	/* Enable Interrupt */
		CLR_BIT(SYSTICK->CTRL,STK_TICKINT);

		/* Set LOAD Register Value to get the Target Delay */
		SYSTICK->LOAD = Copy_u32Delay_us*2;    // register value = total dealy / tick time

		/* Reset Value register*/
		SYSTICK->VAL = 0;

		/* Set Call Back */
		if(Copy_PtrToFunction!=NULL)
		{
		Global_PtrToFunc_SYSTICK = Copy_PtrToFunction;
		}
		else
		{
			/* Do Nothing */
		}
		/* Start Timer / Run SYSTICK  */
		SET_BIT(SYSTICK->CTRL,STK_ENABLE);


}

void SYSTICK_voidDelayAsyncPeriodic(u32 Copy_u32Delay_us, void(*Copy_PtrToFunction)(void))
{
	/*Set Global Flag Value */
		Global_u8AsyncRepition = PERIODIC;
	/* Enable Interrupt */
			CLR_BIT(SYSTICK->CTRL,STK_TICKINT);

			/* Set LOAD Register Value to get the Target Delay */
			SYSTICK->LOAD = Copy_u32Delay_us*2;    // register value = total dealy / tick time

			/* Reset Value register*/
			SYSTICK->VAL = 0;

			/* Set Call Back */
			if(Copy_PtrToFunction!=NULL)
			{
			Global_PtrToFunc_SYSTICK = Copy_PtrToFunction;
			}
			else
			{
				/* Do Nothing */
			}

			/* Start Timer / Run SYSTICK  */
			SET_BIT(SYSTICK->CTRL,STK_ENABLE);

}

u32 SYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK->VAL;

}

u32 SYSTICK_u32GetElapsedTime(void)
{

	return (SYSTICK->LOAD - SYSTICK->VAL) ;

}



/************************************** ISRs *************************************/
/* Systick Handler */
void Systick_Handler(void)
{
	switch(Global_u8AsyncRepition)
	{

	case SINGLE :
		/* Call Application Function */
			Global_PtrToFunc_SYSTICK();

			/* Stop Counting */
			/*Stop Timer  */
			CLR_BIT(SYSTICK->CTRL,STK_ENABLE);

		break;
	case PERIODIC :

		/* Call Application Function */
			Global_PtrToFunc_SYSTICK();


		break;
	}
}
