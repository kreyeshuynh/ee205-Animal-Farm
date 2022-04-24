///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "config.h"
#include "Animal.h"

using namespace std;


const std::string Animal::KINGDOM_NAME = "Animalia";


Animal::Animal( const Weight::t_weight newMaxWeight ,const std::string& newClassification ,const std::string& newSpecies ) : Node(), weight( Weight::POUND, newMaxWeight ) {
    if( !validateClassification( newClassification ) ) {
        //invalid argument if classification isn't valid
        throw invalid_argument( "The classification is invalid" );
    }
    classification = newClassification;

    if( !validateSpecies( newSpecies ) ) {
        //invalid species
        throw invalid_argument( "The species is invalid" );
    }
    species = newSpecies;

    Animal::validate();
}


Animal::Animal( const Gender newGender
        ,const Weight::t_weight newWeight
        ,const Weight::t_weight newMaxWeight
        ,const string& newClassification
        ,const string& newSpecies ) : Node(), weight( newWeight, newMaxWeight ) {

    /// @todo Research delegating constructors and then replace the redundant
    ///       code below.

    if( !validateClassification( newClassification ) ) {
        //invalid class
        throw invalid_argument( "The classification is invalid" );
    }
    classification = newClassification;

    if( !validateSpecies( newSpecies ) ) {
        //invalid species
        throw invalid_argument( "The species is invalid" );
    }
    species = newSpecies;

    setGender( newGender );
    Animal::validate();
}


/// This can be `static` but for symmetry with the other `get` methods, I'm
/// leaving it in the class
///
/// @todo Replace with returning a `string_view`
///
/// @return KINGDOM_NAME
std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}


/// @todo Replace with returning a `string_view`
std::string Animal::getClassification() const noexcept {
    return classification;
}


/// @todo Replace with returning a `string_view`
std::string Animal::getSpecies() const noexcept {
    return species;
}


Gender Animal::getGender() const noexcept {
    return gender;
}


Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight() ;
}


void Animal::setWeight( const Weight::t_weight newWeight ) {
    validate();
    weight.setWeight( newWeight );
    validate();
}


void Animal::setGender( const Gender newGender ) {
    if( gender != Gender::UNKNOWN_GENDER ) {
        //can't change gender if gender is set
        throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
    }

    //set gender to unknown
    assert( gender == Gender::UNKNOWN_GENDER );

    validate();
    gender = newGender ;
    validate();
}


bool Animal::validateClassification( const std::string& checkClassification ) noexcept {
    //checks if the classification is empty
    if( checkClassification.empty() ) {
        cout << PROGRAM_NAME ": classification must not be empty" << endl ;
        return false;
    }

    return true;
}


bool Animal::validateSpecies( const std::string& checkSpecies ) noexcept {
    //checks if the species is empty
    if( checkSpecies.empty() ) {
        cout << PROGRAM_NAME ": species must not be empty" << endl ;
        return false;
    }

    return true;
}

void Animal::dump() const noexcept {
    assert( validate() ) ;

    PRINT_HEADING_FOR_DUMP ;

    Node::dump();

    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}

bool Animal::validate() const noexcept {
    assert( Node::validate() );

    assert( !getKingdom().empty() );
    assert( validateClassification(getClassification()) );
    assert( validateSpecies( getSpecies() ));
    assert( weight.validate() );
    return true;
}