///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "config.h"
#include "Node.h"

using namespace std;

void Node::dump() const {
    FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << endl ;
    FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << endl ;
}

//comparing nodes by address
bool Node::compareByAddress ( const Node* node1, const Node* node2 ) {
    if( node1 > node2 )
        return true;
    return false;
}


bool Node::operator>(const Node &rightSide) {
    return compareByAddress( this, &(Node&)rightSide );
}

//validate if node is healthy
bool Node::validate() const noexcept {
    if( next == nullptr ) {
        return true;
    }

    if( next == next->next ) {
        cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
        return false;
    }

    return true;
}
