/*
 ============================================================================
 Name        : ex1.c
 Author      : Ahmed Emad
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Store Student information
 ============================================================================
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
struct SStudent{
	char m_name[50];
	int m_roll;
	float m_marks;
};
void getInfo(struct SStudent* s){
	printf("Enter information of students:\n");
	printf("Enter name: ");
	fflush(stdout);
	gets(s->m_name);
	fflush(stdin);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&s->m_roll);
	fflush(stdin);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&s->m_marks);
	fflush(stdin);
}
void displayInfo(struct SStudent* s){
	printf("Displaying Information\n");
	printf("name: %s\n",s->m_name);
	printf("Roll: %d\n",s->m_roll);
	printf("Marks: %.2f\n",s->m_marks);
	fflush(stdout);
}
int main() {
	struct SStudent student;
	getInfo(&student);
	displayInfo(&student);
    return 0;
}

