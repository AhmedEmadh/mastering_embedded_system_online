#include <stdio.h>

int sumNumbers(int num){
	if(num<10){
		return num;
	}else{
		int sum = 0;
		sum += sumNumbers(num/10);
		sum += num % 10;
		return sum;
	}
	return 0;
}
int main() {
	printf("%d %d",sumNumbers(123),sumNumbers(4565));
    return 0;
}
