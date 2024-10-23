/*
 ===========================================================================================================
 File Name		: Input_Validate.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 23/10/2024
 Description	: This Module is responsible for Validating different input types
 Notes			: It ensures that the input from user at the form that we want
 ===========================================================================================================
*/

#ifndef INPUT_VALIDATE_H_
#define INPUT_VALIDATE_H_

int INPUT_VALIDATE_IntInputBetween(int start, int end);
int INPUT_VALIDATE_validate_string(char *str, int size);
int INPUT_VALIDATE_PositiveIntInput();
int INPUT_VALIDATE_IntInput();
float INPUT_VALIDATE_PositiveFloatInput();
float INPUT_VALIDATE_FloatInput();
#endif //INPUT_VALIDATE_H_
