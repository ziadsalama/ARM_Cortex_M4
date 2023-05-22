
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/
/* 16 macro for EXTI lines */

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
