///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#pragma once

int updateCatName(int index, char newName[]);

int fixCat(int index);

int updateCatWeight(int index, Weight newWeight);

int updateCatCollar1(int index, enum Color newCollar1);

int updateCatCollar2(int index, enum Color newCollar2);

int updateLicense(int index, unsigned long long newLicense);
