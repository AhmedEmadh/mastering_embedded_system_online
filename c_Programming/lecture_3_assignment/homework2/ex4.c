#include <stdio.h>

int main(void){
	float num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f",&num);

	fflush(stdin);
	if(num>0){
		printf("%.2f is positive.",num);
	}else if(num<0){
		printf("%.2f is negative.",num);
	}else{
		printf("You entered zero.");
	}
	return 0;
}
