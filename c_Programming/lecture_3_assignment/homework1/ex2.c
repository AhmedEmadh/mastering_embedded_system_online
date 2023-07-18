#include <stdio.h>

int main(void){
	int x;
    printf("##########Console-output###\n");
    printf("Enter a integer: ");
    fflush(stdout);
    scanf("%d",&x);
    printf("you entered: %d \n", x);
    return 0;
}
