CC = arm-none-eabi-gcc
CCdump = arm-none-eabi-objdump.exe
CCS = arm-none-eabi-nm.exe
DF = -h
MACH = cortex-m4
CFlag = -g -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -o0 
CSTD = -nostdlib
LFlag = -T

TARGET = final.elf
LFile = linker.ld

All: main.o start.o

FINAL: $(TARGET)

$(TARGET): main.o start.o
	$(CC) $^ $(CSTD) $(LFlag) $(LFile) -Wl,-Map=final.map -o $(TARGET)

main.o:App_2.c 
	$(CC) $(CFlag) $^ -o $@

start.o:start.c
	$(CC) $(CFlag) $^ -o $@

dump:$(TARGET)
	$(CCdump) $(DF) $(TARGET)
Symbol:
	$(CCS) $(TARGET)
clean: 
		rm -rf *.o *.elf *.map