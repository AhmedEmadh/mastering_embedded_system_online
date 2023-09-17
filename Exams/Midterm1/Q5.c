#include <stdio.h>
#include <math.h>
int readBit(int num,int bit){
	return ((num>>bit)&1);
}
int countOnes(int num){
	int i=0,count = 0;
	for(i=0;i<32;i++){
		if(readBit(num,i) == 1){
			count++;
		}
	}
	return count;
}

int main() {
	printf("%d %d",countOnes(5),countOnes(15));
    return 0;
}

