#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "TFT_interface.h"
#include "TFT_cfg.h"
#include "TFT_private.h"

/********************************** Global variables ************************************/


/************************************ Function Implementation ***********/
void TFT_voidSendCmd(u8 Copy_u8Cmd)
{
	/* to  store the received data of spi*/
	u8 Local_u8Dummy;
	/* Set Control pin of TFT -> A0 to be Low*/
	GPIO_voidSetOutputPinValue(CTRL_PORT , CTRL_PIN, GPIO_OUTPUT_LOW);

	/* Send Command over SPI*/
	Local_u8Dummy = SPI_u8Transceiver(Copy_u8Cmd);


}
void TFT_voidSendData(u8 Copy_u8Data)
{
	/* to store the received data of spi*/
	u8 Local_u8Dummy;
	/* Set Control pin of TFT -> A0 to be High */
	GPIO_voidSetOutputPinValue(CTRL_PORT , CTRL_PIN, GPIO_OUTPUT_HIGH);

	/* Send Command over SPI*/
	Local_u8Dummy = SPI_u8Transceiver(Copy_u8Data);

}

void TFT_voidDisplayImage(u16 Copy_u16ImageArray[])
{
	u8 Local_u8HighByte = 0 ;
	u8 Local_u8LowByte = 0 ;
	u16 Local_u16Iterator;
	/* Set X */
	TFT_voidSendCmd(0x2A);
	TFT_voidSendData(0);     // High Byte of Start
	TFT_voidSendData(0);     // Low Byte of Start
	TFT_voidSendData(0);     // High Byte of End
	TFT_voidSendData(127);     // Low Byte of End

	/* Set Y */
	TFT_voidSendCmd(0x2B);
	TFT_voidSendData(0);     // High Byte of Start
	TFT_voidSendData(0);     // Low Byte of Start
	TFT_voidSendData(0);     // High Byte of End
	TFT_voidSendData(159);     // Low Byte of End

	/* Send Display Command  -> 0x2C*/
	TFT_voidSendCmd(0x2C);

	/* Loop Over Image Array Elements to get Displayed*/
	for(Local_u16Iterator=0 ; Local_u16Iterator<20480 ; Local_u16Iterator++)
	{
		 Local_u8HighByte = Copy_u16ImageArray[Local_u16Iterator]>>8 ;
		 Local_u8LowByte = (u8)Copy_u16ImageArray[Local_u16Iterator];
		/* Send High Bytes of Target Element */
		TFT_voidSendData(Local_u8HighByte);

		/* Send Low Bytes of Target Element */
		TFT_voidSendData(Local_u8LowByte);
	}

}

void TFT_voidInit(void)
{
	/* Set Configuration of Micro Controller Pins */
	/* A0 (CTRL) Pin -> Output */
	GPIO_voidInitOutputPin(CTRL_PORT, CTRL_PIN , GPIO_PUSH_PULL , GPIO_LOW_SPEED);

	/*Reset Pin -> OUtput */
	GPIO_voidInitOutputPin(RESET_PORT, RESET_PIN , GPIO_PUSH_PULL , GPIO_LOW_SPEED);

	/* MOSI of SPI1  -> A7 -> AF05*/
	GPIO_voidSetAlternativeFunction(GPIO_PORTA , 7, GPIO_AF5);

	/* SCK of SPI1  -> A5 ->AF05*/
	GPIO_voidSetAlternativeFunction(GPIO_PORTA , 5, GPIO_AF5);

	/* Apply Reset Sequence over Reset Pin */
	TFT_voidResetSequence();

	/* Send Sleep Out Command -> 0x11*/
	TFT_voidSendCmd(0x11);

	/*Delay for 150ms*/
	SYSTICK_voidDelaySync(150000);

	/* Send Color Mode Command -> 0x3A ,  Following by The Selected mode */
	/* Color Standard -> RGB565  -> 0x05 */
	TFT_voidSendCmd(0x3A);
	TFT_voidSendData(0x05);

	/* Send Display On Command -> 0x29*/
	TFT_voidSendCmd(0x29);
}

void TFT_voidResetSequence(void)
{
	/* Set Reset Pin -> High For 100us*/
	GPIO_voidSetOutputPinValue(RESET_PORT , RESET_PIN , GPIO_OUTPUT_HIGH);
	SYSTICK_voidDelaySync(100);

	/* Set Reset Pin -> Low For 1us*/
	GPIO_voidSetOutputPinValue(RESET_PORT , RESET_PIN , GPIO_OUTPUT_LOW);
	SYSTICK_voidDelaySync(1);

	/* Set Reset Pin -> High For 100us*/
	GPIO_voidSetOutputPinValue(RESET_PORT , RESET_PIN , GPIO_OUTPUT_HIGH);
	SYSTICK_voidDelaySync(100);

	/* Set Reset Pin -> LOW For 100us*/
	GPIO_voidSetOutputPinValue(RESET_PORT , RESET_PIN , GPIO_OUTPUT_LOW);
	SYSTICK_voidDelaySync(100);

	/* Set Reset Pin -> High For 120000us*/
	GPIO_voidSetOutputPinValue(RESET_PORT , RESET_PIN , GPIO_OUTPUT_HIGH);
	SYSTICK_voidDelaySync(120000);



}


void TFT_voidDisplayColor(u16 Copy_u16Color)
{
	u8 Local_u8HighByte = 0 ;
		u8 Local_u8LowByte = 0 ;
		u16 Local_u16Iterator;
		/* Set X */
		TFT_voidSendCmd(0x2A);
		TFT_voidSendData(0);     // High Byte of Start
		TFT_voidSendData(0);     // Low Byte of Start
		TFT_voidSendData(0);     // High Byte of End
		TFT_voidSendData(127);     // Low Byte of End

		/* Set Y */
		TFT_voidSendCmd(0x2B);
		TFT_voidSendData(0);     // High Byte of Start
		TFT_voidSendData(0);     // Low Byte of Start
		TFT_voidSendData(0);     // High Byte of End
		TFT_voidSendData(159);     // Low Byte of End

		/* Send Display Command  -> 0x2C*/
		TFT_voidSendCmd(0x2C);

		/* Loop Over TFT Pixels to display the same value*/
		for(Local_u16Iterator=0 ; Local_u16Iterator<20480 ; Local_u16Iterator++)
		{
			 Local_u8HighByte = Copy_u16Color>>8 ;
			 Local_u8LowByte = (u8)Copy_u16Color;
			/* Send High Bytes of Target Element */
			TFT_voidSendData(Local_u8HighByte);

			/* Send Low Bytes of Target Element */
			TFT_voidSendData(Local_u8LowByte);
		}

}

void TFT_voidDisplayColorOverRect(u16 Copy_u16Color , u16 X1 , u16 X2 , u16 Y1 , u16 Y2)
{
	/* local var to Rectangle Area */
	u32 Local_16RectArea = (X2-X1)*(Y2-Y1);
	u8 Local_u8HighByte = 0 ;
			u8 Local_u8LowByte = 0 ;
			u16 Local_u16Iterator;
			/* Set X */
			TFT_voidSendCmd(0x2A);
			TFT_voidSendData(0);     // High Byte of Start
			TFT_voidSendData(X1);     // Low Byte of Start
			TFT_voidSendData(0);     // High Byte of End
			TFT_voidSendData(X2);     // Low Byte of End

			/* Set Y */
			TFT_voidSendCmd(0x2B);
			TFT_voidSendData(0);     // High Byte of Start
			TFT_voidSendData(Y1);     // Low Byte of Start
			TFT_voidSendData(0);     // High Byte of End
			TFT_voidSendData(Y2);     // Low Byte of End

			/* Send Display Command  -> 0x2C*/
			TFT_voidSendCmd(0x2C);

			/* Loop Over TFT Pixels to display the same value*/
			for(Local_u16Iterator=0 ; Local_u16Iterator<Local_16RectArea ; Local_u16Iterator++)
			{
				 Local_u8HighByte = Copy_u16Color>>8 ;
				 Local_u8LowByte = (u8)Copy_u16Color;
				/* Send High Bytes of Target Element */
				TFT_voidSendData(Local_u8HighByte);

				/* Send Low Bytes of Target Element */
				TFT_voidSendData(Local_u8LowByte);
			}

}


/************************************** ISRs *************************************/
