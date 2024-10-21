#Created by Ahmed Emad

# Toolchain configuration
#TOOLCHAIN_PATH = C:\\Users\\ahmed\\Desktop\\bin
#CC = $(TOOLCHAIN_PATH)\\arm-none-eabi-gcc.exe
#AS = $(TOOLCHAIN_PATH)\\arm-none-eabi-as.exe
#LD = $(TOOLCHAIN_PATH)\\arm-none-eabi-ld.exe
#OBJCOPY = $(TOOLCHAIN_PATH)\\arm-none-eabi-objcopy.exe
TOOLCHAIN_PATH=D:\\Courses\\02- Learn Embedded systems in depth\\03 Embedded C\\lesson3\\stm32_Toolchain\\tools\\bin\\
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
ProjectName=unit3_lab4_cortexM4
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
AsOBJ= $(AS:.s=.o)

all: $(ProjectName).bin
	@echo "========Build Successfull========"
$(ProjectName).bin: $(ProjectName).elf
	$(TOOLCHAIN_PATH)$(CC)objcopy.exe -O binary $(ProjectName).elf $(ProjectName).bin

%.o: %.c
	$(TOOLCHAIN_PATH)$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
%.o: %.s
	$(TOOLCHAIN_PATH)$(CC)as.exe $(CFLAGS) $< -o $@
$(ProjectName).elf: $(OBJ) $(AsOBJ) linker_script.ld
	$(TOOLCHAIN_PATH)$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $(ProjectName).elf -Map=map_file.map
	cp $(Project_name).elf $(Project_name).axf

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.bin *.elf