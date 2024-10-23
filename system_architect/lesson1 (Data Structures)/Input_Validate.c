/*
 ===========================================================================================================
 File Name		: Input_Validate.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for Validating different input types
 Notes			: It ensures that the input from user at the form that we want
 ===========================================================================================================
*/


#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "Input_Validate.h"
/*****************************  Static Helper Functions  *****************************/
static void INPUT_VALIDATE_clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Discard invalid input
}
// Function to trim leading and trailing whitespace
static void trim_whitespace(char *str)
{
    int len = strlen(str);

    // Trim trailing whitespace
    while(len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }

    // Trim leading whitespace
    char *start = str;
    while(*start && isspace((unsigned char)*start)) {
        start++;
    }

    // Move the trimmed string back to the start
    if(start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}
/*****************************  Validate Functions  *****************************/

int INPUT_VALIDATE_IntInputBetween(int start, int end)
{
    int input;
    int result;  // To store the result of scanf

    printf("Enter a number between %d and %d: ", start, end);
    fflush(stdout);

    // Read input and validate
    result = scanf("%d", &input);
    INPUT_VALIDATE_clear_input_buffer();  // Clear remaining input buffer after scanf

    // Loop until the input is valid (correct type and within range)
    while (result != 1 || (input < start || input > end)) {
        printf("Invalid input. Please enter a number between %d and %d: ", start, end);
        fflush(stdout);
        
        result = scanf("%d", &input);  // Attempt to read input again
        INPUT_VALIDATE_clear_input_buffer();  // Clear the input buffer after scanf
    }

    return input;
}

// Function to read and validate a string
int INPUT_VALIDATE_validate_string(char *str, int size)
{
    //printf("Enter a string: ");

    // Read string with fgets
    if(fgets(str, size, stdin)) {
        // Remove the newline character, if present
        str[strcspn(str, "\n")] = '\0';

        // Trim any leading or trailing spaces
        trim_whitespace(str);

        // Check if the string is not empty after trimming
        if(strlen(str) == 0) {
            printf("Error: String cannot be empty.\n");
            return 0;  // Invalid string
        }

        //printf("Valid string entered: %s\n", str);
        return 1;  // Valid string
    } else {
        printf("Error: Input failure.\n");
        return 0;  // Invalid string
    }
}

// Function to read and validate a positive integer
int INPUT_VALIDATE_PositiveIntInput()
{
    int input;
    int result;  // To store the result of scanf

    //printf("Enter a positive integer: ");
    fflush(stdout);

    // Read input and validate
    result = scanf("%d", &input);
    INPUT_VALIDATE_clear_input_buffer();  // Clear remaining input buffer after scanf

    // Loop until the input is valid (correct type and positive)
    while (result != 1 || input <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        fflush(stdout);

        result = scanf("%d", &input);  // Attempt to read input again
        INPUT_VALIDATE_clear_input_buffer();  // Clear the input buffer after scanf
    }

    return input;
}

// Function to read and validate any integer
int INPUT_VALIDATE_IntInput()
{
    int input;
    int result;  // To store the result of scanf

    //printf("Enter any integer: ");
    fflush(stdout);

    // Read input and validate
    result = scanf("%d", &input);
    INPUT_VALIDATE_clear_input_buffer();  // Clear remaining input buffer after scanf

    // Loop until the input is valid (correct type)
    while (result != 1) {
        printf("Invalid input. Please enter any integer: ");
        fflush(stdout);

        result = scanf("%d", &input);  // Attempt to read input again
        INPUT_VALIDATE_clear_input_buffer();  // Clear the input buffer after scanf
    }

    return input;
}

// Function to read and validate a positive float
float INPUT_VALIDATE_PositiveFloatInput()
{
    float input;
    int result;  // To store the result of scanf

    //printf("Enter a positive float: ");
    fflush(stdout);

    // Read input and validate
    result = scanf("%f", &input);
    INPUT_VALIDATE_clear_input_buffer();  // Clear remaining input buffer after scanf

    // Loop until the input is valid (correct type and positive)
    while (result != 1 || input <= 0) {
        printf("Invalid input. Please enter a positive float: ");
        fflush(stdout);

        result = scanf("%f", &input);  // Attempt to read input again
        INPUT_VALIDATE_clear_input_buffer();  // Clear the input buffer after scanf
    }

    return input;
}

// Function to read and validate any float
float INPUT_VALIDATE_FloatInput()
{
    float input;
    int result;  // To store the result of scanf

    //printf("Enter any float: ");
    fflush(stdout);

    // Read input and validate
    result = scanf("%f", &input);
    INPUT_VALIDATE_clear_input_buffer();  // Clear remaining input buffer after scanf

    // Loop until the input is valid (correct type)
    while (result != 1) {
        printf("Invalid input. Please enter any float: ");
        fflush(stdout);

        result = scanf("%f", &input);  // Attempt to read input again
        INPUT_VALIDATE_clear_input_buffer();  // Clear the input buffer after scanf
    }

    return input;
}