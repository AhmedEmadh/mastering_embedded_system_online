/*
 ===========================================================================================================
 File Name		: linked_list_Student.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for providing functions and types to deal with Linked List
 Notes			: 
                    It is general linked list that takes anytype
                    It is customized to take student_t objects by editing:
                        - The content of LINKED_LIST_DATA_TYPE macro
                        - Implementing is_equal function that compares two object of the type
 ===========================================================================================================
*/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_




#include "student.h"
#define LINKED_LIST_DATA_TYPE Student_t

typedef struct stNode
{
    LINKED_LIST_DATA_TYPE data;
    struct stNode* next;
} Node_t;

typedef enum enLINKED_LIST_State
{
    LINKED_LIST_no_error,
    LINKED_LIST_NULL_Input,
    LINKED_LIST_allocation_error,
    LINKED_LIST_out_of_range,
    LINKED_LIST_element_not_found
} LINKED_LIST_STATE_t;

LINKED_LIST_STATE_t Linked_List_init(Node_t** node,const LINKED_LIST_DATA_TYPE* element);
LINKED_LIST_STATE_t LINKED_LIST_Add_at_start(Node_t** node,LINKED_LIST_DATA_TYPE* element);
LINKED_LIST_STATE_t LINKED_LIST_Add_at_end(Node_t** node,LINKED_LIST_DATA_TYPE* element);
Node_t* LINKED_LIST_Search(Node_t** node, LINKED_LIST_DATA_TYPE* element);
LINKED_LIST_STATE_t LINKED_LIST_Insert(Node_t** node, LINKED_LIST_DATA_TYPE* element, int index);
LINKED_LIST_STATE_t LINKED_LIST_Delete_element(Node_t** node, LINKED_LIST_DATA_TYPE* element);
void LINKED_LIST_FREE(Node_t** node);
int LINKED_LIST_Length(Node_t** node);
LINKED_LIST_STATE_t LINKED_LIST_Delete_index(Node_t** node, unsigned int index);
LINKED_LIST_STATE_t LINKED_LIST_get_index(Node_t** node,LINKED_LIST_DATA_TYPE* element,int* index);

#endif //LINKED_LIST_H_