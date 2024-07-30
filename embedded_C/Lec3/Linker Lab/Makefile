#Created by Ahmed Emad
CC=C:\Users\ahmed\Desktop\bin\arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
ProjectName=learn-in-depth-Ahmed-Emad
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