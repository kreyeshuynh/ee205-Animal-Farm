///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file config.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iomanip>
#include <iostream>

#define PROGRAM_TITLE "Animal Farm 3"

#define PROGRAM_NAME  "animalfarm3"

#ifdef TRACE

static void TRACE_OUT( const std::string operation, const std::string functionName ) {
   std::cout << PROGRAM_NAME << ": " << operation << " " << functionName << std::endl ;
}

   #define TRACE_START TRACE_OUT( "Start", __FUNCTION__ ) ;  ///< Print `Start` of some function
   #define TRACE_END   TRACE_OUT( "End", __FUNCTION__ ) ;    ///< Print `End` of some function
#else
    #define TRACE_START
    #define TRACE_END
#endif



#define PRINT_HEADING_FOR_DUMP                                                \
    /* Print =========================================================== */   \
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl


/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member )         \
    std::cout << std::setfill( ' ' )  /* Space pad    */  \
              << std::left            /* Left justify */  \
              << std::boolalpha  /* Print `true` or `false` for `bool`s */ \
              << std::setw( 8) << (className)             \
              << std::setw(20) << (member)                \
              << std::setw(52)  /* (data) */

