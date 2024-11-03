// Header file for LinkedListPlus class
// By: Jules Weick and Jack Hansen

#ifndef LINKED_LIST_PLUS
#define LINKED_LIST_PLUS
#include <iostream>
#include "LLNode.h"
#include "LinkedList.h"

class LinkedListPlus : public LinkedList {
  private:
    LLNode* access_; // A pointer to the last node of the linked list
  public:
    LinkedListPlus();
    LinkedListPlus(char char_array[]);
    char AtAccess();
    void MoveAccess(int index);
    void IncrementAccess();
    void SetAccess(char value);
    char PopAccess();
    void InsertAccess(char value);
    };
#endif