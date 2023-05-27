
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/
/* 16 macro for EXTI lines */

/*16 Macro for External Interrupt  */
#define EXTI_LINE0               0
#define EXTI_LINE1               1
#define EXTI_LINE2               2
#define EXTI_LINE3               3
#define EXTI_LINE4               4
#define EXTI_LINE5               5
#define EXTI_LINE6               6
#define EXTI_LINE7               7
#define EXTI_LINE8               8
#define EXTI_LINE9               9
#define EXTI_LINE10              10
#define EXTI_LINE11              11
#define EXTI_LINE12              12
#define EXTI_LINE13              13
#define EXTI_LINE14              14
#define EXTI_LINE15              15

/*3 macros for sense signal */
#define FALLING_EDGE              1
#define RISING_EDGE               2
#define ON_CHANGE                 3



/************************ Functions *****************************************************/

/*this function is to Enable Interrupt and callback for ISR */
void EXTI_voidEnableInterrupt(u8 Copy_u8InterruptID, void(*CopyPtrToFunc)(void));

/*this function is to Disable Interrupt  */
void EXTI_voidDisableInterrupt(u8 Copy_u8InterruptID);

/*this function is to Set Sense Signal  */
void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal, u8 Copy_u8InterruptID);

void EXTI_voidSetLinePort(u8 Copy_u8InterruptID, u8 Copy_u8PortID);

/******************************************************************************************/
#endif
