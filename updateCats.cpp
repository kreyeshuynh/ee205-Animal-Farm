///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "updateCats.h"
#include "catDatabase.h"
#include "addCats.h"

#define PROGRAM_NAME "updateCats.c"


int updateCatName(int index, char newName[]){

    //check if the character array is unique
    for (int i = 0; numCats >= i; i++){
        if (strcmp(newName, catIndex[i].catName) == 0){
            fprintf( stderr, "%s: Cat name [%s] is already in the database.\n",PROGRAM_NAME, newName);
            return false;
            exit(EXIT_FAILURE);
        }
    }
    strcpy(catIndex[index].catName, newName);
    return true;
}

int fixCat(int index){

    catIndex[index].is_fixed = 1;
    return true;
}

int updateCatWeight(int index, float newWeight){

    if (newWeight < 0){

        fprintf( stderr, "%s: Cat weight cannont be less than zero.\n",PROGRAM_NAME);
        return false;
        exit(EXIT_FAILURE);
    }
    else{
        catIndex[index].weight = newWeight;
        return true;
    }

}

int updateCatCollar1(int index, enum Color newCollar1){
    catIndex[index].collarColor1 = newCollar1;
    return true;
}

int updateCatCollar2(int index, enum Color newCollar2){
    catIndex[index].collarColor2 = newCollar2;
    return true;
}

int updateLicense(int index, unsigned long long newLicense){
    catIndex[index].license = newLicense;
    return true;
}

