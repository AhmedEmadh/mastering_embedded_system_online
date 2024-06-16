#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:keroles";
const unsigned char string_buffer2[100] = "learn-in-depth:keroles";
void main(void){
	Uart_Send_string(string_buffer);
}

/* -mcpu=arm926ej-s -I  . */