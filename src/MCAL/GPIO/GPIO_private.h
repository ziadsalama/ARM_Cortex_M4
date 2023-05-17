


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct
{
	u32 GPIO_MODER;  // This Register is to Set The Mode of any Pin
	u32 GPIO_OTYPER; // This Register is to Set The Type of Output Pins[PP/OD]
	u32 GPIO_OSPEEDR;// This Register is Set The Speed of Output Pins
	u32 GPIO_PUPDR;  // This Register is Select Whether Pull Up or Pull Down Input
	u32 GPIO_IDR;    // This Register is to get the Value of input Pins
	u32 GPIO_ODR;    // This Register is to Set the value of Output Pins
	u32 GPIO_BSRR;    // This Register is to Set or Reset any Pin in Atomic Access
	u32 GPIO_LCKR;    // This Register to Lock a Behavior of any GPIO Pin
	u32 GPIO_AFRL;    // This Register to Set The Alternate Function of Pins From 0 to 7 on any Port
	u32 GPIO_AFRH;    // This Register to Set The Alternate Function of Pins From 8 to 15 on any Port

}GPIO_Reg_t;


/*Pointer to Struct */
#define GPIOA                   ((volatile GPIO_Reg_t*)(0x40020000))
#define GPIOB                   ((volatile GPIO_Reg_t*)(0x40020400))
#define GPIOC                   ((volatile GPIO_Reg_t*)(0x40020800))






#endif
