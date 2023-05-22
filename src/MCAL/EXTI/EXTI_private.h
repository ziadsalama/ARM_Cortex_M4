


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_




/* EXTI Registers  */
typedef struct
{
	u32 IMR;         //
	u32 EMR;       //
	u32 RTSR;      //
	u32 FTSR;      //
	u32 SWIER;     //
	u32 PR;      //

}EXTI_Reg_t;

#define EXTI                  ((EXTI_Reg_t*)(0x40013C00))




#endif
