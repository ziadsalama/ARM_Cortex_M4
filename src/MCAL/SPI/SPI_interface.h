
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/

/************************** Interfacing Macros ********************************************/
/* 16 macro for EXTI lines */

#define BOUDRATE_2                 0     // value of prescaler



/************************ Functions *****************************************************/
void SPI_voidInit(void);

u8 SPI_u8Transceiver(u8 Copy_u8TransmittedData);



/******************************************************************************************/
#endif
