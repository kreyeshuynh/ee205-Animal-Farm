///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <ostream>

class Weight {
public:  ///Definitions

    enum UnitOfWeight { POUND, KILO, SLUG };

    typedef float t_weight;

public:   ///Constants
    static const t_weight UNKNOWN_WEIGHT ;

    static const t_weight KILOS_IN_A_POUND ;
    static const t_weight SLUGS_IN_A_POUND ;

    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

private:
    bool bIsKnown = false ;
    bool bHasMax = false ;
    enum UnitOfWeight unitOfWeight = POUND ;

    t_weight weight{} ;
    t_weight maxWeight{} ;

public:
    explicit Weight() noexcept;  //get weight
    explicit Weight( t_weight newWeight );  //get new weight
    explicit Weight( UnitOfWeight newUnitOfWeight ) noexcept;  //get weight with unit
    explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );  //get weight in a value with unit
    explicit Weight( t_weight newWeight, t_weight newMaxWeight );  //max weight
    explicit Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  //max unit of weight
    explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  //get weight with unit and max

public:
    bool  isWeightKnown() const noexcept;  //weight is known
    bool  hasMaxWeight() const noexcept;   //maximum weight
    t_weight getWeight() const noexcept;      //weight in unit of measurement
    t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;  //get weight in unit of measurement
    t_weight getMaxWeight() const noexcept;   //get max weight
    UnitOfWeight getWeightUnit() const noexcept;  //get just the unit of weight

public:
    void setWeight( t_weight newWeight );  //setter for weight
    void setWeight( t_weight newWeight, UnitOfWeight weightUnits );  //setter for weight in a unit

private:
    void setMaxWeight( t_weight newMaxWeight );  //max weight

public:
    static float fromKilogramToPound( t_weight kilogram ) noexcept;
    static float fromPoundToKilogram( t_weight pound ) noexcept;
    static float fromSlugToPound( t_weight slug ) noexcept;
    static float fromPoundToSlug( t_weight pound ) noexcept;

    //conversion of weight
    static float convertWeight( t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

public:
    bool isWeightValid( t_weight checkWeight ) const noexcept;  //checks if the weight is valid
    bool validate() const noexcept;   //validates weight class
    void dump() const noexcept;       //prints weight class

public:
    bool operator==( const Weight& rhs_Weight ) const;  //equal weights
    bool operator<( const Weight& rhs_Weight ) const;   //comparison of weights
    Weight& operator+=( t_weight rhs_addToWeight );     //add to weight if it exists
};

std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );
