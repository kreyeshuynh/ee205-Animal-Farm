///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 3.0
///
/// @author Kaianu Reyes-Huynh <@kaianu@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "List.h"


class SinglyLinkedList : public List {
public:
    SinglyLinkedList();

public:
    void  push_front( Node* newNode ) ;  //adds new mode to beginning of list
    Node* pop_front() noexcept override; //removes and pops first node

    void insert_after( Node* currentNode, Node* newNode ) ;  //insert new node and current node

    void dump() const noexcept override ;     //output
    bool validate() const noexcept override ; //checks and validates if container is healthy

};
