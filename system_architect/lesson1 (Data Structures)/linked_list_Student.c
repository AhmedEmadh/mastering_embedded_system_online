/*
 ===========================================================================================================
 File Name		: linked_list_Student.c
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

#include <stdlib.h>
#include "linked_list_Student.h"
#include <string.h>

static int is_equal(LINKED_LIST_DATA_TYPE* var1,LINKED_LIST_DATA_TYPE* var2)
{
    return var1->m_ID == var2->m_ID;
}

LINKED_LIST_STATE_t Linked_List_init(Node_t** node,const LINKED_LIST_DATA_TYPE* element)
{
    *node = (Node_t *)malloc(sizeof(Node_t));
    if(!(*node))
        return LINKED_LIST_allocation_error;
    (*node)->data = *element;
    (*node)->next = NULL;
    return LINKED_LIST_no_error;
}
LINKED_LIST_STATE_t LINKED_LIST_Add_at_start(Node_t** node,LINKED_LIST_DATA_TYPE* element)
{
    Node_t* local_node = *node;
    if(!(local_node))
        return LINKED_LIST_NULL_Input;
    Node_t* temp;
    temp = local_node;
    local_node = (Node_t *)malloc(sizeof(Node_t));
    if(!local_node)
        return LINKED_LIST_allocation_error;
    (local_node)->next = temp;
    (local_node)->data = *element;
    *node = local_node;
    return LINKED_LIST_no_error;
}
LINKED_LIST_STATE_t LINKED_LIST_Add_at_end(Node_t** node,LINKED_LIST_DATA_TYPE* element)
{
    if(!(*node))
        return LINKED_LIST_NULL_Input;
    Node_t* local_node = *node;
    /* reach the end node */
    while(local_node->next)
    {
        local_node = local_node->next;
    }
    /* at end node create and Initalize the new node */
    Node_t *new_node;
    LINKED_LIST_STATE_t local_error_state = Linked_List_init(&new_node,element);
    if(local_error_state == LINKED_LIST_no_error)
        local_node->next = new_node;
    return local_error_state;
}
Node_t* LINKED_LIST_Search(Node_t** node, LINKED_LIST_DATA_TYPE* element)
{
    if(!node)
        return NULL;
    Node_t* local_node = *node;
    if(!local_node)
        return NULL;
    while(!is_equal(&(local_node->data), element))
    {
        local_node = local_node->next;
        if(!local_node)
            break;
    }
    return local_node;
}
LINKED_LIST_STATE_t LINKED_LIST_Insert(Node_t** node, LINKED_LIST_DATA_TYPE* element, int index)
{
    if(!node)
        return LINKED_LIST_NULL_Input;
    Node_t* local_node = *node;
    if(!local_node)
        return LINKED_LIST_NULL_Input;
    Node_t* previus_node = NULL;
    for(int i=0;i<index;i++)
    {
        if(!(local_node))
            return LINKED_LIST_out_of_range;
        previus_node = local_node;
        local_node = local_node->next;
    }
    Node_t* local_new_node = NULL;
    LINKED_LIST_STATE_t local_error_state = Linked_List_init(&local_new_node, element);
    if(local_error_state != LINKED_LIST_no_error)
        return local_error_state;
    if(previus_node != NULL)
    {
        local_new_node->next = local_node;
        previus_node->next = local_new_node;
    }
    else 
    {
        local_new_node->next = local_node;
        *node = local_new_node;
    }
    return LINKED_LIST_no_error;
}
LINKED_LIST_STATE_t LINKED_LIST_Delete_element(Node_t** node, LINKED_LIST_DATA_TYPE* element)
{
    Node_t* local_node = *node;
    Node_t* local_previus_node = NULL;
    if(local_node == NULL)
        return LINKED_LIST_NULL_Input;
    while(!is_equal(&(local_node->data), (element)))
    {
        if(local_node->next == NULL)
            return LINKED_LIST_element_not_found;
        local_previus_node = local_node;
        local_node = local_node->next;
    }
    if((local_previus_node != NULL) && (local_node->next != NULL))
    {
        /* if next and previus not null */
        Node_t* next_node = local_node->next;
        free(local_node);
        local_previus_node->next = next_node;
    }
    else if((local_previus_node != NULL) && (local_node->next == NULL))
    {
        free(local_node);
        local_previus_node->next = NULL;
    }
    else if((local_previus_node == NULL) && (local_node->next != NULL))
    {
        Node_t* next_node = local_node->next;
        free(local_node);
        *node = next_node;
    }
    else
    {
        /* if next and previus are NULLs */
        free(local_node);
        node = NULL;
    }
    return LINKED_LIST_no_error;
}
LINKED_LIST_STATE_t LINKED_LIST_Delete_index(Node_t** node, unsigned int index)
{
    if(!node)
    {
        return LINKED_LIST_NULL_Input;
    }
    else if(!(*node))
    {
        return LINKED_LIST_NULL_Input;
    }
    Node_t* local_node = *node;
    Node_t* local_prev_node = NULL;
    for(int i=0;i<index;i++)
    {
        if(local_node == NULL)
            return LINKED_LIST_out_of_range;
        local_prev_node = local_node;
        local_node = local_node->next;
    }
    if(local_node == NULL)
        return LINKED_LIST_out_of_range;
    // Node_t* local_next_node = local_node->next;
    if((local_prev_node != NULL) && (local_node->next != NULL))
    {
        /* if next and previus not null */
        Node_t* next_node = local_node->next;
        free(local_node);
        local_prev_node->next = next_node;
    }
    else if((local_prev_node != NULL) && (local_node->next == NULL))
    {
        free(local_node);
        local_prev_node->next = NULL;
    }
    else if((local_prev_node == NULL) && (local_node->next != NULL))
    {
        Node_t* next_node = local_node->next;
        free(local_node);
        *node = next_node;
    }
    else
    {
        /* if next and previus are NULLs */
        free(local_node);
        *node = NULL;
    }
    
    return LINKED_LIST_no_error;
}
void LINKED_LIST_FREE(Node_t** node)
{
    Node_t* local_node = *node;
    Node_t* previus_node = NULL;
    while(local_node != NULL)
    {
        previus_node = local_node;
        local_node = local_node->next;
        free(previus_node);
    }
    *node = NULL;
}
int LINKED_LIST_Length(Node_t** node)
{
    int counter = 0;
    Node_t* local_node = *node;
    while(local_node != NULL)
    {
        local_node = local_node->next;
        counter++;
    }
    return counter;
}
LINKED_LIST_STATE_t LINKED_LIST_get_index(Node_t** node,LINKED_LIST_DATA_TYPE* element,int* index)
{
    if(!node)
    {
        *index = -1;
        return LINKED_LIST_NULL_Input;
    }
    else if(!(*node))
    {
        *index = -1;
        return LINKED_LIST_NULL_Input;
    }
    Node_t* local_node = *node;
    int local_index = 0;
    while(!is_equal(&local_node->data, element))
    {
        if(local_node->next == NULL)
        {
            *index = -1;
            return LINKED_LIST_element_not_found;
        }
        local_node = local_node->next;
        local_index++;
    }
    *index = local_index;
    return LINKED_LIST_no_error;
}