///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file deleteCats.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"

#pragma once

/// delete all cats
extern bool deleteAllCats() ;

/// delete a cat given pointer to cat
extern bool deleteCat( Cat* deleteCat ) ;
