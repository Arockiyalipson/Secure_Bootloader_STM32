/* Linker file for the MCU */ 

ENTRY(Reset_Handler) /*Entry to reset handler*/

MEMORY /*Put the memory */
{
    FLASH(rx):ORIGIN = 0x08000000 ,LENGHT = 512K
    SRAM(rwx):ORIGIN = 0X20000000 ,LENGHT = 64K
}

SECTIONS
{
    .isr_vector:
    {
        .=ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH
    
    .text:
    {
        .=ALIGN(4);
        *(.text)
        *(.text*)

        .=ALIGN(4);
        _etext = .; /*end of text section stores in the symbol*/
    } >FLASH
     
    .rodata:
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _erodata = .;
    } >RAM

    .data:
    {
        .=ALIGN(4);

        _sdata = .; /* start of data storing address*/
        *(.data);
        *(.data*);


    }
}