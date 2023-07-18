#include <stdio.h>

int main(void){
	unsigned char character;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&character);
	fflush(stdin);
	printf("Ascii value of %c = %d",character,character);
	return 0;
}
