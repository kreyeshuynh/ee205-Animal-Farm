///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file List.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

class List {
protected:
    Node* head = nullptr ;
    unsigned int count = 0 ;   //count

public:
    static Node* get_next( const Node* currentNode ) ;  //gets the next node in list

public:
    bool empty() const noexcept ;         //true if list is empty
    unsigned int size() const noexcept ;  //number of nodes in list

    bool isIn( Node* aNode ) const ; //true if aNode is in list
    bool isSorted() const noexcept ; //true if list is sorted

    Node* get_first() const noexcept ;  //get first node in list

    void deleteAllNodes() noexcept ;  //delete all nodes

public:
    virtual Node* pop_front() noexcept = 0 ;     //remove and return first node
    virtual void dump() const noexcept = 0;      //prints content of container
    virtual bool validate() const noexcept = 0;  //validates list if it's healthy
};