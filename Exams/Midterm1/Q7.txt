#include <stdio.h>
#include <math.h>

int sum(int num){
	return ((num*(num+1))/2);
}
int main() {
	printf("%d",sum(100));
    return 0;
}

