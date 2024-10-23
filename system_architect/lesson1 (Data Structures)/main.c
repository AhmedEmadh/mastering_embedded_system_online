/*
 ===========================================================================================================================================
 File Name		: main.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This file is contains main function where the program starts execution
 Notes			: The program calls the function to show UI and don't exit this function to handle user input like in GUI applications
 ===========================================================================================================================================
*/
#include "Main_screen.h"
#include "linked_list_Student.h"
extern Node_t* database_node;
int main()
{
    while(1)
    {
        Main_Screen_Show_Main_Screen();
    }
    return 0;
}