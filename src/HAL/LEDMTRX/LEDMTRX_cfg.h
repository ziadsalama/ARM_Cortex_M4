
#ifndef LEDMTRX_CFG_H_
#define LEDMTRX_CFG_H_

/* Size of Matrix */
#define COL_NUM               8

#define ROW_NUM               8



/*********************************** Configuration Macros ***************************************/
/* Available option for for port value : GPIO_PORTA , GPIO_PORTB , GPIO_PORTC */
/* Available option for for port value : 0->15  */
/* Note  :  Avoid Forbidden Pins : A13 , A14 , A15   ----  B2 , B3 , B4 */
#define COL0                         GPIO_PORTA,PIN0
#define COL1                         GPIO_PORTA,PIN1
#define COL2                         GPIO_PORTA,PIN2
#define COL3                         GPIO_PORTA,PIN3
#define COL4                         GPIO_PORTA,PIN4
#define COL5                         GPIO_PORTA,PIN5
#define COL6                         GPIO_PORTA,PIN6
#define COL7                         GPIO_PORTA,PIN7


#define ROW0                         GPIO_PORTB,PIN0
#define ROW1                         GPIO_PORTB,PIN1
#define ROW2                         GPIO_PORTB,PIN5
#define ROW3                         GPIO_PORTB,PIN6
#define ROW4                         GPIO_PORTB,PIN7
#define ROW5                         GPIO_PORTB,PIN8
#define ROW6                         GPIO_PORTB,PIN9
#define ROW7                         GPIO_PORTB,PIN10


#endif
