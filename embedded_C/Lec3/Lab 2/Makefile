#Created by Ahmed Emad

# Toolchain configuration
#TOOLCHAIN_PATH = C:\\Users\\ahmed\\Desktop\\bin
#CC = $(TOOLCHAIN_PATH)\\arm-none-eabi-gcc.exe
#AS = $(TOOLCHAIN_PATH)\\arm-none-eabi-as.exe
#LD = $(TOOLCHAIN_PATH)\\arm-none-eabi-ld.exe
#OBJCOPY = $(TOOLCHAIN_PATH)\\arm-none-eabi-objcopy.exe

CC=D:\\Courses\\02- Learn Embedded systems in depth\\03 Embedded C\\lesson3\\stm32_Toolchain\\tools\\bin\\arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
ProjectName=blink-led-from-scratch
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
AsOBJ= $(AS:.s=.o)

all: $(ProjectName).bin

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $(ProjectName).elf $(ProjectName).bin

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) startup.s -o startup.o
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $(ProjectName).elf

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.bin *.elf