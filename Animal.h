///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "config.h"
#include "Node.h"
#include "Gender.h"
#include "Weight.h"

class Animal : public Node {
public:
    static const std::string KINGDOM_NAME;

private:
    std::string species;                     //animal species
    std::string classification;              //animal classification
    Gender gender = Gender::UNKNOWN_GENDER;  //animal gender
    Weight weight;                           //weight of animal

public:
    /// minimum member variables to create an animal class
    Animal( const Weight::t_weight newMaxWeight
            ,const std::string&     newClassification
            ,const std::string&     newSpecies
    );

    /// all member variables
    Animal( const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newClassification
            ,const std::string&     newSpecies
    );

public:
    std::string getKingdom() const noexcept;         //get kingdom
    std::string getClassification() const noexcept;  //get classification
    std::string getSpecies() const noexcept;         //get species

    Gender getGender() const noexcept;  //get gender

    Weight::t_weight getWeight() const noexcept;         //get weight
    void setWeight( const Weight::t_weight newWeight );  //set weight

public:
    static bool validateClassification( const std::string& checkClassification ) noexcept;  //validate classification status
    static bool validateSpecies( const std::string& checkSpecies ) noexcept;                //validate species status

protected:
    void setGender( const Gender newGender);   //set gender

public:
    virtual std::string speak() const noexcept = 0;  //asks an animal to say something

public:
    void dump() const noexcept override;       //outputs object
    bool validate() const noexcept override;   //validates if object is valid
};
