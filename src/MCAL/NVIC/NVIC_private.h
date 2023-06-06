
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*VectKey Macro */
#define VECT_KEY                (0x05FA0000)



/* NVIC Registers  */
typedef struct
{
	u32 ISER[8];         // This Register is to Set Enable Register
	u32 Reserved1[24];   // Reserved
	u32 ICER[32];       // This Register is to Clear Enable Register
	u32 Reserved2[24];   // Reserved
	u32 ISPR[32];      // This Register is Set Pending Register
	u32 ICPR[32];      // This Register is Clear Pending Register
	u32 IABR[64];     // This Register is to Set Active Bit Register
	u8 IPR[240];      // This Register is to Set Interrupt priority Register
						/* instead of 8 Registers, each has 4 bytes */
}NVIC_Reg_t;

#define NVIC                  ((NVIC_Reg_t*)(0xE000E100))

/*Register to Configure how to Divide Software Priority Between Group and Sub For the System */
#define SCB_AIRCR             (*(volatile u32*)(0xE000ED0C))


#define GROUP4_SUB0             (0)  /*Support 16 group(nesting level up to 16 )*/
#define GROUP3_SUB1             (4)  /*Support 8 group and 2 subpriorities */
#define GROUP2_SUB2             (5)  /*Support 4 group and 4 subpriorities*/
#define GROUP1_SUB3             (6)  /*Support 2 group and 8 subpriorities*/
#define GROUP0_SUB4             (7)  /*Support 0 group and 16 subpriorities(no nesting )*/

#define NVIC_EXTI1                 7
#endif
