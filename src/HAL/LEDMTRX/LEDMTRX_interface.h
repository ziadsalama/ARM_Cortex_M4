
#ifndef LEDMTRX_INTERFACE_H_
#define LEDMTRX_INTERFACE_H_


/************************** Interfacing Macros ********************************************/
/* 16 macro for EXTI lines */





/************************** Functions *****************************************************/

/*this function shall initialize led matrix */
void LEDMTRX_voidInit(void);

/*this function is to Display Specific pattern over led matrix  */
void LEDMTRX_voidDisplayPattern(u8 Copy_au8PatternArray[],u8 Copy_u8Period);

/*This Function is to turn led matrix of */
void LEDMTRX_voidTurnOff(void);




/******************************************************************************************/
#endif
