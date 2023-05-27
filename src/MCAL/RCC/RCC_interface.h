
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/******************************** Enum to Return Error_State **********************************************/
typedef enum
{
	OK,
	Invalid_Peripheral_ID,
	Wrong_Bus

}RCC_ErrorState_t;






/************************** Interfacing Macros ********************************************/
#define RCC_AHB1             1
#define RCC_AHB2             2
#define RCC_APB1             3
#define RCC_APB2             4

/* Private Macros */
#define RCC_GPIOA_EN         0
#define RCC_GPIOB_EN         1
#define RCC_GPIOC_EN         2

#define RCC_SYSCFG_EN        14


/* This Function is to Enable Peripheral Clock */
RCC_ErrorState_t RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

/*This Function is to Disable Peripheral Clock */
RCC_ErrorState_t RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

/*This Function is to Set System Clock */
void RCC_voidSetSystemClock(void);

#endif
