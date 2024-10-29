/*
 ===========================================================================================================
 File Name		: main.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 29/10/2024
 Description	: This File contains the main code and functions
 Notes			: 
 ===========================================================================================================
*/

#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Student.h"
#include "queue.h"
#include "Input_Validate.h"
#define printff(_val_, ...) do{printf(_val_, ##__VA_ARGS__); fflush(stdout);} while(0)
#define scanff(_format_, _val_)  do { scanf(_format_, _val_); fflush(stdin); } while(0)
typedef unsigned char bool;
#define true        1
#define false       0
#define BuffLength 100

Student_t st[55];
Student_t sBuff[BuffLength];
QUEUE_t database;


bool isStudentExist(QUEUE_t *pQueue,Student_t* Pstudent)
{
    Student_t LocalSbuff[BuffLength];
    QUEUE_t tempQueue;
    Student_t tempStudent;
    bool isStudentExist = false;
    QUEUE_init(&tempQueue, LocalSbuff, BuffLength);
    while(QUEUE_dequeue(pQueue, &tempStudent) == QUEUE_no_error)
    {
        QUEUE_enqueue(&tempQueue,tempStudent);
        if(tempStudent.roll == Pstudent->roll)
            isStudentExist = true;
    }
    while(QUEUE_dequeue(&tempQueue, &tempStudent) == QUEUE_no_error)
    {
        QUEUE_enqueue(pQueue, tempStudent);
    }
    return isStudentExist;
}

typedef enum{
    add_student_error_state_no_Error,
    add_student_error_state_Student_Found,
    add_student_error_state_File_Not_Exist
}add_student_error_state_t;

add_student_error_state_t add_student_file()
{
    FILE *file = fopen("file.txt", "r");
    add_student_error_state_t LocaladdStudentErrorState = add_student_error_state_no_Error;
    if(file == NULL)
        return add_student_error_state_File_Not_Exist;
    char buffer[100];
    Student_t student;
    while(fgets(buffer, 100, file))
    {
        sscanf(buffer,"%d %s %s %f %d %d %d %d %d",&student.roll,student.fname,student.lname,&student.GPA,&student.cid[0],&student.cid[1],&student.cid[2],&student.cid[3],&student.cid[4]);
        if(!isStudentExist(&database, &student))
            QUEUE_enqueue(&database, student);
        else 
        {
            printff("[WARNING] Couldn't add the student with roll number: %d\n",student.roll);
            //LocaladdStudentErrorState = add_student_error_state_Student_Found;
        }
    }   
    
    fclose(file);
    return LocaladdStudentErrorState;
}
void Add_students_From_File()
{
    add_student_error_state_t local_error_state = add_student_error_state_no_Error;
    local_error_state = add_student_file();
    if(local_error_state == add_student_error_state_no_Error)
        printff("\n\n[INFO] The Students added Successfully\n\n");
    else 
    {
        printff("[ERROR] The Studends didn't added successfully\n");
    }
}
void add_student_manually()
{
    Student_t LocalStudent;
    bool LocalisStudentExist = false;
    do
    {
        if(LocalisStudentExist)
            printff("[ERROR] the roll exists please enter student Data again\n");   
        printff("Enter Student roll: ");
        scanff("%d",&LocalStudent.roll);
        printff("Enter Student First Name: ");
        scanff("%s",LocalStudent.fname);
        printff("Enter Student Last Name: ");
        scanff("%s",LocalStudent.lname);
        printff("Enter Student GPA: ");
        scanff("%f",&LocalStudent.GPA);
        printff("Enter The ID of the first course: ");
        scanff("%d",&LocalStudent.cid[0]);
        printff("Enter The ID of the secound course: ");
        scanff("%d",&LocalStudent.cid[1]);
        printff("Enter The ID of the third course: ");
        scanff("%d",&LocalStudent.cid[2]);
        printff("Enter The ID of the forth course: ");
        scanff("%d",&LocalStudent.cid[3]);
        printff("Enter The ID of the fifth course: ");
        scanff("%d",&LocalStudent.cid[4]);
        LocalisStudentExist = isStudentExist(&database, &LocalStudent);
    }while(LocalisStudentExist);
    
    QUEUE_enqueue(&database, LocalStudent);
    printff("\n\n[INFO] the student added successfully\n\n");   
    
}

typedef enum 
{
    ScreenOption_Add_Student_Manualy = 1,
    ScreenOption_AddStudentsFromFile = 2,
    ScreenOption_SearchStudentByRollNumber = 3,
    ScreenOption_SearchStudentByFirstName = 4,
    ScreenOption_SearchStudentsByCourse = 5,
    ScreenOption_FindTheTotalNumberOfStudents = 6,
    ScreenOption_DeleteStudentDetailesByRollNumber = 7,
    ScreenOption_UpdateStudentDetailesByRollNumber = 8,
    ScreenOption_ShowAllInformation = 9,
    ScreenOption_Exit = 10,
} ScreenOption_t;

void printStudent(Student_t *Pstudent)
{
    printff("===============================================\n");
    printff("Student First Name: %s\n",Pstudent->fname);
    printff("Student Last Name: %s\n",Pstudent->lname);
    printff("Student Roll number: %d\n",Pstudent->roll);
    printff("Student GPA: %f\n",Pstudent->GPA);
    printff("Student Course 1 ID: %d\n",Pstudent->cid[0]);
    printff("Student Course 2 ID: %d\n",Pstudent->cid[1]);
    printff("Student Course 3 ID: %d\n",Pstudent->cid[2]);
    printff("Student Course 4 ID: %d\n",Pstudent->cid[3]);
    printff("Student Course 5 ID: %d\n",Pstudent->cid[4]);
    printff("===============================================\n\n");
}

void ShowAllInfo()
{
    Student_t Localbuff[BuffLength];
    Student_t student;
    QUEUE_t tempDatabase;
    bool isInformationExist = false;
    QUEUE_init(&tempDatabase, Localbuff, BuffLength);

    while(QUEUE_dequeue(&database, &student) == QUEUE_no_error)
    {
        isInformationExist = true;
        printStudent(&student);
        QUEUE_enqueue(&tempDatabase, student);
    }
    while (QUEUE_dequeue(&tempDatabase, &student) == QUEUE_no_error) {
        QUEUE_enqueue(&database, student);
    }
    if(!isInformationExist)
    {
        printff("\n\n===============================================\n");
        printff("No Information to show\n");
        printff("===============================================\n\n");
    }
}

typedef enum 
{
    DELETE_Student_Deleted,
    DELETE_Student_Not_Found
} DeleteStudentErrorState_t;


DeleteStudentErrorState_t deleteStudent(int CopyRoll)
{
    DeleteStudentErrorState_t local_error_state = DELETE_Student_Not_Found;
    Student_t localBuff[BuffLength];
    QUEUE_t localTempDatabase;
    Student_t tempStudent;
    QUEUE_init(&localTempDatabase, localBuff, BuffLength);

    while(QUEUE_dequeue(&database,&tempStudent) == QUEUE_no_error)
    {
        if(tempStudent.roll != CopyRoll)
            QUEUE_enqueue(&localTempDatabase, tempStudent);
        else
            local_error_state = DELETE_Student_Deleted;
    }
    while (QUEUE_dequeue(&localTempDatabase, &tempStudent) == QUEUE_no_error)
    {
        QUEUE_enqueue(&database, tempStudent);
    }

    return local_error_state;
}

void deleteStudentByRoll()
{
    int localRoll;
    printff("\nEnter Student Roll to delete: ");
    scanff("%d",&localRoll);
    if(deleteStudent(localRoll) == DELETE_Student_Deleted)
        printff("\n[INFO] Student deleted Successfully\n\n");
    else
        printff("\n[ERROR] Student not found\n\n");
}

void FindTheTotalNumberOfStudents()
{
    printff("\nThe total Number of students is: %d\n\n",database.count);
}

void UpdateStudent(Student_t* PStudent)
{
    printff("Updating Student\n");
    printff("Enter First Name: ");
    scanff("%s",PStudent->fname);
    printff("Enter Last Name: ");
    scanff("%s",PStudent->lname);
    printff("Enter GPA: ");
    scanff("%f",&PStudent->GPA);
    printff("Enter Student Course 1 ID: ");
    scanff("%d",&PStudent->cid[0]);
    printff("Enter Student Course 2 ID: ");
    scanff("%d",&PStudent->cid[1]);
    printff("Enter Student Course 3 ID: ");
    scanff("%d",&PStudent->cid[2]);
    printff("Enter Student Course 4 ID: ");
    scanff("%d",&PStudent->cid[3]);
    printff("Enter Student Course 5 ID: ");
    scanff("%d",&PStudent->cid[4]);
    
}

void UpdateStudentByRoll()
{
    int localRoll;
    printff("Enter Roll Number of Student to update: ");
    scanff("%d",&localRoll);
    Student_t localBuff[BuffLength];
    QUEUE_t localTempDatabase;
    Student_t tempStudent;
    bool isStudentFound = false;
    QUEUE_init(&localTempDatabase, localBuff, BuffLength);

    while(QUEUE_dequeue(&database,&tempStudent) == QUEUE_no_error)
    {
        if(tempStudent.roll == localRoll)
        {
            isStudentFound = true;
            UpdateStudent(&tempStudent);
        }
        QUEUE_enqueue(&localTempDatabase, tempStudent);
    }
    while (QUEUE_dequeue(&localTempDatabase, &tempStudent) == QUEUE_no_error)
    {
        QUEUE_enqueue(&database, tempStudent);
    }
    if(isStudentFound)
        printff("\n[INFO] Student Updated Successfully\n\n");
    else 
        printff("\n[ERROR] Cannot find student\n\n");
}


typedef enum 
{
    FIND_STUDENT_Found,
    FIND_STUDENT_NotFound
}FIND_Student_State_t;

FIND_Student_State_t FindStudentByRollNumber(int CopyRoll,Student_t* PStudent)
{
    Student_t LocalBuff[BuffLength];
    bool isStudentFound = false;
    QUEUE_t localTempDatabase;
    Student_t tempStudent;
    QUEUE_init(&localTempDatabase, LocalBuff, BuffLength);
    while(QUEUE_dequeue(&database,&tempStudent) == QUEUE_no_error)
    {
        if(tempStudent.roll == CopyRoll)
        {
            isStudentFound = true;
            STUDENT_copy(PStudent, &tempStudent);
        }
        QUEUE_enqueue(&localTempDatabase, tempStudent);
    }
    while (QUEUE_dequeue(&localTempDatabase, &tempStudent) == QUEUE_no_error)
    {
        QUEUE_enqueue(&database, tempStudent);
    }
    if(isStudentFound)
        return FIND_STUDENT_Found;
    else 
    {
        return FIND_STUDENT_NotFound;
    }
}

void SearchStudentByRollNumber()
{
    int localRoll;
    Student_t localStudent;
    printff("Enter Roll Number of Student to find: ");
    scanff("%d",&localRoll);
    if(FindStudentByRollNumber(localRoll,&localStudent) == FIND_STUDENT_Found)
    {
        printStudent(&localStudent);
    }
    else 
    {
        printff("\n[ERROR] Student Not Found\n\n");
    }

}


FIND_Student_State_t FindStudentByFirstName(char* FirstName,QUEUE_t* PQueueFoundStudents)
{
    Student_t local_buff[BuffLength];
    FIND_Student_State_t local_error_state = FIND_STUDENT_NotFound;
    Student_t tempStudent;
    QUEUE_t tempDatabase;
    QUEUE_init(&tempDatabase, local_buff, BuffLength);

    while (QUEUE_dequeue(&database, &tempStudent) == QUEUE_no_error) {
        if(!strcmp(tempStudent.fname, FirstName)) /* if names are equal */
        {
            local_error_state = FIND_STUDENT_Found;
            QUEUE_enqueue(PQueueFoundStudents, tempStudent);
        }
        QUEUE_enqueue(&tempDatabase, tempStudent);
    }
    while (QUEUE_dequeue(&tempDatabase, &tempStudent) == QUEUE_no_error) {
        QUEUE_enqueue(&database, tempStudent);
    }


    return local_error_state;
}

void printStudentsQueue(QUEUE_t* PQueue)
{
    Student_t local_buff[BuffLength];
    Student_t local_temp_student;
    QUEUE_t tempQueue;
    QUEUE_init(&tempQueue, local_buff, BuffLength);
    while(QUEUE_dequeue(PQueue, &local_temp_student) == QUEUE_no_error)
    {
        printStudent(&local_temp_student);
        QUEUE_enqueue(&tempQueue, local_temp_student);
    }
    while(QUEUE_dequeue(&tempQueue, &local_temp_student) == QUEUE_no_error)
    {
        QUEUE_enqueue(PQueue, local_temp_student);
    }

}

void SearchStudentByFirstName()
{
    Student_t buff[BuffLength];
    char LocalFirstName[50];
    QUEUE_t local_found_students;
    QUEUE_init(&local_found_students, buff, BuffLength);
    printff("Enter First Name of Students to find: ");
    scanff("%s",LocalFirstName);
    if(FindStudentByFirstName(LocalFirstName,&local_found_students) == FIND_STUDENT_Found)
    {
        printStudentsQueue(&local_found_students);
    }
    else 
    {
        printff("\n[ERROR] Student Not Found\n\n");
    }
}

FIND_Student_State_t FindStudentsByCourseID(int courseID,QUEUE_t* PQueueFoundStudents)
{
    Student_t local_buff[BuffLength];
    FIND_Student_State_t local_error_state = FIND_STUDENT_NotFound;
    Student_t tempStudent;
    QUEUE_t tempDatabase;
    QUEUE_init(&tempDatabase, local_buff, BuffLength);

    while (QUEUE_dequeue(&database, &tempStudent) == QUEUE_no_error) {
        if((tempStudent.cid[0] == courseID)||(tempStudent.cid[1] == courseID)||(tempStudent.cid[2] == courseID)||
        (tempStudent.cid[3] == courseID)||(tempStudent.cid[4] == courseID)) 
        { /* if Student take the course */
            local_error_state = FIND_STUDENT_Found;
            QUEUE_enqueue(PQueueFoundStudents, tempStudent);
        }
        QUEUE_enqueue(&tempDatabase, tempStudent);
    }
    while (QUEUE_dequeue(&tempDatabase, &tempStudent) == QUEUE_no_error) {
        QUEUE_enqueue(&database, tempStudent);
    }


    return local_error_state;
}
void SeachStudentsByCourse()
{
    Student_t buff[BuffLength];
    int courseID;
    QUEUE_t local_found_students;
    QUEUE_init(&local_found_students, buff, BuffLength);
    printff("Enter Course ID of Students to find: ");
    scanff("%d",&courseID);
    if(FindStudentsByCourseID(courseID,&local_found_students) == FIND_STUDENT_Found)
    {
        printStudentsQueue(&local_found_students);
    }
    else 
    {
        printff("\n[ERROR] Student Not Found\n\n");
    }
}
bool PerformOption(ScreenOption_t option)
{
    bool LocalResult = true;
    switch (option) {
    case ScreenOption_Add_Student_Manualy:
    {
        add_student_manually();
        break;
    }
    case ScreenOption_AddStudentsFromFile:
    {
        Add_students_From_File();
        break;
    }
    case ScreenOption_SearchStudentByRollNumber:
    {
        SearchStudentByRollNumber();
        break;
    }
    case ScreenOption_SearchStudentByFirstName:
    {
        SearchStudentByFirstName();
        break;
    }
    case ScreenOption_SearchStudentsByCourse:
    {
        SeachStudentsByCourse();
        break;
    }
    case ScreenOption_FindTheTotalNumberOfStudents:
    {
        FindTheTotalNumberOfStudents();
        break;
    }
    case ScreenOption_DeleteStudentDetailesByRollNumber:
    {
        deleteStudentByRoll();
        break;
    }
    case ScreenOption_UpdateStudentDetailesByRollNumber:
    {
        UpdateStudentByRoll();
        break;
    }
    case ScreenOption_ShowAllInformation:
    {
        ShowAllInfo();
        break;
    }
    case ScreenOption_Exit:
    {
        LocalResult = false;
        break;
    }
    
    }
    return LocalResult;
}

int main()
{
    QUEUE_init(&database,sBuff, BuffLength);
    printff("Welcome to the Student Management System\n");
    while(1)
    {
        printff("Choose The Task that you want to perform\n");
        printff(" 1. Add the Student Details Manually\n");
        printff(" 2. Add the Student Details From Text File\n");
        printff(" 3. Search the Student Details by roll number\n");
        printff(" 4. Search the Student Details by First Name\n");
        printff(" 5. Search the Student Details by Course\n");
        printff(" 6. Get the total number of students\n");
        printff(" 7. Delete the Students Details by Roll Number\n");
        printff(" 8. Update the Students Details by Roll Number\n");
        printff(" 9. Show all information\n");
        printff("10. To Exit\n");
        printff("Enter your choice to perform the task: ");
        if(!PerformOption((ScreenOption_t)INPUT_VALIDATE_IntInputBetween(1, 10)))
            break;
    }

    return 0;
}