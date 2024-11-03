// .cpp file for LinkedListPlus class 
// By: Jack Hansen and Jules Weick

#include <iostream>
#include <cstring>
#include "LLNode.h"
#include "LinkedList.h"
#include "LinkedListPlus.h"

// Default constructor for the LinkedListPlus class when no parameters are passed.
// Parameters:
// None.
// Instantiates:
// An instance of the class with the access_ attribute set to the head_ pointer
// and the attributes from LinkedList() instantiated.
LinkedListPlus::LinkedListPlus() {
  LinkedListPlus::size_ = 0;
  LinkedListPlus::head_ = 0;
  LinkedListPlus::access_ = 0;
}

// Non-default constructor for the LinkedListPlus class when a char array is passed in.
// Parameters:
// 1. char_array[] (char array): A cstring containing chars to instantiate the linked list with.
// Instantiates:
// An instance of the LinkedListPlus class with nodes for each char of char_array.
LinkedListPlus::LinkedListPlus(char char_array[]) {
  if (strlen(char_array) == 0) {
    LinkedListPlus();
  } else {
  LinkedListPlus::head_ = new LLNode(char_array[0]);
  LLNode* current_node = LinkedListPlus::head_;

  for (int i = 1; i < strlen(char_array); i++) {
    LLNode* new_node = new LLNode(char_array[i]);
    current_node->next_ = new_node;
    current_node = new_node;
  }
  LinkedListPlus::access_ = current_node;
  LinkedListPlus::size_ = strlen(char_array);
 }
}

// Returns the char stored at access_, which is the last node of the linked list.
// Parameters:
// None.
// Returns:
// The character stored in the node pointed to by access_.
char LinkedListPlus::AtAccess() {
  return LinkedListPlus::access_->data_;
}

// Moves the access pointer to the index passed in.
// Parameters:
// 1. index (int): The index to move the access pointer to.
// Returns:
// Nothing. Rather, moves the index of the access pointer.
void LinkedListPlus::MoveAccess(int index) {
  LLNode* current_node = LinkedListPlus::head_;
  int counter = 0;

  if (index < 0 || index > LinkedListPlus::size_) {
    std::cout << "Error: Index is invalid.\n";
    return;
  }

  while (current_node->next_ != 0 && counter < index) {
    current_node = current_node->next_;
    counter++;
  }

  LinkedListPlus::access_ = current_node;
}

// Moves the access pointer to the index to the next node in the linked list.
// Parameters:
// None.
// Returns:
// Nothing. Rather, moves the index of the access pointer to the next node in the 
// linked list, assuming that there is one.
void LinkedListPlus::IncrementAccess() {
  if (LinkedListPlus::access_->next_ != 0) {
    LinkedListPlus::access_ = LinkedListPlus::access_->next_;
  } else {
    std::cout << "Error: Unable to increment access_ as it is the last node.\n";
  }
}

// Sets the character stored at access to the value passed in.
// Parameters:
// 1. value (char): The character to set the node access_ is pointing at to store.
// Returns:
// Nothing. Rather, changes the value of the node acess_ is pointing at.
void LinkedListPlus::SetAccess(char value) {
  LinkedListPlus::access_->data_ = value;
}

// Returns and removes the node after the node access_ is pointing at.
// Parameters:
// None.
// Returns:
// The character of the node after the node access_ is pointing at.
char LinkedListPlus::PopAccess() {
  char result = '\0';

  if (LinkedListPlus::size_ == 0) {
    std::cout << "Error: Linked list is empty, nothing to pop.\n";
    return result;
  }
  
  // if there are at least two nodes after the node the access_ pointer
  // is pointing at.
  if (access_->next_ != 0 && access_->next_->next_ != 0) {
    LLNode* tail = access_->next_->next_; // access_ = LinkedListPlus::access_
    LLNode* remove = access_->next_;
    result = remove->data_;
    access_->next_ = tail;
    remove->next_ = 0;
    delete remove;
    remove = 0;
    LinkedListPlus::size_ -= 1;
    return result;
  }
  // case of node after access_ being the last node in the linked list.
  else if (access_->next_ != 0) {
    LLNode* remove = access_->next_;
    result = remove->data_;
    access_->next_ = 0;
    delete remove;
    LinkedListPlus::size_--;
    return result;
    // if there is no node after access, there is nothing to pop from the linked list
    // using this method.
  } else {
    std::cout << "Error: Access is the last node, so there is nothing to pop.\n";
    return result;
  }
  return result;
}

// Inserts a new node with value as its data member after the node 
// access_ is pointing at.
// Parameters:
// 1. value (char): The character to create the new node with to go after
//                  the node access_ is pointing at.
// Returns:
// Nothing. Rather, creates a new node after the node access_ is pointing at.
void LinkedListPlus::InsertAccess(char value) {
  LLNode* new_node = new LLNode(value);

  if (LinkedListPlus::size_ == 0) {
    LinkedListPlus::head_ = new_node;
    LinkedListPlus::size_++;
    LinkedListPlus::access_ = LinkedListPlus::head_;
    return;
  }
  
  if (LinkedListPlus::access_ == 0) {
    std::cout << "Error: There is no access pointer.";
    return;
  }

  if (LinkedListPlus::access_->next_ == 0) {
    LinkedListPlus::access_->next_ = new_node;
    LinkedListPlus::size_++;
  } else {
    LLNode* next_node = LinkedListPlus::access_->next_; // access_ = LinkedListPlus::access_
    LinkedListPlus::access_->next_ = new_node;
    new_node->next_ = next_node;
    LinkedListPlus::size_++;
  }
}