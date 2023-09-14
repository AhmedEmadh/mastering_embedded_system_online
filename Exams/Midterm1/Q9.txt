#include <stdio.h>
#include <math.h>
#include <string.h>
int calculateStrSize(char str[]){
	int size = 0;
		while(str[size] != '\0'){
			size++;
		}
	return size;
}
void reverseWords(char str[]){
	int i=0;
	/*calculate the size of the string*/
	int length = calculateStrSize(str)-1;
	char result[length+1];
	int result_counter = 0,end = length,j;
	int flag = 0;
	for(i=length-1;i>=0;i--){
		if((str[i] == ' ')||(i == 0)){

			for(j = i+1;j<=end;j++){
				if((j==1)&&(i==0)&&(flag == 0)){
					j--;
					result[result_counter] = str[j];
					result_counter++;
					flag = 1;

				}else{
					result[result_counter] = str[j];
					result_counter++;
				}

			}
			end = i-1;
			result[result_counter++] = ' ';
		}
	}
	/*copy the result into str*/
	for(i=0;i<length+1;i++){
		str[i]=result[i];
	}

}
int main() {
	char str[29] = "mohamed gamal";
	reverseWords(str);
	puts(str);
    return 0;
}

