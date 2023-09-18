/*
 ============================================================================
 Name        : ex4.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Store information of student
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SStudent{
	char m_name[50];
	int m_roll;
	int m_marks;
};
void readStudent(struct SStudent* s){
	printf("Enter name: ");
	fflush(stdout);
	gets(s->m_name);
	fflush(stdin);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%d",&s->m_marks);
	fflush(stdin);
	printf("\n");
}
void printStudent(struct SStudent* s){
	printf("Name: %s\n",s->m_name);
	printf("Marks: %d\n",s->m_marks);
	fflush(stdout);
}
int main() {
	int i;
	struct SStudent arr[10];
	/* read student */
	printf("Enter information of students:\n");
	fflush(stdout);
	for(i=0;i<10;i++){
		printf("For roll number %d\n",i+1);
		fflush(stdout);
		readStudent(&arr[i]);
		fflush(stdin);
	}
	/* display information of students: */
	printf("displaying information of students\n");
	for(i=0;i<10;i++){
		printf("Information for roll number %d:\n",i+1);
		fflush(stdout);
		printStudent(&arr[i]);
		fflush(stdin);
	}
    return 0;
}

