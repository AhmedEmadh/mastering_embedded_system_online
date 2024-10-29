/*
 ===========================================================================================================
 File Name		: Student.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 29/10/2024
 Description	: This Module Contains Student type and functions releated to student
 Notes			: 
 ===========================================================================================================
*/

#ifndef SINFO_H_
#define SINFO_H_



typedef struct sinfo
{
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int cid[5];
} Student_t;

void STUDENT_copy(Student_t* Pdestnation,Student_t* Psource);

#endif //SINFO_H_