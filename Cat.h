///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   08_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#pragma once



class Cat {
protected:
    char    name[MAX_LENGTH];
    enum Gender gender ;
    enum Breed  breed ;
    bool isFixed ;
    Weight weight ;

public:
    Cat* next ;

public:
    void zeroOutData();

public:
    Cat();

    Cat( const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) ;

    virtual ~Cat();

    //getters and setters
public:
    const char *getName() const noexcept;
    void setName (const char* newName);
    Gender getGender() const noexcept;
    Breed getBreed() const noexcept;
    bool isFixed() const noexcept;
    Weight getWeight() const noexcept;
    void setWeight(Weight newWeight);

protected:
public:
    void setGender(Gender newGender);
    void setBreed(Breed newBreed);

public:
    bool print() const noexcept;
    bool validate() const noexcept;

public:
    static bool validateName( const char* newName);
    static bool validateGender( const Gender newGender);
    static bool validateBreed (const Breed newBreed);
    static bool validateWeight(const Weight newWeight);

};


#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
