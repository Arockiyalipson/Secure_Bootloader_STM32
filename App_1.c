// This app includes UART CLI 

/*
Code for STM32 F401RE
What to do ??
Blink the led in the nucleo board

Led is in PA5
User button on PC13

*/

#include <stdint.h>

#define PHERI_BASE 0x40000000UL // Base address of all pheripheral

#define AHB2_OFFSET 0x08000000UL              // AHB2 offset
#define AHB2_BASE (PHERI_BASE + AHB2_OFFSET) // AHB2 base address

#define GPIOA_OFFSET 0X00000000UL             // GPIOA offset value
#define GPIOA_BASE (AHB2_BASE + GPIOA_OFFSET) // GPIOA Base addrr

#define RCC_OFFSET 0x00021000UL            // RCC offset
#define RCC_BASE (PHERI_BASE + RCC_OFFSET) // RCC base address

//structure of RCC registers 
typedef struct 
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_ABHENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile uint32_t RCC_AHBRSTR;
    volatile uint32_t RCC_CFGR2;
    volatile uint32_t RCC_CFGR3;
    
}RCC_STR;


// structure of GPIO registers 
typedef struct
{
    volatile uint32_t GPIO_MODER;
    volatile uint32_t GPIO_OTYPER;
    volatile uint32_t GPIO_OSPEEDR;
    volatile uint32_t GPIO_PUPDR;
    volatile uint32_t GPIO_IDR;
    volatile uint32_t GPIO_ODR;
    volatile uint32_t GPIO_BSSR;
    volatile uint32_t GPIO_LCKR;
    volatile uint32_t GPIO_AFRL;
    volatile uint32_t GPIO_AFRH;
    volatile uint32_t GPIO_BRR;
}GPIO_STR;

#define RCC ((RCC_STR*) RCC_BASE)
#define GPIO ((GPIO_STR*) GPIOA_BASE) //setting base address to the struct 

#define GPIOAEN (1U << 17) // shift 1 to 17th position to enable clk for GPIO A
#define PA5 (1U << 5)      // PUT VALUE IN ODR REGISTER

int main()
{
    // Set value in the respected register
    //  Enable clk for gpioa
    RCC->RCC_ABHENR |= GPIOAEN;

    // set moder register
    GPIO->GPIO_MODER |= (1U << 10);
    GPIO->GPIO_MODER &= ~(1U << 11);
    while (1)
    {
        GPIO->GPIO_ODR ^= (PA5);
        for (int i=0;i<10000;i++){
            __asm__("nop");
        }
    }
}