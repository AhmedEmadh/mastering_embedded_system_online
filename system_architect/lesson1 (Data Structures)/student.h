/*
 ===========================================================================================================
 File Name		: student.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for Providing student datetype and student functions
 Notes			: 
 ===========================================================================================================
 */

#ifndef STUDENT_H_
#define STUDENT_H_

typedef struct SStudent
{
    unsigned int m_ID;
    char m_name[40];
    float m_height;
} Student_t;

Student_t STUDENT_CreateStudent(unsigned int ID,const char* name,float height);
void STUDENT_copy(Student_t* Dest,const Student_t* Src);
#endif //STUDENT_H_