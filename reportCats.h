///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "Cat.h"

#pragma once

//print all cats
extern bool printAllCats();

//find cat
extern Cat* findCatByName(const char* name)

//return name of gender
extern const char* genderName( enum Gender gender);

//return name of breed
extern const char* breedName( enum Breed breed);

