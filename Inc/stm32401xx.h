/*
 * stm32401xx.h
 *
 *  Created on: Jul 11, 2026
 *      Author: vyaas
 */
#include <stdint.h>
#ifndef INC_STM32401XX_H_
#define INC_STM32401XX_H_

#define __vo volatile
/* This is device header file which contains MCU specific details like memories,
 * peripherals BA,generic macros, core pheripheral BA
 *
 */



/*************************START : CPU PERIPHERALS************************/

/*
 *  last.ARM Cortex Mx Processor NVIC ISERx register Addresses
 */
#define  NVIC_ISER0       ((__vo uint32_t*)0xE000E100U)
#define  NVIC_ISER1       ((__vo uint32_t*)0xE000E104U)
#define  NVIC_ISER2       ((__vo uint32_t*)0xE000E108U)
#define  NVIC_ISER3       ((__vo uint32_t*)0xE000E10CU)

/*
 * ARM Cortex Mx processor  NVIC ICERx register Addresses
 */

#define  NVIC_ICER0       ((__vo uint32_t*)0xE000E180U)
#define  NVIC_ICER1      ((__vo uint32_t*)0xE000E184U)
#define  NVIC_ICER2      ((__vo uint32_t*)0xE000E188U)
#define  NVIC_ICER3      ((__vo uint32_t*)0xE000E18CU)


/*
 * ARM Cortex Mx processor Priority - NVIC IPRx register Addresses
 */

#define  NVIC_PR_BASEADDR      ((__vo uint32_t*)0xE000E400UL)

#define NO_PR_BITS_IMPLEMENTED        4



/*
 * 1.MEMORIES BA FM,SRAM,ROM
 */
#define FLASH_BASEADDR       (0x08000000UL)          // TOTAL FM = 128KB
#define SRAM_BASEADDR        (0x20000000UL)          //64KB
#define ROM_BASEADDR         (0x20000000UL)




/* START BUS BASEADDRESS
 * AHB1,AHB2,APB1,APB2
 */


#define AHB1_BASEADDR        (0x40020000UL)
#define AHB2_BASEADDR        (0x50000000UL)
#define APB1_BASEADDR        (0x40000000UL)
#define APB2_BASEADDR        (0x40010000UL)



/*START PHERIPHERAL BASEADDRESS
 * GPIO,SPI,UART,EXTI,SYSCFG,I2C
 */


/************BA OF PHERPHERALS HANGING ON AHB1-84mhz **********/

#define GPIOA_BASEADDR             AHB1_BASEADDR
#define GPIOB_BASEADDR            ( AHB1_BASEADDR + 0x0400UL )  //each port has 1kb mm reserved
#define GPIOC_BASEADDR            ( AHB1_BASEADDR + 0x0800UL )
#define GPIOD_BASEADDR            ( AHB1_BASEADDR + 0x0C00UL )
#define GPIOE_BASEADDR            ( AHB1_BASEADDR + 0x1000UL )
#define GPIOH_BASEADDR           ( AHB1_BASEADDR + 0x1C00UL )
#define RCC_BASEADDR              ( AHB1_BASEADDR + 0x3800UL )
#define RCC_BASEADDR              ( AHB1_BASEADDR + 0x3800UL )
#define DMA1_BASEADDR             ( AHB1_BASEADDR + 0x6000UL )
#define DMA2_BASEADDR               (AHB1_BASEADDR + 0x6400UL )



/************BA OF PHERPHERALS HANGING ON AHB2 **********/

#define USB_OTG_BASEADDR              AHB2_BASEADDR

/************BA OF PHERPHERALS HANGING ON APB1-42MHZ **********/
/* The peripherals hanging on these bus requires low speed for data communication
 * TIM - 2 TO 5 , I2C - 1 TO 3 & UART - 2 , SPI - 2,3 hang on apb1 bus - 42mhz ( pclk1 )
 */
#define TIM2_BASEADDR             APB1_BASEADDR
#define TIM3_BASEADDR            ( APB1_BASEADDR + 0x0400UL)
#define TIM4_BASEADDR            ( APB1_BASEADDR + 0x0800UL)
#define TIM5_BASEADDR            ( APB1_BASEADDR + 0x0C00UL)


#define UART2_BASEADDR            ( APB1_BASEADDR + 0x4400UL)

#define I2C1_BASEADDR            ( APB1_BASEADDR + 0x5400UL)
#define I2C2_BASEADDR            ( APB1_BASEADDR + 0x5800UL)
#define I2C3_BASEADDR            ( APB1_BASEADDR + 0x5C00UL)


#define SPI2_BASEADDR            ( APB1_BASEADDR + 0x3800UL)
#define SPI3_BASEADDR            ( APB1_BASEADDR + 0x3C00UL)

#define WWDG_BASEADDR            ( APB1_BASEADDR + 0x2C00UL)

/************BA OF PHERPHERALS HANGING ON APB1-42MHZ **********/
/* The peripherals hanging on these bus requires low speed for data communication
 * TIM - 1 ,9 TO 11 , EXTI , SYSCFG , adc1 & UART - 1,6 , SPI - 1,4 hang on apb1 bus - 42mhz ( pclk1 )
 */


#define UART1_BASEADDR            ( APB2_BASEADDR + 0x1000UL)
#define UART6_BASEADDR            ( APB2_BASEADDR + 0x1400UL)


#define TIM1_BASEADDR            ( APB2_BASEADDR )
#define TIM9_BASEADDR            ( APB2_BASEADDR + 0x4000UL)
#define TIM10_BASEADDR           ( APB2_BASEADDR + 0x4400UL)
#define TIM11_BASEADDR           ( APB2_BASEADDR + 0x4800UL)


#define SPI1_BASEADDR            ( APB2_BASEADDR + 0x3000UL)
#define SPI4_BASEADDR            ( APB2_BASEADDR + 0x3400UL)

#define SYSCFG_BASEADDR          ( APB2_BASEADDR + 0x3800UL)
#define EXTI_BASEADDR            ( APB2_BASEADDR + 0x3C00UL)



/*********************REG DEFINATIONS OF ALL PERIPHERALS************************
 *                  EACH PERI HAS DIFF REG BASED ON REQ WE USE IT TO DRIVE A PIN
 */

//1.GPIOx REG DEF

typedef struct
{
	__vo uint32_t  MODER ;   /* GPIO port mode register address offset : 0x00 */
	__vo uint32_t  OTYPER ;  /*  GPIO port output type register offset : 0x04 */
	__vo uint32_t  OSPEEDER ; /* GPIO port output speed register : 0x08 */
	__vo uint32_t  PUPDR ;    /* GPIO port pull-up/pull-down register : 0x0c */
	__vo uint32_t  IDR ;     /* GPIO port input data register : 0x10 */
	__vo uint32_t  ODR ;    /*  GPIO port output data register :  0x14 */
	__vo uint32_t  BSRRR ;  /*  GPIO port bit set/reset register : 0x18 */
	__vo uint32_t  LCKR ;   /*  GPIO port configuration lock register 0x1c */
	__vo uint32_t  AFR[2] ;  /* GPIO alternate function low register 0x20  for afr[0] , 0x24 for HIGHREG afr[1] */

}GPIO_RegDef_t;  /* alias name of struct */



/***************************RCC REG DEF********************/


typedef struct
{
	__vo uint32_t   RCC_CR ;       /* RCC_CR clock control register address offset : 0x00 */
	__vo uint32_t   RCC_PLLCFGR ;  /*  RCC_PLL config  register add offset : 0x04 */
	__vo uint32_t   RCC_CFGR ;   /* RCC clock config register (prescalers ) add offset : 0x08 */
	__vo uint32_t   RCC_CIR ;    /* RCC clock config interrupt register add offset : 0x0c */
	__vo uint32_t   RCC_AHB1RSTR ;     /* RCC AHB1 peripheral reset register add offset : 0x10 */
	__vo uint32_t   RCC_AHB2RSTR ;    /*  RCC AHB2 peripheral reset register add offset :  0x14 */
	uint32_t   RESERVED0 ;    /*  future purpose reserved register :  0x18 */
	uint32_t   RESERVED1 ;    /*  future purpose reserved register :  0x1c */
	__vo uint32_t   RCC_APB1RSTR ;  /*  RCC APB1 peripheral reset register add offset : 0x20 */
	__vo uint32_t   RCC_APB2RSTR ;   /*  RCC APB2 peripheral reset register add offset : 0x24 */
	uint32_t   RESERVED2 ;    /*  future purpose reserved register :  0x28 */
	uint32_t   RESERVED3 ;    /*  future purpose reserved register  :  0x2c */
	__vo uint32_t   RCC_AHB1ENR ;  /* RCC AHB1 peripheral ENABLE register add offset : 0X30*/
	__vo uint32_t   RCC_AHB2ENR ;  /* RCC APB1 peripheral ENABLE register add offset : 0X34*/
	uint32_t   RESERVED4 ;    /*  future purpose reserved register :  0x38 */
	uint32_t   RESERVED5 ;    /* future purpose reserved register : 0x3c */
	__vo uint32_t   RCC_APB1ENR;  /* RCC APB1 peripheral ENABLE register add offset : 0x40 */
	__vo uint32_t   RCC_APB2ENR;  /* RCC APB2 peripheral ENABLE register add offset : 0x44 */
	uint32_t   RESERVED6 ;    /* future purpose reserved register  :  0x48 */
	uint32_t   RESERVED7 ;    /* future purpose reserved register  :  0x4C */
	__vo uint32_t   RCC_AHB1LPENR ;     /* RCC AHB1 peripheral clock enable in low power mode register add offset: 0x50 */
	__vo uint32_t   RCC_AHB2LPENR ;   /* RCC AHB1 peripheral clock enable in low power mode register add offset: 0x54 */
	uint32_t   RESERVED8 ;     /*  future purpose reserved register :  0x58 */
	uint32_t   RESERVED9 ;     /*  future purpose reserved register :  0x5c */
	__vo uint32_t   RCC_APB1LPENR ;   /* RCC APB1 peripheral clock enable in low power mode register add offset: 0x60 */
	__vo uint32_t   RCC_APB2LPENR ;   /* RCC APB2 peripheral clock enable in low power mode register add offset: 0x64 */
	uint32_t   RESERVED10 ;        /*  future purpose reserved register :  0x68 */
	uint32_t   RESERVED11 ;        /*  future purpose reserved register :  0x6C */
	__vo uint32_t   RCC_BDCR ;     /*  RCC Backup domain control register add offset : 0x70 */
	__vo uint32_t   RCC_CSR ;     /*  RCC clock control & status registeradd offset : 0x74 */
	uint32_t   RESERVED12 ;       /*  future purpose reserved register :  0x78 */
	uint32_t   RESERVED13 ;       /*  future purpose reserved register :  0x7c */
	__vo uint32_t  RCC_SSCGR ;
	__vo uint32_t  RCC_PLLI2SCFGR ;
	__vo uint32_t  RCC_DCKCFGR ;
}RCC_RegDef_t;  /* alias name of struct */



/**********************************************************************/


/*****************************EXTI-REGISTERS-BA********************/
typedef struct
{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;

}EXTI_RegDef_t;
/******************************************************************/



/*****************************SYSCFG-REGISTERS-BA********************/
typedef struct
{
	__vo uint32_t SYSCFG_MEMRMP;   /* Offset address : 0x00 */
	__vo uint32_t SYSCFG_PMC;      /* offset address : 0x04 */
	__vo uint32_t SYSCFG_EXTICR[4];  /* offset address : 0x08-0x14 */
	uint32_t RESERVED[2];       /* offset address : 0x18 - 0x1c */
	__vo uint32_t SYSCFG_CMPCR;       /* offset address : 0x20 */


}SYSCFG_RegDef_t; /*alias name of struct */
/******************************************************************/









//variable dec
#define GPIOA         (( GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB         (( GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC         (( GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD         (( GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE         (( GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOH         (( GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

#define EXTI         (( EXTI_RegDef_t *)EXTI_BASEADDR)
#define SYSCFG         (( SYSCFG_RegDef_t *)SYSCFG_BASEADDR)


/****************************************************************/

/*
 *  6.37th CLOCK ENABLE MACROS FOR GPIOX PERIPHERAL
 */
#define GPIOA_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<0))  /* GPIOA peripheral clock enable */
#define GPIOB_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<1))  /* GPIOB peripheral clock enable */
#define GPIOC_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<2))  /* GPIOC peripheral clock enable */
#define GPIOD_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<3))  /* GPIOD peripheral clock enable */
#define GPIOE_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<4))  /* GPIOE peripheral clock enable */
#define GPIOH_PCLK_EN()	(RCC->RCC_AHB1ENR |=(0X1<<7))  /* GPIOH peripheral clock enable */

/*
 *  CLOCK ENABLE MACROS FOR I2Cx PERIPHERAL
 */
#define I2C1_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<21))  /* I2C1 peripheral clock enable */
#define I2C2_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<22))  /* I2C2 peripheral clock enable */
#define I2C3_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<23))  /* I2C3 peripheral clock enable */

/*
 *  CLOCK ENABLE MACROS FOR SPIx PERIPHERAL
 */
#define SPI2_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<14))  /* spi2 peripheral clock enable */
#define SPI3_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<15))  /* spi3 peripheral clock enable */
#define SPI1_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<12))  /* spi1 peripheral clock enable */
#define SPI4_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<13))  /* spi2 peripheral clock enable */

/*
 *  CLOCK ENABLE MACROS FOR USARTx PERIPHERAL
 */
#define USART2_PCLK_EN()	(RCC->RCC_APB1ENR |=(0X1<<17))  /* uart2 peripheral clock enable */
#define USART1_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<4))  /* uart1 peripheral clock enable */
#define USART6_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<5))  /* uart6 peripheral clock enable */

/*
 *  CLOCK ENABLE MACROS FOR EXTI , SYSCFG PERIPHERAL
 */
#define EXTI_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<4))  /* exti peripheral clock enable */
#define SYSCFG_PCLK_EN()	(RCC->RCC_APB2ENR |=(0X1<<14))  /* syscnfg peripheral clock enable */


/********************************8.DISABLE CLOCK FOR PERI********************************/

/*
 *  CLOCK DISABLE MACROS FOR GPIOx PERIPHERAL
 */
#define GPIOA_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<0))  /* GPIOA peripheral clock Disable */
#define GPIOB_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<1))  /*  GPIOB peripheral clock Disable */
#define GPIOC_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<2))  /* gpioC peripheral clock Disable */
#define GPIOD_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<3))  /* gpioD peripheral clock Disable */
#define GPIOE_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<4))  /* gpioE peripheral clock Disable */
#define GPIOH_PCLK_DI()	(RCC->RCC_AHB1ENR &=~(0X1<<7))  /* gpioE peripheral clock Disable */

/*
 *  CLOCK DISABLE MACROS FOR I2Cx PERIPHERAL
 */
#define I2C2_PCLK_DI()	(RCC->RCC_APB1ENR &=~(0X1<<22))  /* I2C2 peripheral clock Disable */
#define I2C1_PCLK_DI()	(RCC->RCC_APB1ENR &=~(0X1<<21))  /* I2C1 peripheral clock Disable */
#define I2C3_PCLK_DI()	(RCC->RCC_APB1ENR &=~(0X1<<23))  /* I2C3 peripheral clock Disable */

/*
 *  CLOCK DISABLE MACROS FOR SPIx PERIPHERAL
 */
#define SPI2_PCLK_DI()	(RCC->RCC_APB1ENR &=~(0X1<<14))  /* SPI2 peripheral clock Disable */
#define SPI3_PCLK_DI()	(RCC->RCC_APB1ENR &=~(0X1<<15))  /* SPI3 peripheral clock Disable */
#define SPI1_PCLK_DI()	(RCC->RCC_APB2ENR &=~(0X1<<12))  /* SPI1 peripheral clock Disable */
#define SPI4_PCLK_DI()	(RCC->RCC_APB2ENR &=~(0X1<<13))  /* SPI4 peripheral clock Disable */

/*
 *  CLOCK DISABLE MACROS FOR USARTx PERIPHERAL
 */
#define USART2_PCLK_DA()	(RCC->APB1ENR &=~(0X1<<17))  /*UART2 peripheral clock disable */
#define USART1_PCLK_DA()	(RCC->APB2ENR &=~(0X1<<4))  /* UART1 peripheral clock disable */
#define USART6_PCLK_DA()	(RCC->APB2ENR &=~(0X1<<5))  /* UART6 peripheral clock disable */

/*
 *  CLOCK DISABLE MACROS FOR EXTI , SYSCFG PERIPHERAL
 */
#define EXTI_PCLK_DA()	    (RCC->APB2ENR &=~(0X1<<4))  /* EXTI peripheral clock disable */
#define SYSCFG_PCLK_DA()	(RCC->APB2ENR &=~(0X1<<14))  /* gpioE peripheral clock disable */


/*
 * Macros to RESET GPIO Peripherrals
 */

#define 	GPIOA_REG_RST()         do{ (RCC->RCC_AHB1RSTR|=(0X1<<0)) ;      RCC->RCC_AHB1RSTR &=~(0X1<<0);  }while(0)
#define 	GPIOB_REG_RST()         do{ (RCC->RCC_AHB1RSTR|=(0X1<<1)) ;     RCC->RCC_AHB1RSTR &=~(0X1<<1);  }while(0)
#define 	GPIOE_REG_RST()         do{ (RCC->RCC_AHB1RSTR|=(0X1<<4)) ;     RCC->RCC_AHB1RSTR &=~(0X1<<4);  }while(0)
#define 	GPIOD_REG_RST()         do{ (RCC->RCC_AHB1RSTR|=(0X1<<3)) ;     RCC->RCC_AHB1RSTR &=~(0X1<<3);  }while(0)
#define 	GPIOH_REG_RST()         do{ (RCC->RCC_AHB1RSTR|=(0X1<<7)) ;     RCC->RCC_AHB1RSTR &=~(0X1<<7);  }while(0)
#define 	GPIOC_REG_RST()        do{ (RCC->RCC_AHB1RSTR|=(0X1<<2)) ;      RCC->RCC_AHB1RSTR &=~(0X1<<2);  }while(0)


/*
 * IRQ (Interrupt Request ) No of STM32F401x MCU
 * NOTE : Update these macros with valid values according to your MCU
 */

#define IRQ_NO_EXTI0           6
#define IRQ_NO_EXTI1           7
#define IRQ_NO_EXTI2           8
#define IRQ_NO_EXTI3           9
#define IRQ_NO_EXTI4          10
#define IRQ_NO_EXTI5_9        23
#define IRQ_NO_EXTI10_15      40
#define IRQ_NO_EXTI17         41
#define IRQ_NO_EXTI16         1


/*
 * returns port code for given GPIOx BA
 */
#define GPIO_BASEADDR_TO_CODE(x)          (x==GPIOA) ? 0 : \
		(x==GPIOB) ? 1 : \
				(x==GPIOC) ? 2 : \
						(x==GPIOD) ? 3 : \
								(x==GPIOE) ? 4 : \
										(x==GPIOH) ? 7 : 0




//generic macros

#define SET    1
#define RESET  0
#define ENABLE  SET
#define DISABLE  RESET

//#include "stm32401xxgpio.h"
#endif /* INC_STM32401XX_H_ */
