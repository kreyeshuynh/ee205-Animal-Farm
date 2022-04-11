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



