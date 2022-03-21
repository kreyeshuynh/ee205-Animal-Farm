///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH  51    //Max length of characters in a cat's name
#define MAX_CATS    1024    //Max number of cats in the array

#pragma once

enum catGender { UNKNOWN_GENDER, MALE, FEMALE };
enum catBreed  { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };
enum Color     { BLACK, WHITE, RED, BLUE, GREEN, PINK };

//declaring struct
extern struct Cat{

    char  catName[MAX_CATS];
    enum  catGender gender;
    enum  catBreed breed;
    bool  is_fixed;
    float weight;
    enum  Color collarColor1;
    enum  Color collarColor2;
    unsigned long long license;

} Cat;

extern struct Cat catIndex[MAX_CATS];

//declaring cat description arrays
//extern char  catName[MAX_LENGTH][MAX_CATS];
//extern enum  catGender gender[MAX_CATS];
//extern enum  catBreed breed[MAX_CATS];
//extern bool  is_fixed[MAX_CATS];
//extern float weight[MAX_CATS];


//global variable to indicated the current number of cats
extern int numCats;

//initialize initializeDatabase()
extern void initializeDatabase();

//gender
extern char* genderName (const enum catGender gender);

//breed
extern char* breedName (const enum catBreed breed);

//color
extern char* colorName (const enum Color color );

