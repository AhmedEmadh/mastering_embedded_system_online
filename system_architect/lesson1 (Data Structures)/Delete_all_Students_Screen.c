/*
 ===========================================================================================================
 File Name		: Delete_all_Students_Screen.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for viewing screen for deleting all students
 Notes			: 
 ===========================================================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Delete_all_Students_Screen.h"
#include "linked_list_Student.h"

extern Node_t* database_node;

void DELETE_ALL_STUDENTS_SCREEN_ShowDeleteAllStudentsScreen()
{
        LINKED_LIST_FREE(&database_node);
        database_node = NULL;
        printf("All Students Deleted Successfully\n");
        fflush(stdout);
}

