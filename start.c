#include<stdint-gcc.h>




//getting symbols
extern uint32_t _etext;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;
extern uint32_t _stack_top;


void Reset_Handler(void);
int main(void);
void __libc_init_array(void);

// function prototyping of the handlers 
void NMI_HANDLERIRQ(void) __attribute__((weak,alias("Default_Handler")));
void HardFault_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void PVD_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TAMPERST_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void RTCWKUP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void RCC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2TS_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH2_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH5_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH6_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA1CH7_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void ADC12_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void CANTX_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void CANRX0_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void CANRX1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void CANSCE_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI95_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM1BRK_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM1UP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM1TRG_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM1CC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C1EV_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C1ER_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C2EV_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C2ER_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USART1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USART2_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USART3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1510_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void RTCALRM_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USBWKUP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM8BRK_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM8UP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIIM8TRG_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM8CC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void ADC3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void FMC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void UART4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void UART5_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM6DAC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM7_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA2CH1_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA2CH2_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA2CH3_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA2CH4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void DMA2CH5_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void ADC4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void COMP123_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void COMP456_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void COMP7_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C3EV_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void I2C3ER_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USBHP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USBLP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void USBRMP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM20BRK_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM20UP_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM20TRG_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void TIM20CC_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void FPU_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_HANDLERIRQ(void) __attribute__((weak, alias("Default_Handler")));

// creation of IRQ ahndlers
const uintptr_t vector[] __attribute__((used,section(".isr_vector"))) = {
    (uintptr_t)&_stack_top,
    (uintptr_t)Reset_Handler,
    (uintptr_t)NMI_HANDLERIRQ,
    (uintptr_t)HardFault_HANDLERIRQ,
    (uintptr_t)MemManage_HANDLERIRQ,
    (uintptr_t)BusFault_HANDLERIRQ,
    (uintptr_t)UsageFault_HANDLERIRQ,
    0,
    (uintptr_t)SVCall_HANDLERIRQ,
    (uintptr_t)PendSV_HANDLERIRQ,
    (uintptr_t)SysTick_HANDLERIRQ,
    (uintptr_t)WWDG_HANDLERIRQ,
    (uintptr_t)PVD_HANDLERIRQ,
    (uintptr_t)TAMPERST_HANDLERIRQ,
    (uintptr_t)RTCWKUP_HANDLERIRQ,
    (uintptr_t)FLASH_HANDLERIRQ,
    (uintptr_t)RCC_HANDLERIRQ,
    (uintptr_t)EXTI0_HANDLERIRQ,
    (uintptr_t)EXTI1_HANDLERIRQ,
    (uintptr_t)EXTI2TS_HANDLERIRQ,
    (uintptr_t)EXTI3_HANDLERIRQ,
    (uintptr_t)EXTI4_HANDLERIRQ,
    (uintptr_t)DMA1CH1_HANDLERIRQ,
    (uintptr_t)DMA1CH2_HANDLERIRQ,
    (uintptr_t)DMA1CH3_HANDLERIRQ,
    (uintptr_t)DMA1CH4_HANDLERIRQ,
    (uintptr_t)DMA1CH5_HANDLERIRQ,
    (uintptr_t)DMA1CH6_HANDLERIRQ,
    (uintptr_t)DMA1CH7_HANDLERIRQ,
    (uintptr_t)ADC12_HANDLERIRQ,
    (uintptr_t)CANTX_HANDLERIRQ,
    (uintptr_t)CANRX0_HANDLERIRQ,
    (uintptr_t)CANRX1_HANDLERIRQ,
    (uintptr_t)CANSCE_HANDLERIRQ,
    (uintptr_t)EXTI95_HANDLERIRQ,
    (uintptr_t)TIM1BRK_HANDLERIRQ,
    (uintptr_t)TIM1UP_HANDLERIRQ,
    (uintptr_t)TIM1TRG_HANDLERIRQ,
    (uintptr_t)TIM1CC_HANDLERIRQ,
    (uintptr_t)TIM2_HANDLERIRQ,
    (uintptr_t)TIM3_HANDLERIRQ,
    (uintptr_t)TIM4_HANDLERIRQ,
    (uintptr_t)I2C1EV_HANDLERIRQ,
    (uintptr_t)I2C1ER_HANDLERIRQ,
    (uintptr_t)I2C2EV_HANDLERIRQ,
    (uintptr_t)I2C2ER_HANDLERIRQ,
    (uintptr_t)SPI1_HANDLERIRQ,
    (uintptr_t)SPI2_HANDLERIRQ,
    (uintptr_t)USART1_HANDLERIRQ,
    (uintptr_t)USART2_HANDLERIRQ,
    (uintptr_t)USART3_HANDLERIRQ,
    (uintptr_t)EXTI1510_HANDLERIRQ,
    (uintptr_t)RTCALRM_HANDLERIRQ,
    (uintptr_t)USBWKUP_HANDLERIRQ,
    (uintptr_t)TIM8BRK_HANDLERIRQ,
    (uintptr_t)TIM8UP_HANDLERIRQ,
    (uintptr_t)TIIM8TRG_HANDLERIRQ,
    (uintptr_t)TIM8CC_HANDLERIRQ,
    (uintptr_t)ADC3_HANDLERIRQ,
    (uintptr_t)FMC_HANDLERIRQ,
    0,
    0,
    (uintptr_t)SPI3_HANDLERIRQ,
    (uintptr_t)UART4_HANDLERIRQ,
    (uintptr_t)UART5_HANDLERIRQ,
    (uintptr_t)TIM6DAC_HANDLERIRQ,
    (uintptr_t)TIM7_HANDLERIRQ,
    (uintptr_t)DMA2CH1_HANDLERIRQ,
    (uintptr_t)DMA2CH2_HANDLERIRQ,
    (uintptr_t)DMA2CH3_HANDLERIRQ,
    (uintptr_t)DMA2CH4_HANDLERIRQ,
    (uintptr_t)DMA2CH5_HANDLERIRQ,
    (uintptr_t)ADC4_HANDLERIRQ,
    0,
    0,
    (uintptr_t)COMP123_HANDLERIRQ,
    (uintptr_t)COMP456_HANDLERIRQ,
    (uintptr_t)COMP7_HANDLERIRQ,
    0,
    0,
    0,
    0,
    0,
    (uintptr_t)I2C3EV_HANDLERIRQ,
    (uintptr_t)I2C3ER_HANDLERIRQ,
    (uintptr_t)USBHP_HANDLERIRQ,
    (uintptr_t)USBLP_HANDLERIRQ,
    (uintptr_t)USBRMP_HANDLERIRQ,
    (uintptr_t)TIM20BRK_HANDLERIRQ,
    (uintptr_t)TIM20UP_HANDLERIRQ,
    (uintptr_t)TIM20TRG_HANDLERIRQ,
    (uintptr_t)TIM20CC_HANDLERIRQ,
    (uintptr_t)FPU_HANDLERIRQ,
    0,
    0,
    (uintptr_t)SPI4_HANDLERIRQ};

void Default_Handler(void)
{
    while (1){};
}

void Reset_Handler(void)
{
    uint32_t *Psrc =  &_sidata;
    uint32_t *Pdst =  &_sdata;
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; 
    for(int i=0; i<size;i++)
    {
        *Pdst++ = *Psrc++;
    }

    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    Pdst = (uint32_t*) &_sbss;
        for(int i=0;i<size;i++)
        {
            *Pdst++ = 0;
        }

    main();
}

void __libc_init_array(void)
{
}
