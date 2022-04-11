///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   10_Apr_2022
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

//initialize database for cats
void initializeDatabase(){
    if(catDatabaseHeadPointer != nullptr){
        throw logic_error( PROGRAM_NAME ": Delete old database")
    }

    assert( validateDatabase());
}
//verify if cat is in database
bool isCatInDatabase( const Cat* aCat ) {
    assert( aCat != nullptr ) ;

    assert( validateDatabase() ) ;

    for(Cat* idexCat = catDatabaseHeadPointer ; idexCat != nullptr ; idexCat = idexCat->next ) {
        if( idexCat == aCat ) {
            return true ;
        }
    }

    assert( validateDatabase() ) ;

    return false ; 
}
//validates if database is working correctly
extern bool validateDatabase() {
    int validCats = 0 ;

    for(Cat* idexCat = catDatabaseHeadPointer ; idexCat != nullptr ; idexCat = iCat->next ) {
        if( !idexCat->validate() ) {
            return false ;
        }

        Cat* foundCat = findCatByName( idexCat->getName() ) ;
        if( foundCat != iCat ) {
            cout << PROGRAM_NAME ": Warning:  Found a duplicate cat name [" << idexCat->getName() << "]" << endl ;
        }

        validCats++ ;
    }

    if( validCats != numberOfCats ) {
        cout << PROGRAM_NAME << ": Error:  numCats [" << numCats
             << "] does not equal [" << validCats << "]" << endl ;
        return false ;
    }

    return true ;  // The database is healthy
}

