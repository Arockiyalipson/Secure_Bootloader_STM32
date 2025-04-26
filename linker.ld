ENTRY(Reset_handler)

MEMORY
{
    FLASH(rx) : ORIGIN = 0X08000000, LENGTH =512K
    SRAM(rwx) : ORIGIN = 0X20000000, LENGTH =80K
}
SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        _etext = .;
    } >FLASH AT >FLASH 

    .data :
    {
        _sdata = . ;
        *(.data)
        _edata = . ;
    } >SRAM AT >FLASH
    
    .bss :
    {   
        _sbss = .;
        *(.bss)
        _ebss = .;
    }> SRAM AT> SRAM
}