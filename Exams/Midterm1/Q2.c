#include <stdio.h>
#include <math.h>
float mySqrt(int num){
	return sqrt(num);
}
int main() {
	printf("%.3f %.3f",mySqrt(4),mySqrt(10));
    return 0;
}

