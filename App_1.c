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

#define GPIO_MODER_R *(volatile unsigned int *)(GPIOA_BASE)        // GPIO MODER register
#define GPIO_ODR_R *(volatile unsigned int *)(GPIOA_BASE + 0X14UL) // GPIO output register

#define RCC_OFFSET 0x00021000UL            // RCC offset
#define RCC_BASE (PHERI_BASE + RCC_OFFSET) // RCC base address

#define RCC_AHBEN_OFFSET 0X00000014UL                                       // GPIOA CLK enable register offset
#define RCC_AHBEN_R *(volatile unsigned int *)(RCC_BASE + RCC_AHBEN_OFFSET) // rcc clk enable register

#define GPIOAEN (1U << 17) // shift 1 to 17th position to enable clk for GPIO A
#define PA5 (1U << 5)      // PUT VALUE IN ODR REGISTER

int main()
{
    // Set value in the respected register
    //  Enable clk for gpioa
    RCC_AHBEN_R |= GPIOAEN;

    // set moder register
    GPIO_MODER_R |= (1U << 10);
    GPIO_MODER_R &= ~(1U << 11);
    while (1)
    {
        GPIO_ODR_R ^= (PA5);
        for (int i=0;i<10000;i++){}
    }
}