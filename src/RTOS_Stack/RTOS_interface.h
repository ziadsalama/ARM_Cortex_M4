
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/



/********************************************************************************************************/

/* RTOS */
typedef struct
{
	void(*TaskPtrToFunction)(void);    // pointer to the task c function
	u32 Periodicity;
	u8 State ;           // State of task -> Resumed , Suspend
}Task_t;


/************************ Functions *****************************************************/
/*this function is to initialize RTOS and Run OS */
void RTOS_voidRunOS(void);

void RTOS_voidCreatTask(u32 Copy_u32TaskPeriodicity ,void(*Copy_PtrToFunction)(void));

void Scheduler(void);
void RTOS_voidResumeTask(u8 Copy_u8TaskPeriority);

void RTOS_voidSuspendTask(u8 Copy_u8TaskPeriority);

void RTOS_voidDeleteTask(u8 Copy_u8TaskPeriority);


/******************************************************************************************/
#endif
