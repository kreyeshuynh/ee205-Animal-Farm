///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <stdbool.h>

#include "Cat.h"
#include "reportCats.h"

using namespace std ;

void Cat::zeroOutData() {
    memset( name, 0, MAX_LENGTH );
    gender = UNKNOWN_GENDER ;
    breed = UNKNOWN_BREED ;
    isCatFixed = false ;
    weight = UNKNOWN_WEIGHT ;
    next = nullptr ;
}

Cat::Cat() {
    zeroOutData() ;
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
    setName( newName ) ;
    setGender( newGender ) ;
    setBreed( newBreed ) ;
    setWeight( newWeight ) ;

    assert( validate() ) ;
}

Cat::~Cat() {
    zeroOutData() ;
}


const char *Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const char *newName) {
    validateName( newName ) ;
    memset( name, 0, MAX_LENGTH);
    strcpy( name, newName );
}

Gender Cat::getGender() const noexcept {
    return gender;
}

Breed Cat::getBreed() const noexcept {
    return breed;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

Weight Cat::getWeight() const noexcept {
    return weight;
}

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

bool Cat::print() const noexcept {
    assert( validate() ) ;

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )         << getName()   << endl ;
    FORMAT_LINE( "Cat", "gender" )       << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )        << breedName( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isFixed" )      << isFixed()   << endl ;
    FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

    return true ;
}


bool Cat::validate() const noexcept {
    try {
        validateName( name ) ;
        validateGender( gender ) ;
        validateBreed( breed ) ;
        validateWeight( weight ) ;
    } catch (exception const& e) {
        cout << e.what() << endl ;
        return false ;
    }
    return true;
}

//if non usable name
bool Cat::validateName(const char *newName) {
    if( newName == nullptr ) {
        throw invalid_argument(PROGRAM_NAME ": name must not be empty");
    }

    if( strlen( newName ) <= 0 ) {
        throw length_error( PROGRAM_NAME ": name length must be > 0");
    }

    if( strlen( newName ) >= MAX_CAT_NAME ) {
        throw length_error( PROGRAM_NAME ": name must be < MAX_LENGTH" );
    }

    return true;
}

//if unknown gender
bool Cat::validateGender(const Gender newGender) {
    if( newGender == UNKNOWN_GENDER ) {
        throw invalid_argument( PROGRAM_NAME ": Gender must be known") ;
    }

    return true;
}

//if breed is unknown breed
bool Cat::validateBreed(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ) {
        throw invalid_argument( PROGRAM_NAME ": Breed must be known" ) ;
    }

    return true;
}

//if weight is less than 0
bool Cat::validateWeight(const Weight newWeight) {
    if( newWeight <= 0 ) {
        throw invalid_argument( PROGRAM_NAME ": Weight must be > 0" ) ;
    }

    return true;
}
//cannot be unfixed
void Cat::fixCat() noexcept {
    Cat::isCatFixed = true;
}


void Cat::setWeight(Weight newWeight) {
    validateWeight( newWeight ) ;
    Cat::weight = newWeight;
}

//set gender
void Cat::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER ) {
        throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
    }

    validateGender( newGender );
    Cat::gender = newGender ;
}

//set breed
void Cat::setBreed(Breed newBreed) {
    if( breed != UNKNOWN_BREED ) {
        throw logic_error( PROGRAM_NAME ": The breed is already set, you can't change it" ) ;
    }

    validateBreed( newBreed ) ;
    Cat::breed = newBreed;
}
