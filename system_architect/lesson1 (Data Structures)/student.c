/*
 ===========================================================================================================
 File Name		: student.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for Providing student datetype and student functions
 Notes			: 
 ===========================================================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "student.h"

Student_t STUDENT_CreateStudent(unsigned int ID,const char* name,float height)
{
    Student_t local_student;
    local_student.m_ID = ID;
    strcpy(local_student.m_name, name); 
    local_student.m_height = height;
    return local_student;
}

void STUDENT_copy(Student_t* Dest,const Student_t* Src)
{
    Dest->m_ID = Src->m_ID;
    Dest->m_height = Src->m_height;
    strcpy(Dest->m_name, Src->m_name);
}