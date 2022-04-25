///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>

#include "config.h"

class Node {
    friend class List;
    friend class SinglyLinkedList;

protected:
    Node* next = nullptr;

protected:
    static bool compareByAddress ( const Node* node1, const Node* node2 ) ;

public:
    virtual void dump() const;  //print
    virtual bool validate() const noexcept;  //validate node

    //comparing two nodes
    virtual bool operator>(const Node& rightSide);

    virtual ~Node();
};


