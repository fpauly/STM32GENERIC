#ifndef VARIANT_H
#define VARIANT_H

/*LEDs*/
#define  BOARD_NR_LED 4
#define  LED_BUILTIN  		PB6
#define  LED1_BUILTIN 		PB7
#define  LED2_BUILTIN 		PH4
#define  LED3_BUILTIN 		PI8
#define  LED_BUILTIN_MASK	0x0F
#define STM32_LED_BUILTIN_ACTIVE_HIGH

/*KEYs*/
#define  BOARD_NR_KEY     6
#define  BUTTON           PA0 
#define  SYS_WKUP1	PA0 /*for lowPower*/
#define  BUTTON1 		  PG2  //
#define  BUTTON2   		  PG3  //
#define  BUTTON3  		  PD4  //
#define  BUTTON4   		  PD5  //
#define  BUTTON5   		  PI11 //BUTTON_SEL
#define  BUTTON_MASK      0x01

/*spi*/
#define MOSI PA7
#define MISO PA6
#define SCK  PA5
#define SS   PA4

/*i2c*/
#define SDA PB9
#define SCL PB8
#define I2C1_100KHZ_TIMING 0x20404768
#define I2C2_100KHZ_TIMING 0x20404768
#define I2C3_100KHZ_TIMING 0x20404768
#define I2C4_100KHZ_TIMING 0x20404768

/*usb*/

#endif
