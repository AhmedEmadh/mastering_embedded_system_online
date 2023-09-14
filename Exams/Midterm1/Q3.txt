#include <stdio.h>
#include <math.h>
int is_prime(int num){
	if(num > 2){
		int i;
		for(i=2;i<num;i++){
			if((num % i) == 0){
				return 0;
			}
		}
		return 1;
	}else{
		return 1;
	}
}
void printPrime(int n1,int n2){
	int i;
	for(i=n1;i<=n2;i++){
		if(is_prime(i)){
			printf("%d ",i);
		}
	}
	printf("\n");
}
int main() {
	printPrime(1,20);
    return 0;
}

