


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

}GPIO_Reg_t;


/*Pointer to Struct */
#define GPIOA                   ((volatile GPIO_Reg_t*)(0x40020000))
#define GPIOB                   ((volatile GPIO_Reg_t*)(0x40020400))
#define GPIOC                   ((volatile GPIO_Reg_t*)(0x40020800))






#endif
