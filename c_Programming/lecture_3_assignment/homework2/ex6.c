#include <stdio.h>

int main(void){
	unsigned int n;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	fflush(stdin);
	printf("Sum = %d", (n * (n+1))/2);
	return 0;
}
