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

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Student.h"
void STUDENT_copy(Student_t* Pdestnation,Student_t* Psource)
{
    Pdestnation->roll = Psource->roll;
    Pdestnation->GPA = Psource->GPA;
    Pdestnation->cid[0] = Psource->cid[0];
    Pdestnation->cid[1] = Psource->cid[1];
    Pdestnation->cid[2] = Psource->cid[2];
    Pdestnation->cid[3] = Psource->cid[3];
    Pdestnation->cid[4] = Psource->cid[4];
    strcpy(Pdestnation->fname, Psource->fname);
    strcpy(Pdestnation->lname, Psource->lname);
}