/*
 ========================================================================================================
 File Name		: stack.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 10/12/2023
 Description	: This file contains Stack implementation with configurable type (Last in first out)
 Notes			: 
 ========================================================================================================
*/

#ifndef STACK_H_
#define STACK_H_
#include <stdint.h>
#define STACK_element_type uint32_t
/* type definitions */
typedef struct STACK_buf{
	unsigned int length;
	unsigned int count;
	STACK_element_type* base;
	STACK_element_type* head;
} STACK_t;

typedef enum{
	STACK_no_error,
	STACK_full,
	STACK_empty,
	STACK_Null
}STACK_status;


/*APIs*/

STACK_status STACK_push(STACK_t* stack_buf,STACK_element_type item);
STACK_status STACK_pop(STACK_t* stack_buf,STACK_element_type* item);
STACK_status STACK_init(STACK_t* stack_buf,STACK_element_type* buf,unsigned int length);

#endif /* STACK_H_ */
