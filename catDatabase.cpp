///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "catDatabase.h"


//char  catName[MAX_LENGTH][MAX_CATS];
//enum  catGender gender[MAX_CATS];
//enum  catBreed breed[MAX_CATS];
//bool  is_fixed[MAX_CATS];
//float weight[MAX_CATS];

struct Cat catIndex[MAX_CATS];

int numCats = 0;

void initializeDatabase(){

    //catName initialization
    for(int i = 0; i < MAX_CATS; i++){
        memcpy(catIndex[i].catName,"\0", MAX_LENGTH);
    }

    //gender initialization
    for( int i = 0; i < MAX_CATS; i++){
        catIndex[i].gender = 0;
    }

    //breed initialization
    for( int i = 0; i < MAX_CATS; i++){
        catIndex[i].breed = 0;
    }

    //is_fixed initialization
    for( int i = 0; i < MAX_CATS; i++){
        catIndex[i].is_fixed = 0;
    }

    //weight initialization
    for( int i = 0; i < MAX_CATS; i++){
        catIndex[i].weight = 0.0;
    }
}

//convert gender to strings
extern char* genderName (const enum catGender gender){

    switch (gender){
        case 0:
            return "Unknown Gender";
            break;
        case 1:
            return "Male";
            break;
        case 2:
            return "Female";
            break;
        default:
            return "Non-valid gender";
            exit(EXIT_FAILURE);
    }
}

//convert breed to strings
extern char* breedName (const enum catBreed breed){

    switch (breed){
        case 0:
            return "Unknown Breed";
            break;
        case 1:
            return "Maine Coon";
            break;
        case 2:
            return "Manx";
            break;
        case 3:
            return "Shorthair";
            break;
        case 4:
            return "Persian";
            break;
        case 5:
            return "Sphynx";
            break;
        default:
            return "Non-valid breed";
            exit(EXIT_FAILURE);
    }

}

//convert color to strings
extern char* colorName (const enum Color color ){

    switch (color){
        case 0:
            return "Black";
            break;
        case 1:
            return "White";
            break;
        case 2:
            return "Red";
            break;
        case 3:
            return "Blue";
            break;
        case 4:
            return "Green";
            break;
        case 5:
            return "Pink";
            break;
        default:
            return "Non-valid color";
            exit(EXIT_FAILURE);
    }

}
