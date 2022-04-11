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
#include <stdexcept>
#include <cassert>
#include <iostream>

#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"

using namespace std;

Cat* catDatabaseHeadPointer = nullptr;

int numCats = 0;

void initializeDatabase(){
    if(catDatabaseHeadPointer != nullptr){
        throw logic_error( PROGRAM_NAME ": Delete old database")
    }

    assert( validateDatabase());
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
