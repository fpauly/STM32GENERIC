/**
  ******************************************************************************
  * @file    stm3210e_eval_nand.h
  * @author  MCD Application Team
  * @version V7.0.0
  * @date    14-April-2017
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm3210e_eval_nand.c driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_EVAL_NAND_H
#define __STM32_EVAL_NAND_H
#if __has_include("bsp.h")
 #include "bsp.h"
#endif

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
//#include "stm32f1xx_hal.h"

/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup STM3210E_EVAL
  * @{
  */
    
/** @addtogroup STM3210E_EVAL_NAND
  * @{
  */    

/* Exported constants --------------------------------------------------------*/ 
/** @defgroup STM3210E_EVAL_NAND_Exported_Constants STM3210E EVAL NAND Exported Constants
  * @{
  */
 
/** 
  * @brief  NAND status structure definition  
  */     
#define   NAND_OK         0x00U

#define NAND_DEVICE_ADDR  ((uint32_t)NAND_DEVICE1)  
  
/** 
  * @brief  FSMC NAND memory parameters  
  */
#ifndef   NAND_PAGE_SIZE
#define NAND_PAGE_SIZE             ((uint16_t)0x0200) /* 512 bytes per page w/o Spare Area */
#define NAND_BLOCK_SIZE            ((uint16_t)0x0020) /* 32x512 bytes pages per block */
#define NAND_PLANE_SIZE            ((uint16_t)0x0400) /* 1024 Block per plane */
#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x0010) /* last 16 bytes as spare area */
#define NAND_MAX_PLANE             ((uint16_t)0x1000) /* 4 planes of 1024 block */
#endif
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/


/**
  * @}
  */
  
/**
  * @}
  */ 
     
/**
  * @}
  */ 

/**
  * @}
  */ 

#ifdef __cplusplus
}

extern NAND_HandleTypeDef nandHandle;

class STM32NAND
{
  public:

    static STM32NAND& getInstance() {
      static STM32NAND instance; // Guaranteed to be destroyed. Instantiated on first use.
      return instance;
    }
    
	STM32NAND(STM32NAND const&)        = delete;
    void operator=(STM32NAND const&)  = delete;
	
    uint8_t Init(void){STM_FSMC_NAND_Init();return HAL_OK;};
	uint8_t readData(NAND_AddressTypeDef BlockAddress, uint8_t *pData, uint32_t uwNumPage){return HAL_NAND_Read_Page_8b(&nandHandle, &BlockAddress, pData, uwNumPage);};
	uint8_t writeData(NAND_AddressTypeDef BlockAddress, uint8_t *pData, uint32_t uwNumPage){return HAL_NAND_Write_Page_8b(&nandHandle, &BlockAddress, pData, uwNumPage);};
	uint8_t eraseBlock(NAND_AddressTypeDef BlockAddress){return HAL_NAND_Erase_Block(&nandHandle, &BlockAddress);};
	uint8_t readID(NAND_IDTypeDef *pNAND_ID){return HAL_NAND_Read_ID(&nandHandle, pNAND_ID);};

  private:
    STM32NAND(void){};

};

#endif

#endif /* __STM3210E_EVAL_NAND_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

