///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>

#include "deleteCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;

//delete cat given pointer to cat
bool deleteCat(Cat* deleteCat){
    assert( deleteCat != nullptr);

    assert( validateDatabase());

    //if the cat is not the first cat in the database then find the cat
    Cat* idexCat = catDatabaseHeadPointer ;
    while( idexCat != nullptr ) {
        if( idexCat->next == deleteCat ) {
            idexCat->next = deleteCat->next ;
            delete deleteCat ;
            numCats--;

            assert( validateDatabase() ) ;

            return true ;
        }
        idexCat = idexCat->next ;
    }

    assert( validateDatabase() ) ;

    throw invalid_argument( PROGRAM_NAME ": Unable to delete cat.  Not in database" );

}

//deletes all cats in database
bool deleteAllCats() {

    while(catDatabaseHeadPointer != nullptr ) {
        deleteCat(catDatabaseHeadPointer ) ;
    }

    numCats = 0 ;

    return true ;
}

