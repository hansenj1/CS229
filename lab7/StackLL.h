//Header file for StackLL
//Jack Hansen and Jules Weick
//Lab 7 10/27/24

#ifndef LLP_STACK
#define LLP_STACK
#include <iostream>
#include "LinkedListPlus.h"

class StackLL {
  private:
    LinkedListPlus* contents_; // Pointer to a LinkedListPlus Object
  public:
    std::string toString();
    void push(char value);
    char pop();
    char peek();
    int get_size();
    bool is_empty();
    
    };
#endif