/*
 ===========================================================================================================
 File Name		: Database.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for controlling linked list database
 Notes			: 
 ===========================================================================================================
 */


#include "Database.h"
#include "student.h"
#include "linked_list_Student.h"
#ifndef NULL
#define NULL ((void *)0)
#endif //NULL


Node_t* database_node = NULL;

void DATABASE_AddStudent(Student_t* student)
{
    if(database_node == NULL)
        Linked_List_init(&database_node,student);
    else 
    {
        LINKED_LIST_Add_at_start(&database_node,student);
    }
}
DatabaseState_t DATABASE_RemoveStudent(unsigned int student_ID)
{
    int index;
    Student_t student = STUDENT_CreateStudent(student_ID, "", 0.0f);
    LINKED_LIST_get_index(&database_node,&student,&index);
    if(index == -1)
        return DATABASE_element_not_found;
    
    LINKED_LIST_STATE_t local_linked_list_error_state;
    local_linked_list_error_state = LINKED_LIST_Delete_index(&database_node, index);
    if(local_linked_list_error_state != LINKED_LIST_no_error)
        return DATABASE_undefined_error;

    return DATABASE_no_error;
}
Student_t DATABASE_SearchForStudent(unsigned int student_ID)
{
    Student_t student = STUDENT_CreateStudent(student_ID, "", 0.0f);
    Node_t* node = LINKED_LIST_Search(&database_node,&student);
    STUDENT_copy(&student,&node->data);
    return student;
}
