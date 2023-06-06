


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/* SPI Registers  */
typedef struct
{
	volatile u32 CR1;          //
	volatile u32 CR2;         //
	volatile u32 SR;          //
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;

}SPI_Reg_t;


#define SPI                  ((SPI_Reg_t*)(0x40013000))




#endif
