/*
 ===========================================================================================================
 File Name		: Delete_Student_Screen.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for viewing screen for deleting a student
 Notes			: 
 ===========================================================================================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Input_Validate.h"
#include <stdio.h>
void DELETE_STUDENT_SCREEN_ShowDeleteStudentScreen()
{
    unsigned int local_student_id;
    printf("Delete Student Screen\n");
    printf("====================================\n");
    printf("Enter Student ID to be deleted : ");
    fflush(stdout);
    local_student_id = INPUT_VALIDATE_PositiveIntInput();
    fflush(stdin);
    if(DATABASE_RemoveStudent(local_student_id) == DATABASE_no_error)
    {
        printf("Student Deleted Successfully\n");
    }
    else 
    {
        printf("Error Student not found!\n");
    }
    fflush(stdout);
}


