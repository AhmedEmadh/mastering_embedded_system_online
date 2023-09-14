#include <stdio.h>
#include <math.h>

int uniqueNumber(int arr[],int size){
	int unique = 0,i;
	for(i=0;i<size;i++){
		unique ^= arr[i];
	}
	return unique;
}

int main() {
	int arr1[7] = {4,2,5,2,5,7,4};
	int arr2[3] = {4,2,4};
	printf("%d %d",uniqueNumber(arr1,7),uniqueNumber(arr2,3));
    return 0;
}

