/*
 ============================================================================
 File Name		: queue.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 11/12/2023
 Description	: This file contains Queue implementation with configurable type (First in first out)
 Notes			: 
 ============================================================================
 */
#include "queue.h"

QUEUE_Status QUEUE_init(QUEUE_t* queue,QUEUE_element_type* buf,uint32_t length){
	/* check if there are nulls */
	if(!queue || !buf)
		return QUEUE_Null;
	queue->length = length;
	queue->count = 0;
	queue->base = buf;
	queue->head = buf;
	queue->tail = buf;

	return QUEUE_no_error;
}
QUEUE_Status QUEUE_enqueue(QUEUE_t* queue, QUEUE_element_type item){
	/* check not null */
	if(!queue)
		return QUEUE_Null;
	/* check not full */
	if(queue->count == queue->length)
		return QUEUE_full;
	/* enqueue */
	/* put new item */
	*(queue->tail) = item;
	/*increment tail*/
	if(queue->tail >= (queue->base + queue->length*sizeof(QUEUE_element_type)))
		queue->tail = queue->base;
	else
		queue->tail++;

	/* increment count */
	queue->count++;
	return QUEUE_no_error;
}
QUEUE_Status QUEUE_dequeue(QUEUE_t* queue, QUEUE_element_type* item){
	/* check not null */
	if(!queue || !item)
		return QUEUE_Null;
	/* check not empty */
	if(queue->count == 0)
		return QUEUE_empty;
	/**** dequeue ****/

	/* take item */
	*item = *(queue->head);
	/* increment head */
	if(queue->head >= (queue->base + (queue->length)*sizeof(QUEUE_element_type)))
			queue->head = queue->base;
	else
			queue->head++;
	/* decrement count */
	queue->count--;
	/* return no error */
	return QUEUE_no_error;
}
QUEUE_Status QUEUE_is_full(QUEUE_t* queue){
	/* check not null */
	if(!queue)
		return QUEUE_Null;
	/* check if full */
	if(queue->count == queue->length)
		return QUEUE_full;
	/* return not full */
	return QUEUE_no_error;
}
QUEUE_Status QUEUE_is_empty(QUEUE_t* queue){
	/* check not null */
	if(!queue)
		return QUEUE_Null;
	/* check if empty */
	if(queue->count == 0)
		return QUEUE_empty;
	/* return not empty s*/
	return QUEUE_no_error;
}

uint8_t QUEUE_Get_Count(QUEUE_t* queue){
	return queue->count;
}