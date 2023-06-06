

#include "../LIB/BIT_MATHS.h"
#include "../LIB/STD_LIB.h"

#include "../MCAL/SYSTICK/SYSTICK_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_cfg.h"


/*************************************** Global Variables ************************************/
Task_t TaskArray[TASK_NUM] = {{NULL}};



/************************** Function Impementation *******************************************/
void RTOS_voidRunOS(void)
{
	SYSTICK_voidSystickInit();           /* Initialize Systick */
	SYSTICK_voidDelayAsyncPeriodic(1000 ,Scheduler );    /* System Tick -> 1000us -> 1ms*/
															//System Tick must bs Configurable
}

void RTOS_voidCreatTask(u32 Copy_u32TaskPeriodicity ,void(*Copy_PtrToFunction)(void))
{
	/* Local variable to iterate over system tasks */
	static u8 Local_u8TaskIterator=0 ;


	/* Looping Over Tasks */
	if(Local_u8TaskIterator<TASK_NUM)
	{
		/* Make Sure That index is empty */
		if(TaskArray[Local_u8TaskIterator].TaskPtrToFunction == NULL)
		{
			TaskArray[Local_u8TaskIterator].Periodicity = Copy_u32TaskPeriodicity;
			TaskArray[Local_u8TaskIterator].TaskPtrToFunction = Copy_PtrToFunction;
			TaskArray[Local_u8TaskIterator].State = RESUMED ;    /*Any task initially resumed  */
		}
		Local_u8TaskIterator++;

	}
}

void Scheduler(void)
{
	/* Local variable to iterate over system tasks */
	u8 Local_u8TaskIterator=0 ;

	/* Local Variable related to periodicity Calculations*/
	static u32 Local_u32SystemTick=0;

	/* Increment System Tick */
	Local_u32SystemTick++ ;

	/* Loop Over Tasks */
	for(Local_u8TaskIterator=0;Local_u8TaskIterator<TASK_NUM;Local_u8TaskIterator++)
	{
		/* Make Sure That the Task is not Suspended */
		if(TaskArray[Local_u8TaskIterator].State == RESUMED)
		{
			/* Make Sure That the Sysytem Tick Mathes the task Priodicity*/
			if(Local_u32SystemTick % TaskArray[Local_u8TaskIterator].Periodicity == 0)
			{
				/* Make Sure That index is empty */
				if(TaskArray[Local_u8TaskIterator].TaskPtrToFunction != NULL)
				{
					/* Call Task C Function */
					TaskArray[Local_u8TaskIterator].TaskPtrToFunction();
				}

			}
		}
		else
		{
			/* do nothing */
		}
	}
}



void RTOS_voidResumeTask(u8 Copy_u8TaskPeriority)
{
	TaskArray[Copy_u8TaskPeriority].State = RESUMED;

}

void RTOS_voidSuspendTask(u8 Copy_u8TaskPeriority)
{
	TaskArray[Copy_u8TaskPeriority].State = SUSPENDED;

}

void RTOS_voidDeleteTask(u8 Copy_u8TaskPeriority)
{
	TaskArray[Copy_u8TaskPeriority].TaskPtrToFunction = NULL;
}
