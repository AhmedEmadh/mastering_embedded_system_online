#include <stdio.h>

int main(void){
	int number;
	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&number);
	fflush(stdin);
	printf("%d is ",number);
	if(number % 2){
		printf("odd.");
	}else{
		printf("even.");
	}
	return 0;
}
