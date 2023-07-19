#include <stdio.h>

int main(void){
	float a,b,c;
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	fflush(stdin);
	printf("largest number is %.2f",(a>b)?a:((b>c)?b:c));
	return 0;
}
