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


#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "addCats.h"
#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

using namespace std;

//printing all cats in database
bool printAllCats(){

    int numCats = 0;

    assert( validateDatabase());

    for(Cat* indexCat = catDatabaseHeadPointer ; indexCat != nullptr; indexCat = idexCat->next){
        indexCat->print();
        numCats++;
    }

    assert(validateDatabase());
    return true;
}

Cat* findCatByName(const char* name){

    assert( Cat().validateName( name ));

    for(Cat* indexCat = catDatabaseHeadPointer; idexCat != nullptr; idexCat = idexCat->next){
        if( strcmp(name, idexCat->getName() ) == 0) {
            return indexCat;
        }
    }

    return nullptr;

}

//changes gender enum to gender in string
const char* genderName( const enum Gender gender){

    switch( gender ){
        case UNKNOWN_GENDER: return "Unknown";
        case MALE:           return "Male";
        case FEMALE:         return "Female";
    }
    throw logic_error(PROGRAM_NAME ": Gender does not have string value");

}

//changes breed enum to breed in string
const char* breedName( const enum Breed breed ) {
    switch( breed ) {
        case UNKNOWN_BREED: return "Unknown"    ;
        case MAINE_COON   : return "Maine Coon" ;
        case MANX         : return "Manx"       ;
        case SHORTHAIR    : return "Shorthair"  ;
        case PERSIAN      : return "Persian"    ;
        case SPHYNX       : return "Sphynx"     ;
    }
    throw logic_error(PROGRAM_NAME ": Breed does not have string value");
}

