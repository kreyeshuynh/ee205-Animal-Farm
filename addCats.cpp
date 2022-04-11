///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>

#include "Cat.h"
#include "addCats.h"
#include "catDatabase.h"

using namespace std;

bool addCat(Cat* newCat){
    assert( newCat != nullptr);
    newCat->validate();

    if(isCatInDatabase( newCat )) {
        throw logic_error( PROGRAM_NAME ": The Cat is already in the database" );
    }
    assert(validateDatabase());

    newCat->next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat ;
    numCats++;

    assert( validateDatabase());

    return true;
}




