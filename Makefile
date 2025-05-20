CC = arm-none-eabi-gcc
CCdump = arm-none-eabi-objdump.exe
CCS = arm-none-eabi-nm.exe
DF = -h
MACH = cortex-m4
CFlag =-g -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -o0 
CSTD = -nostdlib 
LFlag = -T


# src file list 
STARTS = start.c
MAINS = App_2.c

# dst file list 
STARTD = startup.o
MAIND = main.o

TARGET = final.elf
LFile = linker.ld

All: $(STARTD) $(MAIND)

FINAL: $(TARGET)

$(TARGET): *.o
	$(CC) $^ $(CSTD) -specs=nosys.specs $(LFlag) $(LFile) -Wl,-Map=final.map -o $(TARGET)
	@echo "taget compiled"

$(MAIND):$(MAINS) 
	$(CC) $(CFlag) $^ -o $@

$(STARTD):$(STARTS)
	$(CC) $(CFlag) $^ -o $@

dump:$(TARGET)
	$(CCdump) $(DF) $(TARGET)


Symbol:
	$(CCS) $(TARGET)

clean: 
		rm -rf *.o *.elf *.map
		@echo deleted all files
