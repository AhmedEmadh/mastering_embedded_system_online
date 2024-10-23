/*
 ========================================================================================================
 File Name	 	: queue.c
 Author      	: Ahmed Emad Hassan
 Version     	: 1.0
 Date        	: 11/12/2023
 Description 	: This file contains Queue declarations with configurable type (First in first out)
 Notes       	: 
 ========================================================================================================
*/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "stdint.h"


/****** user configuration ******/

/* select element type: uint8_t uint16_t uint32_t */
#define QUEUE_element_type uint32_t

/****** end user configuration ******/


/* QUEUE data types */
/* pass object reference to functions to make operations on the queue */
typedef struct{
	unsigned int length;
	unsigned int count;
	QUEUE_element_type* base;
	QUEUE_element_type* head;
	QUEUE_element_type* tail;
}QUEUE_t;
/* error state data types returned from functions */
typedef enum{
	QUEUE_no_error,
	QUEUE_full,
	QUEUE_empty,
	QUEUE_Null
}QUEUE_Status;

/* QUEUE functions */
/* initalize Queue by passing struct by refernce to it with all needed paramentrs: used array,length of the array */
QUEUE_Status QUEUE_init(QUEUE_t* queue,QUEUE_element_type* buf,uint32_t length);
/* inserts element to the Queue passed by reference*/
QUEUE_Status QUEUE_enqueue(QUEUE_t* queue, QUEUE_element_type item);
/* removes and reads element from the queue passed by reference*/
QUEUE_Status QUEUE_dequeue(QUEUE_t* queue, QUEUE_element_type* item);
/* checks if passed queue is full and returns QUEUE_full state when full and QUEUE_no_error else */
QUEUE_Status QUEUE_is_full(QUEUE_t* queue);
/* checks if passed queue is empty and returns QUEUE_empty state when empty and QUEUE_no_error else */
QUEUE_Status QUEUE_is_empty(QUEUE_t* queue);
#endif /* QUEUE_H_ */
