#include <stdio.h>

int main(void){
	float num1,num2;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f",&num1);
	fflush(stdin);
	scanf("%f",&num2);
	fflush(stdin);
	printf("sum: %f\n",num1+num2);
	return 0;
}
