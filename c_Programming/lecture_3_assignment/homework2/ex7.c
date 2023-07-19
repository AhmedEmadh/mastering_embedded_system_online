#include <stdio.h>

int main(void){
	int i;
	int n;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);
	fflush(stdin);
	int factorial = 1;
	if(n>0){
		for(i=1;i<=n;i++){
			factorial *= i;
		}
	}

	printf("Factorial = %d", factorial);
	return 0;
}
