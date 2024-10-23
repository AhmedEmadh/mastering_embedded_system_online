/*
 ========================================================================================================
 File Name		: stack.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 10/12/2023
 Description	: This file contains Stack implementation with configurable type (Last in first out)
 Notes			: 
 ========================================================================================================
*/
#include "stack.h"

STACK_status STACK_push(STACK_t* stack_buf,STACK_element_type item){
	/* check if valid */
	if(!stack_buf->base || !stack_buf->head)
		return STACK_Null;
	/* check if full */
	/*if(stack_buf->head >= (stack_buf->base + (stack_buf->length * 4)));*/
	if(stack_buf->count == stack_buf->length)
		return STACK_full;
	/* add value */
	*(stack_buf->head) = item;
	stack_buf->head++;
	stack_buf->count++;
	return STACK_no_error;
}
STACK_status STACK_pop(STACK_t* stack_buf,STACK_element_type* item){
	/* check stack is valid */
	if(!stack_buf->base || !stack_buf->head)
		return STACK_Null;
	/* check stack is empty */
	if(stack_buf->count == 0)
		return STACK_empty;
	/* get item */
	stack_buf->head--;
	if(item)
		*item = *(stack_buf->head);
	stack_buf->count--;
	return STACK_no_error;
}

STACK_status STACK_init(STACK_t* stack_buf,STACK_element_type* buf,unsigned int length){
	if(!(stack_buf) || !(buf))
		return STACK_Null;

	stack_buf->base = buf;
	stack_buf->head = buf;
	stack_buf->length = length;
	stack_buf->count = 0;

	return STACK_no_error;
}

