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
    /* define starting address is 0x10000 */
	. = 0x10000;
	.reset . :
	{
		/* put the .text section of startup.o into .reset section of MEM  */
		startup.o(.text)
	}> MEM
	.text :
	{
		/* includes all text sections and put it in read only section */
		*(.text) *(.rodata)
	}> MEM
	.data :
	{
		/* include data section of all files into data section of MEM */
		*(.data)
	}> MEM
	.bss :
	{
		/* create bss section from all common symbols (uninitialized data) */
		*(.bss) *(COMMON)
	}> MEM
	/* defines current memory location that is 0x10000 + 0x1000 = 0x11000 */
	. = . + 0x1000;
	/* stack top starts from 0x11000 to the end */
	stack_top = . ;
}


