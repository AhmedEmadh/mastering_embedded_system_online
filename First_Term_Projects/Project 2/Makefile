# Toolchain configuration (left empty for default system tools)
TOOLCHAIN_PATH=
CC=gcc
CFLAGS=-g3
INCS=-I .
LIBS=
ProjectName=Student_Database
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
AsOBJ= $(AS:.s=.o)

# Default target
all: $(ProjectName)

# Build executable
$(ProjectName): $(OBJ) $(AsOBJ)
	$(TOOLCHAIN_PATH)$(CC) $(OBJ) $(AsOBJ) -o $(ProjectName) $(LIBS)
	@echo "======== Build Successful ========"

# Compile C source files
%.o: %.c
	$(TOOLCHAIN_PATH)$(CC) -c $(INCS) $(CFLAGS) $< -o $@

# Assemble assembly source files
%.o: %.s
	$(TOOLCHAIN_PATH)as $< -o $@

# Clean all files
clean_all:
	rm -f *.o

# Clean only executable
clean:
	rm -f $(ProjectName).exe
