
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/





/************************ Functions *****************************************************/

/*this function is to initialize NVIC , Set Priority Configuration */
void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptID);

void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptID);


void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptID);


void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptID);


u8 NVIC_voidReadActiveFlag(u8 Copy_u8InterruptID);

void NVIC_voidSetSWPriority(u8 Copy_u8SWPriority , u8 Copy_u8InterruptID);

/******************************************************************************************/
#endif
