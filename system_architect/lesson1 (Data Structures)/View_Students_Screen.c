/*
 ===========================================================================================================
 File Name		: View_Students_Screen.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for viewing screen for viewing students
 Notes			: 
 ===========================================================================================================
*/


#include <stdio.h>
#include "linked_list_Student.h"

extern Node_t* database_node;

void VIEW_STUDENTS_SCREEN_printStudentsList(Node_t** node)
{
    if((!node))
    {
        printf("No Students Available\n");
        return;
    }
    else if(!(*node))
    {
        printf("No Students Available\n");
        return;
    }
    Node_t* local_node = *node;
    printf("All Students\n");
    printf("=======================\n");
    while(local_node != NULL)
    {
        printf("=================================\n");
        printf("Name: %s\n",local_node->data.m_name);
        printf("ID: %u\n",local_node->data.m_ID);
        printf("Height: %f\n",local_node->data.m_height);
        fflush(stdout);
        printf("=================================\n");
        local_node = local_node->next;
    }
    printf("\n=================================\n");
}
void VIEW_STUDENTS_SCREEN_printAllStudentsAtDatabase()
{
    VIEW_STUDENTS_SCREEN_printStudentsList(&database_node);
}

void VIEW_STUDENTS_SCREEN_Show_View_Students_Screen()
{
    VIEW_STUDENTS_SCREEN_printAllStudentsAtDatabase();
    fflush(stdout);
}