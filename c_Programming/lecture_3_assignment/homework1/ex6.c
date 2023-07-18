#include <stdio.h>

int main(void){
	float a,b,temp;
	printf("Enter the value of number a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter the value of number b: ");
	fflush(stdout);
	scanf("%f",&b);
	fflush(stdin);

	temp = a;
	a = b;
	b = temp;
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of b = %f\n",b);
	return 0;
}
