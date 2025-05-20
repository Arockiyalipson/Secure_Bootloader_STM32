OUTPUT_ARCH(arm)
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

PROVIDE(_stack_top = ORIGIN(RAM) + LENGTH(RAM));
ENTRY(Reset_Handler)

SECTIONS
{
    .vectors :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text .text.*)
        *(.rodata .rodata.*)
        . = ALIGN(4);
        _etext = .;
    }> FLASH AT > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
	. = ALIGN(4);
        _sdata = .; 
        *(.data .data.*)
        . = ALIGN(4);
        _edata = .;
    }> RAM AT > FLASH

    .bss :
    {
        _sbss = .;
        . = ALIGN(4);
        *(.bss)
        . = ALIGN(4);
        _ebss = .;
    }> RAM AT > RAM
}
