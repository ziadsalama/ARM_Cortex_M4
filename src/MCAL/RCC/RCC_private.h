


#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_





/* System Clock Configuration */
#define  HSI                  1
#define  HSE_RC               2
#define  HSE_CRYSTAL          3
#define  PLL                  4



/* RCC Registers  */
#define RCC_CR                        *((volatile u32 *)(0x40023800))
#define RCC_HSION                     0
#define RCC_HSIRDY                    1
#define RCC_HSEON                     16
#define RCC_HSERDY                    17
#define RCC_HSEBYP                    18
#define RCC_PLLON                     24
#define RCC_PLLRDY                    25

#define CR_HSITRIM0                   3
#define CR_HSITRIM1                   4
#define CR_HSITRIM2                   5
#define CR_HSITRIM3                   6
#define CR_HSITRIM4                   7

#define CR_HSICAL0                    8
#define CR_HSICAL1                    9
#define CR_HSICAL2                    10
#define CR_HSICAL3                    11
#define CR_HSICAL4                    12
#define CR_HSICAL5                    13
#define CR_HSICAL6                    14
#define CR_HSICAL7                    15

#define CR_CSSON                      19

#define CR_PLLI2SON                   26
#define CR_PLLI2SRDY                  27





#define RCC_PLLCFGR                   *((volatile u32 *)(0x40023804))

#define RCC_CFGR                      *((volatile u32 *)(0x40023808))
#define CFGR_SW0                       0
#define CFGR_SW1                       1

#define CFGR_SWS0                      2
#define CFGR_SWS1                      3

#define CFGR_HPRE0                     4
#define CFGR_HPRE1                     5
#define CFGR_HPRE2                     6
#define CFGR_HPRE3                     7

#define CFGR_PPRE10                    10
#define CFGR_PPRE11                    11
#define CFGR_PPRE12                    12
#define CFGR_PPRE20                    13
#define CFGR_PPRE21                    14
#define CFGR_PPRE22                    15

#define CFGR_RTCPRE0                   16
#define CFGR_RTCPRE1                   17
#define CFGR_RTCPRE2                   18
#define CFGR_RTCPRE3                   19
#define CFGR_RTCPRE4                   20

#define CFGR_MCO10                     21
#define CFGR_MCO11                     22

#define CFGR_I2SSRC                    23

#define CFGR_MCO1PRE0                  24
#define CFGR_MCO1PRE1                  25
#define CFGR_MCO1PRE2                  26
#define CFGR_MCO2PRE0                  27
#define CFGR_MCO2PRE1                  28
#define CFGR_MCO2PRE2                  29

#define CFGR_MCO20                     30
#define CFGR_MCO21                     31



#define RCC_CIR                       *((volatile u32 *)(0x40023812))
#define RCC_AHB1RSTR                  *((volatile u32 *)(0x40023810))
#define RCC_AHB2RSTR                  *((volatile u32 *)(0x40023814))
#define RCC_APB1RSTR                  *((volatile u32 *)(0x40023820))


#define RCC_APB2RSTR                  *((volatile u32 *)(0x40023824))

#define RCC_AHB1ENR                   *((volatile u32 *)(0x40023830))
#define AHB1ENR_GPIOAEN          0
#define AHB1ENR_GPIOBEN          1
#define AHB1ENR_GPIOCEN          2
#define AHB1ENR_GPIODEN          3
#define AHB1ENR_GPIOEEN          4

#define AHB1ENR_GPIOH            7

#define AHB1ENR_CRCEN            12

#define AHB1ENR_DMA1EN           21
#define AHB1ENR_DMA2EN           22



#define RCC_AHB2ENR                   *((volatile u32 *)(0x40023834))
#define AHB2ENR_OTGFSEN                7

#define RCC_APB1ENR                   *((volatile u32 *)(0x40023840))
#define APB1ENR_TIM2EN                 0
#define APB1ENR_TIM3EN                 1
#define APB1ENR_TIM4EN                 2
#define APB1ENR_TIM5EN                 3

#define APB1ENR_WWDGEN                 11

#define APB1ENR_SPI2EN                 14
#define APB1ENR_SPI3EN                 15

#define APB1ENR_USART2EN               17

#define APB1ENR_I2C1EN                 21
#define APB1ENR_I2C2EN                 22
#define APB1ENR_I2C3EN                 23

#define APB1ENR_PWREN                  28

#define RCC_APB2ENR                   *((volatile u32 *)(0x40023844))
#define APB2ENR_TIM1EN                  0

#define APB2ENR_USART1EN                4
#define APB2ENR_USART6EN                5

#define APB2ENR_ADC1EN                  8

#define APB2ENR_SDIOEN                  11

#define APB2ENR_SPI1EN                  12
#define APB2ENR_SPI4EN                  13

#define APB2ENR_SYSCFGEN                14

#define APB2ENR_TIM9EN                  16
#define APB2ENR_TIM10EN                 17
#define APB2ENR_TIM11EN                 18


#define RCC_AHB1LPENR                 *((volatile u32 *)(0x40023850))
#define RCC_AHB2LPENR                 *((volatile u32 *)(0x40023854))
#define RCC_APB1LPENR                 *((volatile u32 *)(0x40023860))
#define RCC_APB2LPENR                 *((volatile u32 *)(0x40023864))


#define RCC_BDCR                      *((volatile u32 *)(0x40023870))
#define RCC_CSR                       *((volatile u32 *)(0x40023874))
#define RCC_SSCGR                     *((volatile u32 *)(0x40023880))
#define RCC_PLLI2SCFG                 *((volatile u32 *)(0x40023884))
#define RCC_DCKCFGR                   *((volatile u32 *)(0x40023892))





#endif
