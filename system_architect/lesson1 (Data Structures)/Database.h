/*
 ===========================================================================================================
 File Name		: Database.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for controlling linked list database
 Notes			: 
 ===========================================================================================================
 */


#ifndef DATABASE_H_
#define DATABASE_H_
#include "student.h"

typedef enum enDatabaseState
{
    DATABASE_no_error,
    DATABASE_element_not_found,
    DATABASE_undefined_error
} DatabaseState_t;

void DATABASE_AddStudent(Student_t* student);
DatabaseState_t DATABASE_RemoveStudent(unsigned int student_ID);
Student_t DATABASE_SearchForStudent(unsigned int student_ID);
#endif //DATABASE_H_
