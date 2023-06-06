
#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_cfg.h"

/********************************** Global variables ************************************/


/************************************ Function Implementation ***********/

void SPI_voidInit(void)
{
	/* Set Clock Phase -> High  -> Send First  */
	SET_BIT(SPI->CR1 , 0 );

	/* Set Clock Polarity  -> High*/
	SET_BIT(SPI->CR1 , 1);

	/* Enable Master Options  */
	SET_BIT(SPI->CR1 ,2);

	/* Set Boud Rate -> 000  -> Prescaler = 2  ,   by bit Masking */
	SPI->CR1 &=~((0b111)<< 3);
	SPI->CR1 |=(BOUDRATE_2 << 3);

	/* Set The Node to be Master by SoftWare */
	SET_BIT(SPI->CR1 , 8);
	SET_BIT(SPI->CR1 , 9);

	/* Set MSB First */
	CLR_BIT(SPI->CR1 ,7);

	/* Frame Format -> 8-Bit or 16-Bit */
	CLR_BIT(SPI->CR1 ,11);

	/* Enable SPI Peripheral */
	SET_BIT(SPI->CR1 , 6);   // SPI Enable

}

u8 SPI_u8Transceiver(u8 Copy_u8TransmittedData)
{
	/* Set Data To Be Sent Into Data Register */
	SPI->DR = Copy_u8TransmittedData;

	/* Pooling till the end of Data Transfer */
	while((READ_BIT(SPI->SR ,7)) == 1);    // Pooling over Busy Flag

	/* Get The Value of the Received Data */
	return SPI->DR;

}



/************************************** ISRs *************************************/
