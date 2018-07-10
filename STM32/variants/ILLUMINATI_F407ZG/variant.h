#ifndef VARIANT_H
#define VARIANT_H

/******************** LED ************************/
#define BOARD_NR_LED            3 
#define LED_BUILTIN  			PE3
#define LED1_BUILTIN 			PE4
#define LED2_BUILTIN 			PG9
#define LED_BUILTIN_MASK		0x00
#define STM32_LED_BUILTIN_ACTIVE_LOW

/******************** BUTTON ************************/
#define  BOARD_NR_KEY		4                     
#define  BUTTON		PF6
#define  BUTTON1	PF7
#define  BUTTON2	PF8
#define  BUTTON3	PF9
#define  BUTTON_MASK         0x00
  

#define MOSI PA7
#define MISO PA6
#define SCK  PA5
#define SS   PA4

#define SDA PB9
#define SCL PB8

#endif
