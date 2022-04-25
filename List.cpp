///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>

#include "config.h"
#include "List.h"

using namespace std;


//if list is empty
bool List::empty() const noexcept {
    return (head == nullptr);
}

//returns size of list
unsigned int List::size() const noexcept {
    return count ;
}

bool List::isIn(Node *aNode) const {

    //if aNode = nullptr
    if( aNode == nullptr ) {
        throw invalid_argument( PROGRAM_NAME ": aNode must have a value." );
    }

    Node* currentNode = head;

    while( currentNode != nullptr ) {
        if( aNode == currentNode )
            return true;
        currentNode = currentNode->next;
    }

    return false;
}

bool List::isSorted() const noexcept {
    assert( validate() );

    if( count <= 1 )
        return true;

    for( Node* i = head ; i->next != nullptr ; i = i->next ) {
        if( *i > *i->next )  // if the node is greater than the next
            return false;
    }

    return true;
}


//first node in list
Node* List::get_first() const noexcept {
    return head;
}


//starts and current node and goes to the next one
Node* List::get_next(const Node *currentNode) {
    //if currentNode =nullptr
    if( currentNode == nullptr ) {
        throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
    }

    return currentNode->next;
}


void List::deleteAllNodes() noexcept {
    assert( validate() );

    while( head != nullptr ) {
        pop_front();
    }

    assert( validate() );
}