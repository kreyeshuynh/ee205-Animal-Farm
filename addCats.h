///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////


#include <stdbool.h>
#include "catDatabase.h"
#pragma once


//headerfile for adding cats

extern int addCat( const char CatName[], const enum catGender Gender, const enum catBreed Breed, const bool IsFixed, const Weight Weight, const enum Color CollarColor1, const enum Color CollarColor2, const unsigned long long License );

