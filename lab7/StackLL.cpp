//StackLL Class implementation
//Jack Hansen and Jules Weick
//Lab 7 10/27/24
#include <iostream>
#include "StackLL.h"
StackLL::StackLL(){
    //Default constructor for the StackLL class
    //Parameters:
    //none
    //Instantiates:
    //an empty instance of the StackLL class 
    StackLL::contents_ = new LinkedListPlus();
}

StackLL::~StackLL(){
    //Deconstructor to deallocate the Stack 
    //Takes no Parameters, returns nothing
    delete StackLL::contents_;
    StackLL::contents_ = 0;

}

std::string StackLL::toString(){
    //Returns a string of all the characters in the Stack object
    //Parameters:
    //None
    //Returns:
    //a std::string of all the characters
    return StackLL::contents_->ToString();
}

void StackLL::push(char value){
    //Function to add a character to the head of the Stack(ie the left side)
    //Parameters:
    //char value: the char to be added
    //Returns Nothing
    StackLL::contents_->Insert(value, 0);
    
}

char StackLL::pop(){
    //Returns but does not delete the first item in the stack
    //Parameters:
    //None
    //Returns:
    //the first character in the stack
    if (is_empty()) {
        throw std::runtime_error("Stack is empty, cannot pop.");
    }
    return StackLL::contents_->Pop(0);
    
}

char StackLL::peek(){
    //returns the value at the top of the stack
    //Paramaters:
    //None
    //Returns:
    //the value at the top of the stack
    if (is_empty()) {
        throw std::runtime_error("Stack is empty, cannot peek.");
    }
    return contents_->Get(0);

}

int StackLL::get_size(){
    //returns the size of the stack
    //Paramaters:
    //None
    //Returns:
    //an integer representing the size
    return StackLL::contents_->GetSize();

}

bool StackLL::is_empty(){
    //Checks if a Stack is empty or not
    //Paramaters:
    //None
    //Returns:
    //either true or false
    return StackLL::get_size() == 0;
    
}
//#5 from lab instructions:
/*
to turn a string "CS229" into "CS329", we need a total of 6 calls
the calls are as follows:
pop() -> returns "C", "S229" remains
pop() -> returns "S", "229" remains
pop() -> returns "2", "29" remains
push("3") -> adds "3", making the Stack "329"
push("S") -> adds "S", making the stack "S329"
push("C"), adding "C" and completing the transformation to "CS329"
in total, 6 calls were made, 3 push and 3 pop
*/