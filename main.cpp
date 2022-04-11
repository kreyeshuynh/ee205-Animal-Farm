///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
///
/// @file animalFarm.c
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <kaianu@hawaii.edu>
/// @date   03/20/2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


int main (){

    printf("Starting Animal Farm 1\n\n");

    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;


    printAllCats() ;
    int kali = findCat( "Kali" ) ;
    assert( updateCatName( kali, "Chili" ) == false ) ; // duplicate cat name should fail
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == true ) ;
    assert( updateCatWeight( kali, 9.9 ) == true ) ;
    assert( fixCat( kali ) == true ) ;
    assert( updateCatCollar1( kali, GREEN ) == true ) ;
    assert( updateCatCollar2( kali, GREEN ) == true ) ;
    assert( updateLicense( kali, 201 ) == true ) ;

    printCat( kali ) ;
    printAllCats() ;
    deleteAllCats() ;
    printAllCats() ;

    printf("\nDone with Animal Farm 1\n");

    return( EXIT_SUCCESS ) ;
}
