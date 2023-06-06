

#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"

#include "../LEDMTRX/LEDMTRX_interface.h"
#include "../LEDMTRX/LEDMTRX_private.h"
#include "../LEDMTRX/LEDMTRX_cfg.h"

/********************************** Global variables ************************************/
/* Global Array to iterate over led matrix rows*/
u8 Local_u8RowsArray[ROW_NUM][2]={ROW0,ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7};
/* Global Array to iterate over led matrix Columns*/
u8 Local_u8ColsArray[COL_NUM][2]={COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7};

/************************************ Function Implementation ***********/

void LEDMTRX_voidInit(void)
{
	/* Local Iterator For iterate over Cloumns and rows */
	u8 Local_u8Iterator = 0;
	/* Set All Rows Pins To Be Output , PushPull , LowSpeed */
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8RowsArray[Local_u8Iterator][0],Local_u8RowsArray[Local_u8Iterator][1],GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	}

	/* Set All  Columns Pins To Be Output , PushPull , LowSpeed */
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8ColsArray[Local_u8Iterator][0],Local_u8ColsArray[Local_u8Iterator][1],GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	}
	/* Diactivate all Columns */
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8Iterator][0],Local_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}
	/* Set All Leds Off */
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8Iterator][1],Local_u8RowsArray[Local_u8Iterator][1],GPIO_OUTPUT_LOW);
	}
}


void LEDMTRX_voidTurnOff(void)
{
	/* Local Iterator For iterate over Cloumns and rows */
	u8 Local_u8Iterator = 0;
	/* Diactivate all Columns */
	for(Local_u8Iterator=0;Local_u8Iterator<COL_NUM;Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8Iterator][0],Local_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}
	/* Set All Leds Off */
	for(Local_u8Iterator=0;Local_u8Iterator<ROW_NUM;Local_u8Iterator++)
	{
		GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8Iterator][0],Local_u8RowsArray[Local_u8Iterator][1],GPIO_OUTPUT_LOW);
	}

}



void LEDMTRX_voidDisplayPattern(u8 Copy_au8PatternArray[],u8 Copy_u8Period)
{
	/* Local Iterator to loop over Cloumns  */
	u8 Local_u8ColsIterator = 0;
	/* Local Iterator to loop over ROWS  */
	u8 Local_u8RowsIterator = 0;
	u8 Iterator = 0;
	for(Iterator=0 ; Iterator<=Copy_u8Period ; Iterator++)
	{


		for(Local_u8ColsIterator=0;Local_u8ColsIterator<COL_NUM;Local_u8ColsIterator++)
		{
			/* Activate Current -> Set Its Pins To be Low Output   */
			GPIO_voidSetOutputPinValue(Local_u8ColsArray[Local_u8ColsIterator][0],Local_u8ColsArray[Local_u8ColsIterator][1],GPIO_OUTPUT_LOW);

			/* Loop Over all Rows to set the Corresponding Value -> 0 or 1 from the Pattern Array Index*/
			for(Local_u8RowsIterator=0;Local_u8RowsIterator<ROW_NUM;Local_u8RowsIterator++)
			{
				/* Set the Value of the Row to be the value of the corresponding bit for the row of
				 * the corresponding Pattern index for the activated column  */
				GPIO_voidSetOutputPinValue(Local_u8RowsArray[Local_u8RowsIterator][0],Local_u8RowsArray[Local_u8RowsIterator][1]
																															  ,READ_BIT(Copy_au8PatternArray[Local_u8ColsIterator],Local_u8RowsIterator));
			}
			/* Set Delay = 2.5 msec between every activation */
			SYSTICK_voidDelaySync(2500);
			/* Led Matrix Reset Before the new Activation  */
			LEDMTRX_voidTurnOff();
		}
	}
}



/**********************************************************************************************************/






