///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "config.h"
#include "Weight.h"

using namespace std;

const Weight::t_weight Weight::UNKNOWN_WEIGHT = -1 ;

const Weight::t_weight Weight::KILOS_IN_A_POUND = 0.453592 ;
const Weight::t_weight Weight::SLUGS_IN_A_POUND = 0.031081 ;

const string Weight::POUND_LABEL = "Pound" ;
const string Weight::KILO_LABEL  = "Kilo" ;
const string Weight::SLUG_LABEL  = "Slug" ;

Weight::Weight() noexcept {
    assert( validate() );
}

Weight::Weight( const Weight::t_weight newWeight ) {
    setWeight( newWeight );
    assert( validate() );
}

//can't change weight once inputted
Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight ) noexcept {
    unitOfWeight = newUnitOfWeight ;
    assert( validate() );
}

//can't change unit of weight once inputted
Weight::Weight( const Weight::t_weight newWeight, const Weight::UnitOfWeight newUnitOfWeight ) : Weight( newUnitOfWeight ) {
    setWeight( newWeight, newUnitOfWeight );
    assert( validate() );
}

Weight::Weight( const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight ) {
    setMaxWeight( newMaxWeight );
    setWeight( newWeight );
    assert( validate() );
}

Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const Weight::t_weight newMaxWeight ) : Weight( newUnitOfWeight ) {
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

Weight::Weight( const Weight::t_weight newWeight
        ,const Weight::UnitOfWeight newUnitOfWeight
        ,const Weight::t_weight newMaxWeight ) : Weight( newUnitOfWeight, newMaxWeight ) {
    setWeight( newWeight );
    assert( validate() );
}

bool Weight::isWeightKnown() const noexcept {
    assert( validate() );

    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    assert( validate() );

    return bHasMax;
}

//unknown weight if not inputted
Weight::t_weight Weight::getWeight() const noexcept {
    assert( validate() );

    if( bIsKnown )
        return weight ;
    else
        return UNKNOWN_WEIGHT ;
}

Weight::t_weight Weight::getWeight( const Weight::UnitOfWeight weightUnits ) const noexcept {
    assert( validate() );

    return convertWeight( weight, unitOfWeight, weightUnits );
}


Weight::t_weight Weight::getMaxWeight() const noexcept {
    assert( validate() );

    if( bHasMax )
        return maxWeight ;
    else
        return UNKNOWN_WEIGHT ;
}


Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    assert( validate() );

    return unitOfWeight ;
}


void Weight::setWeight( const Weight::t_weight newWeight ) {
    assert( validate() );

    if( !isWeightValid( newWeight ) ) {
        //out of range
        throw out_of_range( "Weight is out of range" ) ;
    }

    weight = newWeight ;
    bIsKnown = true ;
    assert( validate() );
}

void Weight::setWeight( const Weight::t_weight newWeight, const Weight::UnitOfWeight weightUnits ) {
    setWeight( convertWeight( newWeight, weightUnits, unitOfWeight ));
}

void Weight::setMaxWeight( const Weight::t_weight newMaxWeight ) {
    assert( !bHasMax );

    if( !isWeightValid( newMaxWeight) ) {
        //max weight if out of range
        throw out_of_range( "The maximum weight is out of range" );
    }

    maxWeight = newMaxWeight;
    bHasMax = true ;

}


bool Weight::isWeightValid( const Weight::t_weight checkWeight ) const noexcept {
    //weight is > than 0
    if( checkWeight <= 0 ) {
        cout << "Weight [" << checkWeight << "] can not be <= 0" << endl ;
        return false;
    }

    if( bHasMax ) {
        if( checkWeight > maxWeight ) {
            cout << "Weight [" << checkWeight << "] is > the maximum weight [" << maxWeight << "]" << endl ;
            return false;
        }
    }

    return true;
}

bool Weight::validate() const noexcept {
    if( bHasMax ) {
        if( !isWeightValid(( maxWeight))) {
            cout << "Max weight is <= 0" << endl;
            return false;
        }

        assert( maxWeight > 0 );
    }

    if( bIsKnown ) {
        if( !isWeightValid( weight ) ) {
            return false;
        }
        assert( weight > 0);

        if( bHasMax ) {
            assert( weight <= maxWeight );
        }
    }
    return true;
}

Weight::t_weight Weight::fromKilogramToPound( const Weight::t_weight kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

Weight::t_weight Weight::fromPoundToKilogram( const Weight::t_weight pound ) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

Weight::t_weight Weight::fromSlugToPound( const Weight::t_weight slug ) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

Weight::t_weight Weight::fromPoundToSlug( const Weight::t_weight pound ) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

Weight::t_weight Weight::convertWeight( const Weight::t_weight fromWeight
        ,const UnitOfWeight fromUnit
        ,const UnitOfWeight toUnit ) noexcept {
    Weight::t_weight commonWeight = UNKNOWN_WEIGHT;

    switch( fromUnit ) {
        case POUND: commonWeight = fromWeight ;
            break;
        case KILO: commonWeight = fromKilogramToPound( fromWeight ) ;
            break;
        case SLUG: commonWeight = fromSlugToPound( fromWeight ) ;
            break;
        default: assert( false );
    }

    Weight::t_weight toWeight = UNKNOWN_WEIGHT;

    switch( toUnit ) {
        case POUND: toWeight = commonWeight ;
            break;
        case KILO: toWeight = fromPoundToKilogram( commonWeight );
            break;
        case SLUG: toWeight = fromPoundToSlug( commonWeight );
            break;
        default: assert( false );
    }

    return toWeight ;
}

void Weight::dump() const noexcept {
    FORMAT_LINE_FOR_DUMP( "Weight", "this" ) << this << endl ;
    FORMAT_LINE_FOR_DUMP( "Weight", "isKnown" ) << bIsKnown << endl ;
    FORMAT_LINE_FOR_DUMP( "Weight", "weight" ) << weight << endl ;
    FORMAT_LINE_FOR_DUMP( "Weight", "unitOfWeight" ) << unitOfWeight << endl ;
    FORMAT_LINE_FOR_DUMP( "Weight", "hasMax" ) << bHasMax << endl ;
    FORMAT_LINE_FOR_DUMP( "Weight", "maxWeight" ) << maxWeight << endl ;
}

std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) {
    stringstream stringBuffer;

    if( !rhs_Weight.isWeightKnown() && !rhs_Weight.hasMaxWeight() ) {
        lhs_stream << "Unknown" ;
        return lhs_stream;
    }
    else if( rhs_Weight.isWeightKnown() ) {
        stringBuffer << rhs_Weight.getWeight();
    } else {
        stringBuffer << "Unknown";
    }

    if( rhs_Weight.hasMaxWeight() ) {
        stringBuffer << " out of " << rhs_Weight.getMaxWeight();
    }

    stringBuffer << " " << rhs_Weight.getWeightUnit() ;

    if(    ( !rhs_Weight.hasMaxWeight() && rhs_Weight.getWeight() > 1 )
           || ( rhs_Weight.hasMaxWeight() && rhs_Weight.getMaxWeight() > 1 ) ) {
        stringBuffer << "s";
    }

    return lhs_stream << stringBuffer.str();
}

std::ostream& operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
        //the unit can't be converted
        default: throw out_of_range( "The unit can not be converted to a string" );
    }
}


bool Weight::operator==( const Weight& rhs_Weight ) const {
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}


bool Weight::operator<( const Weight& rhs_Weight ) const {
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight < rhs_weight;
}


Weight& Weight::operator+=( const Weight::t_weight rhs_addToWeight ) {
    if( !bIsKnown ) {
        //weight is not known
        throw out_of_range( "Weight is unknown" ) ;
    }

    setWeight( weight + rhs_addToWeight );

    return *this;
}

