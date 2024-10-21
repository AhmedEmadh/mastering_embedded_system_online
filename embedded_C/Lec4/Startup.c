/* Ahmed Emad */

#include <stdint.h>
#define STACK_Start_SP  0x20001000

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
static unsigned long stack_top[256];



extern int main(void);
void Reset_Handler (void);


void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));

void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) = {
	(void (* const)()) stack_top,
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler
};


void Reset_Handler (void)
{
	int i;
	//copy data from flash to ram
	unsigned int Data_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for(i=0;i<Data_size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	/* init .bss section in SRAM = 0 */
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char *)&_S_bss;
	for(i=0;i< bss_size;i++){
		*((unsigned char *)P_dst) = (unsigned char)0;
	}
	//Jump to main
	main();
}
