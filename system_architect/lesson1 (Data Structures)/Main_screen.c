/*
 =====================================================================================================================
 File Name		: Main_screen.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for viewing main screen for doing operations on linked list database
 Notes			: 
 =====================================================================================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include "linked_list_Student.h"
#include "Delete_Student_Screen.h"
#include "Delete_all_Students_Screen.h"
#include "View_Students_Screen.h"
#include <stdio.h>
#include "Main_screen.h"
#include <stdlib.h>
#include "Add_Student_Screen.h"
#include "Input_Validate.h"

typedef enum enOption
{
    enAddStudent = 1,
    enDeleteStudent = 2,
    enViewStudent = 3,
    enDeleteAll = 4,
    enSearchForStudent = 5,
    enNumberOfStudents = 6,
    enIDsOfStudents = 7
} enOption_t;
extern Node_t* database_node;
void _go_to_Search_For_Student_Screen()
{
    unsigned int local_id;
    int is_found = 0;
    Node_t* temp_node = database_node;
    printf("Enter the ID of the student: ");
    fflush(stdout);
    local_id = INPUT_VALIDATE_PositiveIntInput();
    while(temp_node)
    {
        if(temp_node->data.m_ID == local_id)
        {
            printf("Name: %s\n",temp_node->data.m_name);
            printf("ID: %u\n",temp_node->data.m_ID);
            printf("ID: %f\n",temp_node->data.m_height);
            printf("\n");
            is_found = 1;
            break;
        }
        temp_node = temp_node->next;
    }
    if(!is_found)
        printf("Student not found\n");
    fflush(stdout);
}
void _go_to_Number_of_Students_Screen()
{
    printf("The Number Of Students is %d\n",LINKED_LIST_Length(&database_node));
    fflush(stdout);
}
void _go_to_IDs_of_Students_Screen()
{
    Node_t* temp_node = database_node;
    while(temp_node)
    {
        printf("%d\n",temp_node->data.m_ID);
        temp_node = temp_node->next;
    }
    fflush(stdout);
}

static void _go_to_add_student_screen()
{
    ADD_STUDENT_SCREEN_ShowAddStudentScreen();
}
static void _go_to_view_student_screen()
{
    VIEW_STUDENTS_SCREEN_Show_View_Students_Screen();
}
static void _go_to_delete_student_screen()
{
    DELETE_STUDENT_SCREEN_ShowDeleteStudentScreen();
}
static void _go_to_delete_all_screen()
{
    char input_char;
    printf("Are you Sure That you want to delete all students (y/n)? ");
    fflush(stdout);
    scanf("%c",&input_char);
    if(input_char == 'y' || input_char == 'Y')
        DELETE_ALL_STUDENTS_SCREEN_ShowDeleteAllStudentsScreen();
    else 
    {
        printf("Deletation Cancled\n");
        fflush(stdout);
    }
}

enOption_t ReadOption()
{
    int option;
    fflush(stdout);
    return (enOption_t)INPUT_VALIDATE_IntInputBetween((int)enAddStudent, (int)enIDsOfStudents);
}
void PerformOption(enOption_t option)
{
    switch (option) {
    case enAddStudent:
    {
        system("cls");
        _go_to_add_student_screen();
        system("pause");
        break;
    }
    case enViewStudent:
    {
        system("cls");
        _go_to_view_student_screen();
        system("pause");
        break;
    }
    case enDeleteStudent:
    {
        system("cls");
        _go_to_delete_student_screen();
        system("pause");
        break;
    }
    case enDeleteAll:
    {
        system("cls");
        _go_to_delete_all_screen();
        system("pause");
        break;
    }
    case enSearchForStudent:
    {
        system("cls");
        _go_to_Search_For_Student_Screen();
        system("pause");
        break;
    }
    case enNumberOfStudents:
    {
        system("cls");
        _go_to_Number_of_Students_Screen();
        system("pause");
        break;
    }
    case enIDsOfStudents:
    {
        system("cls");
        _go_to_IDs_of_Students_Screen();
        system("pause");
        break;
    }

    default:
    {

        break;
    }
    }
}

void Main_Screen_Show_Main_Screen()
{
    system("cls");
    printf("\tChoose one of the following Options\n");
    printf("1: Add student\n");
    printf("2: Delete student\n");
    printf("3: view students\n");
    printf("4: Delete all\n");
    printf("5: Search for student\n");
    printf("6: Number of students\n");
    printf("7: List IDs of the students\n");
    fflush(stdout);
    PerformOption(ReadOption());
}
