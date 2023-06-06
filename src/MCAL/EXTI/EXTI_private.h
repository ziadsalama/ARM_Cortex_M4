


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_




/* EXTI Registers  */
typedef struct
{
	u32 IMR;         //Interrupt mask register
	u32 EMR;       // Event mask register
	u32 RTSR;      // Rising trigger selection register
	u32 FTSR;      // Falling trigger selection register
	u32 SWIER;     // Software interrupt event register
	u32 PR;      // Pending register

}EXTI_Reg_t;



/* SYSCFG Registers  */
typedef struct
{
	u32 MEMRMP;         //
	u32 PMC;       //
	u32 EXTICR[4];      //

}SYSCFG_Reg_t;

#define EXTI                  ((EXTI_Reg_t*)(0x40013C00))

#define SYSCFG                  ((SYSCFG_Reg_t*)(0x40013800))


#endif
