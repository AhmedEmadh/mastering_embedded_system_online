#include <stdio.h>
#include <math.h>

void printArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void reverseArray(int arr[],int size){
	int i,j,temp;
	for(i=0,j=size-1;i<j;i++,j--){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int main() {
	int a[5] = {1,2,3,4,5};
	reverseArray(a,5);
	printArray(a,5);
    return 0;
}

