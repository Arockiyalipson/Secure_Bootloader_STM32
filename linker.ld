ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rw):ORIGIN =0x08000000, LENGTH = 512K
    RAM(rwx):ORIGIN =0x20000000, LENGTH = 80K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = .;
    }> FLASH AT > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        _sdata = .; 
        . = ALIGN(4);
        *(.data)
        . = ALIGN(4);
        _edata = .;
    }> FLASH AT > RAM

    .bss :
    {
        _sbss = .;
        . = ALIGN(4);
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    }> RAM 
}