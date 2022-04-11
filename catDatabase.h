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
#include <cstddef>

#define MAX_LENGTH  50    //Max length of characters in a cat's name
#define MAX_CATS    1024    //Max number of cats in the array

#define PROGRAM_TITLE "Animal Farm 2"
#define PROGRAM_NAME "animalfarm2"
#pragma once

enum catGender { UNKNOWN_GENDER, MALE, FEMALE };
enum catBreed  { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };
enum Color     { BLACK, WHITE, RED, BLUE, GREEN, PINK };

//Weight defined type
typedef float Weight;

//define unknown_weight to -1
const Weight UNKNOWN_WEIGHT = -1;

//head pointer for database
extern Cat* catDatabaseHeadPointer ;


extern int numCats ;

//initializes the cat database
extern void initializeDatabase() ;

//verifies if cat is in database
extern bool isCatInDatabase( const Cat* aCat ) ;

//verifies if the database works
extern bool validateDatabase() ;

