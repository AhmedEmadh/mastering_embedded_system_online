#include <stdio.h>
#include <math.h>
int power(int num,int exp){
	int result = 1;
	int i;
	for(i=1;i<=exp;i++){
		result *= num;
	}
	return result;
}
int numOfDigits(int num){
	int i;
	for(i = 0;i<20;i++){
		if(num % (int)(power(10,i)) == num)
			return i;
	}
}
int reverseDigits(int num){
	int num_of_digits = numOfDigits(num);
	int arr[num_of_digits];
	/* store numbers in array */
	int i,j,temp;
	for(i=0;i<num_of_digits;i++){
		arr[i] = ((num % ((int)power(10,(i+1))))/(power(10,i)));
	}
	/* swap numbers in array */
	for(i=0,j=num_of_digits-1;i<j;i++,j--){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	/* put numbers of array in result */
	int result = 0;
	for(i=0;i<num_of_digits;i++){
		result += arr[i]*((int)power(10,i));
	}
	return result;
}
int main() {
	printf("%d %d",reverseDigits(2457),reverseDigits(1057));
    return 0;
}

