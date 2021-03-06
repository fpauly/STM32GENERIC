#include "Arduino.h"

#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_cortex.h"
#include "stm32f0xx_ll_utils.h"


/** System Clock Configuration
*/
void _Error_Handler(char* file, uint32_t line);
void SystemClock_Config(void) __weak;

void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);
  if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_1)
  {
	_Error_Handler(__FILENAME__, __LINE__); 
  }
#if defined(USE_HSI)
  LL_RCC_HSI48_Enable();
    while(LL_RCC_HSI48_IsReady() != 1)
  {
    
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI48, LL_RCC_PLL_MUL_6, LL_RCC_PREDIV_DIV_6);

  LL_RCC_PLL_Enable();
  while(LL_RCC_HSI48_IsReady() != 1)
  {
    
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI48, LL_RCC_PLL_MUL_6, LL_RCC_PREDIV_DIV_6);


#else //HSE
# if defined(USE_HSEBYPASS)	
#   if !(SB16 && SB50)
#     pragma message "Confirm that SB16 & SB50 ard closed (enable MCO)"
#   endif

  LL_RCC_HSE_EnableBypass();
# else
#  if EXTERNCRYSTAL8M < 1	
#     pragma message "Confirm the extern 8M crystal is installed"
#  endif
# endif
	
  LL_RCC_HSE_Enable();
   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLL_MUL_6, LL_RCC_PREDIV_DIV_1);
#endif  
  LL_RCC_PLL_Enable();
   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  }
  LL_Init1msTick(F_CPU);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(F_CPU);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, SYSTICK_INT_PRIORITY, 0);
  LL_SYSTICK_EnableIT();  //for STM32F0 add systick enableIT huaweiwx@sina.com 2017.8.5
}
