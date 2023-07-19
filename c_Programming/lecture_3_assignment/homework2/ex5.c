#include <stdio.h>

int main(void){
	unsigned char character;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&character);
	fflush(stdin);
	if(((character > 64)&&(character<91))||((character>96)&&(character<123))){
		printf("%c is an alphabet",character);
	} else{
		printf("%c is not an alphabet",character);
	}
	return 0;
}
