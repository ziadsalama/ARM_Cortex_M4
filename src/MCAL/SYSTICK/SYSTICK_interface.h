
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/
/* 16 macro for EXTI lines */





/************************ Functions *****************************************************/

/* This Function is to Initialization  */
void SYSTICK_voidSystickInit(void);
/* This Function is to Run Systick  */
void SYSTICK_voidRunSystick(void);
/* This Function is to Stop Systick  */
void SYSTICK_voidRunSystick(void);
/* This Function is to make delay sync Micro Second  */
void SYSTICK_voidDelaySync(u32 Copy_u32Delay_us);

/* This Function is to make delay sync Milli Second  */
void SYSTICK_voidDelaySyncMilliSecond(u32 Copy_u32Delay_ms);


/* This Function is to make delay Async -> Single  */
void SYSTICK_voidDelayAsyncSingle(u32 Copy_u32Delay_us, void(*Copy_PtrToFunction)(void));


/* This Function is to make delay Async -> Periodic  */
void SYSTICK_voidDelayAsyncPeriodic(u32 Copy_u32Delay_us, void(*Copy_PtrToFunction)(void));

/* This Function is to get Remainning Time */
u32 SYSTICK_u32GetRemainingTime(void);

/* This Function is to get Elapsed Time */
u32 SYSTICK_u32GetElapsedTime(void);

/******************************************************************************************/
#endif
