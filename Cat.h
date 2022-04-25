///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_Animal_Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "config.h"
#include "Mammal.h"

class Cat : public Mammal {
public:
    static const std::string      SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;    //max weight

protected:
    std::string name ;        //name of cat
    bool        isCatFixed ;  //true if cat is fixed

public:
    explicit Cat( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            //if cat does not have a name
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isCatFixed = false;

        Cat::validate();
    }

    // all member variables
    Cat( const std::string&     newName
            ,const Color            newColor
            ,const bool             newIsFixed
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
    ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            //if cat does not have a name
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isCatFixed = newIsFixed;

        Cat::validate();
    }

public:
    std::string getName() const noexcept ;  //getter for cat name
    void setName( const std::string& newName );   //setter for cat name

    bool isFixed() const noexcept ;      //true of cat is fixed
    void fixCat() noexcept ;             //fix the cat

public:
    std::string speak() const noexcept override;  //speak, say meow
    void dump() const noexcept override;          //print content of class
    bool validate() const noexcept override;      //validate cat class

public:
    static bool validateName( const std::string& newName ) ;  //validates newName
};
