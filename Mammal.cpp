///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <cassert>

#include "config.h"
#include "Mammal.h"

using namespace std;


const std::string Mammal::MAMMAL_NAME = "Mammilian";


void Mammal::dump() const noexcept {
    assert( validate() ) ;

    Animal::dump() ;

    FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << endl ;
}