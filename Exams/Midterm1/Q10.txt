#include <stdio.h>
#include <math.h>
#include <string.h>
int readBit(int num,int bit){
	return ((num>>bit)&1);
}
int maxNumberOfOnes(int num){
	int i,count=0,max_count=0,j;
	for(i=0;i<32;i++){
		if((readBit(num,i) == 0)&&(readBit(num,i+1) == 1)){
			for(j=i+1;(readBit(num,j) == 1)&&(j<32);j++,count++);
			i=j;
			if(j<32){
				if(count>max_count){
					max_count = count;
					count = 0;
				}
			}
		}
	}
	return max_count;
}
int main() {
	printf("%d",maxNumberOfOnes(14));
    return 0;
}

