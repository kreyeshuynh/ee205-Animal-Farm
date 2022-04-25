///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <algorithm>

// Set to trace the flow of execution through this code
// #define TRACE

#include "config.h"
#include "SinglyLinkedList.h"

using namespace std;


SinglyLinkedList::SinglyLinkedList() {
    assert( SinglyLinkedList::validate() );

}


//node add to list
void SinglyLinkedList::push_front(Node *newNode) {
    TRACE_START

    //invalid if newNode = nullptr
    if( newNode == nullptr ) {
        throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr" );
    }

    //if newNode is invalid
    if( !newNode->validate() ) {
        throw domain_error( PROGRAM_NAME ": newNode is not valid" );
    }

    //if newNode is already in container
    if( isIn( newNode ) ) {
        throw logic_error( PROGRAM_NAME ": Node is already in container" );
    }

    assert( validate() );

    //list is not empty
    if( head != nullptr ) {
        newNode->next = head;
        head = newNode;
    } else {	 //list is empty
        newNode->next = nullptr;
        head = newNode;
    }

    count++;
    assert( validate() );

    TRACE_END
}


//return nullptr is list is empty
Node *SinglyLinkedList::pop_front() noexcept {
    TRACE_START

    if( head == nullptr )  //list is empty
        return nullptr;

    assert( validate() );

    Node* returnValue = head;

    //not last node
    if( head->next != nullptr ) {
        head = head->next;
    } else {  // last node
        head = nullptr;
    }

    returnValue->next = nullptr;

    count--;
    assert( validate() );
    assert( returnValue->validate() );

    TRACE_END

    return returnValue;
}

void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    TRACE_START

    //if list is empty
    if( head == nullptr) {
        throw logic_error( PROGRAM_NAME ": Can't insert with an empty List." );
    }

    //if current node = nullptr
    if( currentNode == nullptr ) {
        throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
    }

    //if currentNode is not in the list
    if( !isIn( currentNode )) {
        throw logic_error( PROGRAM_NAME ": currentNode must be in the List." );
    }

    //if newNode = nullptr
    if( newNode == nullptr ) {
        throw invalid_argument( PROGRAM_NAME ": newNode must have a value." );
    }

    //if newNode is not valid
    if( !newNode->validate() ) {
        throw domain_error( PROGRAM_NAME ": newNode is not valid" );
    }

    //if newNode is already in the list
    if( isIn( newNode )) {
        throw logic_error( PROGRAM_NAME ": newNode is already in the List." );
    }

    assert( validate() );

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    count++;
    assert( validate() );

    TRACE_END
}


void SinglyLinkedList::dump() const noexcept {
    cout << "SinglyLinkedList:  head=[" << head << "]" << endl;
    for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
        currentNode->dump();
    }
}


//returns true if list is healthy
bool SinglyLinkedList::validate() const noexcept {
    if( head == nullptr ) {
        assert( count == 0 );
        assert( empty() );
    } else {
        assert( count != 0 );
        assert( !empty() );
    }

    if( head != nullptr ) {
        if( head->next == nullptr ) {
            assert( count == 1 );
        }
    }

    unsigned int forwardCount = 0;
    Node* currentNode = head;

    //go forward in list
    while( currentNode != nullptr ) {
        assert( currentNode->validate() ) ;
        forwardCount++;
        currentNode = currentNode->next;
    }
    assert( size() == forwardCount );


    return true;
}
