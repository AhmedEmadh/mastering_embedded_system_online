#include <stdio.h>

int main(void){
	int num1,num2;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d",&num1);
	scanf("%d",&num2);
	fflush(stdin);
	printf("sum: %d\n",num1+num2);
	return 0;
}
