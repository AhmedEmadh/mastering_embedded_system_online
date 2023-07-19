#include <stdio.h>

int main(void){
	unsigned char operator;
	float a,b;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdout);
	scanf("%c",&operator);
	fflush(stdin);
	printf("Enter two operands: ");
	scanf("%f",&a);
	scanf("%f",&b);
	fflush(stdin);
	switch(operator){
	case '+':
		printf("%.1f / %.1f = %.1f",a,b,a+b);
	break;
	case '-':
		printf("%.1f / %.1f = %.1f",a,b,a-b);
		break;
	case '*':
		printf("%.1f / %.1f = %.1f",a,b,a*b);
		break;
	case '/':
		printf("%.1f / %.1f = %.1f",a,b,a/b);
		break;
	default:
		printf("invalid operator");
	}
	return 0;
}
