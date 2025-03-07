
/*
Code for STM32 F401RE
What to do ??
Blink the led in the nucleo board

Led is in PA5

USART2 TX in PA2
User button on PC13

*/

#include <stdint.h>

#define PHERI_BASE 0x40000000UL // Base address of all pheripheral

#define AHB2_OFFSET 0x08000000UL             // AHB2 offset
#define AHB2_BASE (PHERI_BASE + AHB2_OFFSET) // AHB2 base address

#define GPIOA_OFFSET 0X00000000UL             // GPIOA offset value
#define GPIOA_BASE (AHB2_BASE + GPIOA_OFFSET) // GPIOA Base addrr

#define RCC_OFFSET 0x00021000UL            // RCC offset
#define RCC_BASE (PHERI_BASE + RCC_OFFSET) // RCC base address

#define USART2_OFFSET 0X00004400UL               // USART2 OFFSET
#define USART2_BASE (PHERI_BASE + USART2_OFFSET) // USART2 BASE ADDRR

// structure of RCC registers
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

} RCC_STR;

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
} GPIO_STR;

// struct for USART registers
typedef struct
{
    volatile uint32_t USART_CR1; // Control register
    volatile uint32_t USART_CR2;
    volatile uint32_t USART_CR3;
    volatile uint32_t USART_BRR;
    volatile uint32_t USART_GTPR;
    volatile uint32_t USART_RTOR;
    volatile uint32_t USART_RQR;
    volatile uint32_t USART_ISR;
    volatile uint32_t USART_ICR;
    volatile uint32_t USART_RDR; // RX data register
    volatile uint32_t USART_TDR; // TX data register
} USART2_STR;

#define RCC ((RCC_STR *)RCC_BASE)          // setting RCC base address to the struct
#define GPIOA ((GPIO_STR *)GPIOA_BASE)     // setting GPIOA base address to the struct
#define USART2 ((USART2_STR *)USART2_BASE) // setting USART2 base address to the struct

#define GPIOAEN (1U << 17)  // shift 1 to 17th position to enable clk for GPIO A
#define USART2EN (1U << 17) // clk enble for uart
#define PA2 (1U << 2)       // PIN 2 ENABLE IN GPIOA ODR
#define CR1_TE (1U << 3)    // set bit 3 to 1 for TE eneble
#define CR1_UE (1U << 0)
#define ISR_TXE (1U << 7)

#define SYSCLK 16000000
#define APB1_CLK SYSCLK
#define BaudRate 115200
static void USART2_BRR_SET(uint32_t PHERICLK, uint32_t BAUDRATE);

int main()
{
}

// Init function for USART2 tx
void uart2_tx_init(void)
{

    /* Init function for uart modeule*/
    // Config GPIO
    /*
        1. clk enable for gpio
        2. GPIO to alternate function mode(Moderreg)
        3. GPIO to alternate function(AFL or AFH)
    */

    RCC->RCC_ABHENR |= GPIOAEN;      // enable clk for gpio
    GPIOA->GPIO_MODER &= ~(1U << 4); // IN MODER REGISTER
    GPIOA->GPIO_MODER |= (1U << 5);

    GPIOA->GPIO_AFRL |= (1U << 8); // SETTING ALTERNATE FUNCTION REGISTER VALUE (AF07)
    GPIOA->GPIO_AFRL |= (1U << 9);
    GPIOA->GPIO_AFRL |= (1U << 10);
    GPIOA->GPIO_AFRL &= ~(1U << 11);

    // config UART
    /*
         1. clk enable for UART
         2. config baudrate (16bit value)
         3. config tranfer direction
         3. enable UART module
    */

    RCC->RCC_APB1ENR |= USART2EN;       // enable clk for usart
    USART2_BRR_SET(APB1_CLK, BaudRate); // calculate baud rate
    USART2->USART_CR1 = CR1_TE;         // config tranfer direction
    USART2->USART_CR1 |= CR1_UE;        // enable UART module
}

void uart_tx(char ch)
{
    // write values into the tx data register
    while (!(USART2->USART_ISR) & ISR_TXE)
    {
    }

    USART2->USART_TDR = ch & 0xff; // to write the exact data
}

static void USART2_BRR_SET(uint32_t PHERICLK, uint32_t BAUDRATE)
{
    USART2->USART_BRR = Compute_BaudRate(PHERICLK, BAUDRATE);
}

static uint16_t Compute_BaudRate(uint32_t PHERICLK, uint32_t BAUDRATE)
{
    return ((PHERICLK + (BAUDRATE / 2U)) / BAUDRATE); // return calculated baud rate
}
