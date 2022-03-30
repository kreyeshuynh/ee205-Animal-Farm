///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "addCats.h"
#include "catDatabase.h"

#define PROGRAM_NAME "addCat.c"


int addCat( const char CatName[], const enum catGender Gender, const enum catBreed Breed, const bool IsFixed, const Weight Weight, const enum Color CollarColor1, const enum Color CollarColor2, const unsigned long long License ) {

    size_t nameLength = strlen(CatName);

    //if the number of cats is greater than the database can hold, exit function
    if (numCats > MAX_CATS){
        fprintf( stderr, "%s: Too many cats in the database.\n", PROGRAM_NAME);
        exit(EXIT_FAILURE);
    }
    //if number of characters in name is empty, exit function
    if ( nameLength == 0 ){
        fprintf( stderr, "%s: Cat name cannot be empty.\n", PROGRAM_NAME);
        exit(EXIT_FAILURE);
    }
    //if number of characters in array is greater than 30, exit function
    if ( nameLength > MAX_LENGTH ){

        fprintf( stderr, "%s: Cat name cannot be greater than 30 characters.\n", PROGRAM_NAME);
        exit(EXIT_FAILURE);
    }

    //check if the character array is unique
    if(numCats != 0){
        for (int i = 0; numCats  >= i; i++){
            if (strcmp(CatName, catIndex[i].catName) == 0){

                fprintf( stderr, "%s: Cat name has to be unique.\n", PROGRAM_NAME);
                exit(EXIT_FAILURE);
            }
        }
    }
    //weight cannot be less than 0
    if (Weight < 0){

        fprintf( stderr, "%s: Cat weight cannot be less than 0.\n", PROGRAM_NAME);
        exit(EXIT_FAILURE);
    }
    //store all data into arrays
    strncpy(catIndex[numCats].catName, CatName, MAX_LENGTH);
    catIndex[numCats].gender = Gender;
    catIndex[numCats].breed = Breed;
    catIndex[numCats].is_fixed = IsFixed;
    catIndex[numCats].weight = Weight;
    catIndex[numCats].collarColor1 = CollarColor1;
    catIndex[numCats].collarColor2 = CollarColor2;
    catIndex[numCats].license = License;

    numCats = numCats + 1;

    return numCats;
}
