#include <stdio.h>

int main(void){
	char character;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&character);
	fflush(stdin);
	printf("%c is ",character);
	switch(character){
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
		{
		printf("vowel.");
		}
		break;
		default:
		{
			printf("consonant.");
		}

			break;
	}
	return 0;
}
