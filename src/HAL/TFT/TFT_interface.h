
#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/






/************************ Functions *****************************************************/
void TFT_voidSendCmd(u8 Copy_u8Cmd);

void TFT_voidSendData(u8 Copy_u8Data);

void TFT_voidDisplayImage(u16 Copy_u16ImageArray[]);

void TFT_voidInit(void);

void TFT_voidResetSequence(void);

void TFT_voidDisplayColor(u16 Copy_u16Color);

void TFT_voidDisplayColorOverRect(u16 Copy_u16Color , u16 X1 , u16 X2 , u16 Y1 , u16 Y2);

/******************************************************************************************/
#endif
