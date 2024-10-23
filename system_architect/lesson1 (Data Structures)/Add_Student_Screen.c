/*
 ===========================================================================================================
 File Name		: Add_Student_Screen.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for viewing screen for adding students
 Notes			: 
 ===========================================================================================================
 */

#include <stdio.h>
#include "Add_Student_Screen.h"
#include "Input_Validate.h"
#include "student.h"
#include "Database.h"


void ADD_STUDENT_SCREEN_ShowAddStudentScreen()
{
    /* Defining used local variables */
    unsigned int local_ID;
    char local_name[20];
    float local_height;
    /* Taking Input from user */
    printf("Adding new Student\n");
    printf("=====================\n");
    printf("Enter the ID : ");
    fflush(stdout);
    local_ID = INPUT_VALIDATE_PositiveIntInput();
    printf("Enter Student Full Name : ");
    fflush(stdout);
    INPUT_VALIDATE_validate_string(local_name, 20);
    printf("Enter height: ");
    fflush(stdout);
    local_height = INPUT_VALIDATE_PositiveFloatInput();
    /* Adding Student to Database */
    Student_t local_student = STUDENT_CreateStudent(local_ID, local_name, local_height);
    DATABASE_AddStudent(&local_student);
    
}