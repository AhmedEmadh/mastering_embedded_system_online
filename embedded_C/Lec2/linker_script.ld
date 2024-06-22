/*the entry point is reset section*/
ENTRY(reset)
/*define different memories at the microcontroller*/
MEMORY
{
	MEM (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
}
/*define sections*/
/*
	this will be > VMA @> LMA
	VMA: Run time memory address
	LMA: Burning Memory Address
 */
SECTIONS
{
	. = 0x10000;
	.reset . :
	{
		startup.o(.text)
	}> MEM
	.text :
	{
		*(.text) *(.rodata)
	}> MEM
	.data :
	{
		*(.data)
	}> MEM
	.bss :
	{
		*(.bss) *(COMMON)
	}> MEM
	. = . + 0x1000;
	stack_top = . ;
}


