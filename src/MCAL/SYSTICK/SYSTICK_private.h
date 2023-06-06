


#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


/* SYSTICK Registers  */
typedef struct
{
	volatile u32 CTRL;          // SysTick control and status register
	volatile u32 LOAD;         //  SysTick reload value register
	volatile u32 VAL;          // SysTick current value register
	volatile u32 CALIB;        // SysTick calibration value register


}SYSTICK_Reg_t;


#define SYSTICK                  ((SYSTICK_Reg_t*)(0xE000E010))

#define STK_ENABLE                      0
#define STK_TICKINT                     1
#define STK_COUNTFLAG                   16

#define SINGLE                     0
#define PERIODIC                   1



#endif
