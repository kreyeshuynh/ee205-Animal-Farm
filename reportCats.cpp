///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "addCats   .h"
#include "catDatabase.h"
#include "reportCats.h"

//print cat given the spot in the database
void printCat(int index){

    if (index < 0 || index > NumCats){
        printf("animalFarm1: Bad Cat [%d]\n", index);
        exit(EXIT_FAILURE);
    }

    printf("cat index = [%d]\tname = ",index);
    printf(catIndex[index].catName);
    printf("\tgender = [%s]\tbreed = [%s]\tisFixed = [%d]\tweight = [%f]\tcollar color 1 = [%s]\tcollar color 2 = [%s]\tlicense = [%lld]\n", genderName(catIndex[index].gender), breedName(catIndex[index].breed), catIndex[index].is_fixed, catIndex[index].weight, colorName(catIndex[index].collarColor1), colorName(catIndex[index].collarColor2), catIndex[index].license);
}

//print all cats
void printAllCats(){
    NumCats = NumCats - 1;
    //go through all of the index while it not going over the ammount stored and print all of the specifications
    for (int index = 0; index <= NumCats; index++){

        printf("cat index = [%d]\tname = ",index);
        printf(catIndex[index].catName);
        printf("\tgender = [%s]\tbreed = [%s]\tisFixed = [%d]\tweight = [%f]\tcollar color 1 = [%s]\tcollar color 2 = [%s]\tlicense = [%lld]\n", genderName(catIndex[index].gender), breedName(catIndex[index].breed), catIndex[index].is_fixed, catIndex[index].weight, colorName(catIndex[index].collarColor1), colorName(catIndex[index].collarColor2), catIndex[index].license);
    }
    NumCats = NumCats + 1;
}

int findCat(char name[]){

    int temp = 0;
    //go through all of the cat names and see if there is a match
    for(int index = 0; index <= NumCats; index++){

        if (strcmp(name, catIndex[index].catName) == 0){
            temp = index;
            index = NumCats + 1;

            printf("cat index = [%d]\n", temp);
            continue;
        }
    }
    return temp;
}
