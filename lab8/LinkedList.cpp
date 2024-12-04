/* LinkedList class.  Built on nodes that store single char.
Singly-linked, so any action that doesn't operate on the head
needs to traverse, and thus has O(n) running time.
Code built by Brian Law, modified by Andrew Shallue
CS229, Data Structures, Fall 2024
*/

#include <iostream>
#include <cstring>

#include "LinkedList.h"

// Create an empty linked list with 0 elements.
LinkedList::LinkedList() {
  LinkedList::head_ = 0;
  LinkedList::size_ = 0;
}

// create a linked list filled with chars from a given cstring
// if cstring is empty, no action will be taken.
LinkedList::LinkedList(char char_array[]) {
  // if input cstring is empty, set both data members to 0
  if (strlen(char_array) == 0){
    LinkedList::head_ = 0;
    LinkedList::size_ = 0;
  }else{

    // Head gets treated differently.
    LinkedList::head_ = new LLNode(char_array[0]);
    
    // Everything else, you add like you normally would with a LL.
    LLNode* last_node = LinkedList::head_;
    for (int i = 1; i < strlen(char_array); i++) {
      last_node->next_ = new LLNode(char_array[i]);
      last_node = last_node->next_;
    }

    // Remember to set the size attribute properly.
    LinkedList::size_ = strlen(char_array);
  }
}

// Create a new LinkedList that's a copy of the other LinkedList.
LinkedList::LinkedList(const LinkedList& other) {
  // If the other linked list is empty, this is a jerk move. 
  if (other.size_ == 0) {
    LinkedList::head_ = 0;
    LinkedList::size_ = 0;
  }
  else {
    // Start the head node.
    LinkedList::head_ = new LLNode(other.head_->data_);

    // Double pointers that are synchronized to traverse both linked lists in parallel.
    // other_node points at the next node to be added. last_node points at last node in
    // the linked list being constructed.
    LLNode* last_node = LinkedList::head_;
    LLNode* other_node = other.head_->next_;

    // As long as there are nodes in the other to be copied...
    while (other_node != 0) {
      // Copy the node into our linked list.
      last_node->next_ = new LLNode(other_node->data_);
      // Move both pointers forward.
      last_node = last_node->next_;
      other_node = other_node->next_;
    }
  }

  // Remember to set the size attribute properly.
  LinkedList::size_ = other.size_;
}

// following rule of 3, assignment operator
LinkedList LinkedList::operator=(const LinkedList& other){
  // using the same code I used for DynamicArray
  // if the two objects are the same, nothing to do
  if(this == &other){
      return *this;
  
  }else if(other.size_ == 0){
      // if the size of other is 0, create empty linked list
      LinkedList::head_ = 0;
      LinkedList::size_ = 0;
      return *this;

  }else{
      // clear current contents
      delete[] LinkedList::head_;

      // Start the head node.
      LinkedList::head_ = new LLNode(other.head_->data_);

      // Double pointers that are synchronized to traverse both linked lists in parallel.
      // other_node points at the next node to be added. last_node points at last node in
      // the linked list being constructed.
      LLNode* last_node = LinkedList::head_;
      LLNode* other_node = other.head_->next_;

      // As long as there are nodes in the other to be copied...
      while (other_node != 0) {
        // Copy the node into our linked list.
        last_node->next_ = new LLNode(other_node->data_);
        // Move both pointers forward.
        last_node = last_node->next_;
        other_node = other_node->next_;
      }

      // Remember to set the size attribute properly.
      LinkedList::size_ = other.size_;
      // return the object we have modified
      return *this;
  }
}

// Destructor cleans up all Nodes in this linked list. Relies upon recursive destruction of
// subsequent LLNodes. If ANYTHING else points at these nodes, a memory-reading bug may be generated. 
// This includes if any nodes in this LL point back into the LL (creating a loop). The presumption of
// this LinkedList class design is that nodes belongs to this LinkedList and only this LinkedList, with
// no loops.
LinkedList::~LinkedList() {
  // If there is a head node, delete it. Recursive destructor in LLNode should take care
  // of remaining nodes in the LL
  if (LinkedList::head_ != 0) {
    delete LinkedList::head_;
  }
}

// Get the number of elements in this linked list.
int LinkedList::GetSize() {
  return LinkedList::size_;
}

// Return the contents of this linked list as a comma-separated list of values, bracketed.
std::string LinkedList::ToString() {
  // Starting opening bracket
  std::string return_this = "[";
  
  // Pointer for linked list iteration.
  LLNode* current_node = LinkedList::head_;
  
  // Loop over every node, adding its data to the string return value.
  while (current_node != 0) {
    return_this += current_node->data_;

    // Add a comma if there are more items to come.
    if (current_node->next_ != 0) {
      return_this += ", ";
    }
    current_node = current_node->next_;
  }

  // Return result.
  return return_this + "]";
}

// Add a new node with the given value to the end of the LL
void LinkedList::Append(char new_value) {
  // If the LL is empty, add the first node to it
  if (LinkedList::head_ == 0) {
    LinkedList::head_ = new LLNode(new_value);
  }else {
    // Otherwise, LL is not empty, so traverse to the last node, then add the new node to the end of the LL
    LLNode* current_node = LinkedList::head_;
    // Moves the current_node pointer to the last node in the LL, NOT the NULL at the end
    while (current_node->next_ != 0) {
      current_node = current_node->next_;
    }
    
    // Create a new node for the new value to add to the end of the list
    LLNode* new_node = new LLNode(new_value);
    current_node->next_ = new_node;
  }
  // either way, add one to size
  LinkedList::size_++;
}

// Insert a new node with the specified value at the given index. 
// All nodes after the given index are pushed "back" 1 index.
// If index out of bounds, print an error message and do nothing
void LinkedList::Insert(char value, int index) {
  // Index check to prevent bugs.
  // Note that I want to allow for the case when index = 0 and size = 0
  if (index < 0 || (index > 0 && index >= LinkedList::size_)) {
    std::cout << "Error in LinkdedList::Insert, index " << index << " out of bounds\n";
    return;
    
    // In a later version of this class I'd like to talk about this as an alternate plan:
    //throw std::runtime_error("Invalid index " + std::to_string(index) + " for Insert(...)");
  }
  
  // create a new node with the new character
  LLNode* new_node = new LLNode(value);

  // When inserting at the head (index == 0) requires special handling
  if (index == 0) {
    new_node->next_ = LinkedList::head_;
    LinkedList::head_ = new_node;
  }
  else {
    LLNode* previous_node = LinkedList::head_;
    int counter = 0;

    // Traverse the LL until we reach the end or until index - 1 is reached. 
    // We use index - 1 here because we want the node preceding the index we want to insert at!
    while (previous_node->next_ != 0 && counter < index - 1) {
      previous_node = previous_node->next_;
      counter++;
    }
    
    // Save a pointer to the next node, so we can "reattach it" after we add the new node
    LLNode* next_node = previous_node->next_;

    // Stick the new node in between the previous and the next node
    previous_node->next_ = new_node;
    new_node->next_ = next_node;

    // relying here on next_node being garbage collected
  }
  // either way, add one to size
  LinkedList::size_++;  
}

// Remove and return the last element in this linked list.
// Note that this Pop() is linear time.
char LinkedList::Pop() {
  // Rather than repeating code from the next function, let's just use it.
  return LinkedList::Pop(LinkedList::GetSize() - 1);
}

// Remove and return the element at the specified index in this linked list.
// Watch out for special cases.  If out of bounds, return '0' and print error.
char LinkedList::Pop(int index) {
  // Index check to prevent bugs.
  if (index < 0 || index >= LinkedList::size_) {
    std::cout << "Error in LinkedList::Pop, index " << index << " out of bounds\n";
    return '0';

    //throw std::runtime_error("Invalid index " + std::to_string(index) + " for Pop(...)");
  }

  // Temporary placeholder for the return value.
  char return_value;

  // Special case if popping at at head.
  if (index == 0) {
    // Save the data to be returned before we delete the node!
    return_value = LinkedList::head_->data_;
    // Create a temporary placeholder pointer to the new head, before we delete the original head.
    LLNode* new_head = LinkedList::head_->next_;
    // Disconnect the head node before deleting it.
    LinkedList::head_ = 0;
     // Delete the original head off the heap.
    delete LinkedList::head_;
    // Reconnect to the new head.
    LinkedList::head_ = new_head;
  }
  else {
    // We will try to stop the pointer 1 node BEFORE the node to be popped.
    LLNode* previous_node = LinkedList::head_;
    int counter = 0;

    // Traverse the LL until we reach the end or until index - 1 is reached. 
    // We use index - 1 here because we want the node preceding the index we want to insert at!
    while (previous_node->next_ != 0 && counter < index - 1) {
      previous_node = previous_node->next_;
      counter++;
    }

    // Save a pointer to the NEXT NEXT node, so we can reattach it later
    LLNode* next_node = previous_node->next_->next_;
    // Save the return value from the node we are popping
    return_value = previous_node->next_->data_;

    // Disconnect the node before deleting it.
    previous_node->next_->next_ = 0;
    // Delete the node we are popping
    delete previous_node->next_;
    // Reattach the next node to the previous node
    previous_node->next_ = next_node;
  }

  // Update size attribute.
  LinkedList::size_--;  
  return return_value;
}

///////////////////////////////////////////////////////////
////////////////////////// Part 2 ////////////////////////
//////////////////////////////////////////////////////////

// Return the data value in the node located at the specified index in the LL
// If out of bounds, print an error message and return char '0'
char LinkedList::Get(int index) {
  // Index check to prevent bugs.
  if (index < 0 || index >= LinkedList::size_) {
    std::cout << "Error in LinkedList::Get, " << index << " is out of bounds\n";
    return '0';

    // the solution on the next line due to Brian Law.  I should investigate at some point.
    //throw std::runtime_error("Invalid index " + std::to_string(index) + " for Get(...)");
  }
  
  // Start the pointer at the head
  LLNode* current_node = LinkedList::head_;
  // Index counter
  int counter = 0;

  // Traverse the LL until we reach the end or until the index is reached
  while (current_node->next_ != 0 && counter < index) {
    current_node = current_node->next_;
    ++counter;
  }

  // Return the data at the node we reached 
  return current_node->data_;
}

// Check if this linked list contains the specified character.
bool LinkedList::Contains(char contains_me) {
  // Pointer for linked list iteration.
  LLNode* current_node = LinkedList::head_;

  // Loop over every node in the linked list.
  while (current_node != 0) {
    // If specified char found return true immediately.
    if (current_node->data_ == contains_me) {
      return true;
    }
    current_node = current_node->next_;
  }

  // If end of linked list reached, no value found.
  return false;
}

// Count the number of times the specified char occurs as an element in this linked list.
int LinkedList::Count(char count_me) {
  LLNode* current_node = LinkedList::head_;
  int counter = 0;

  // loop until current_node is 0, which means the end of the list was reached
  while (current_node != 0) {
    if (current_node->data_ == count_me) {
      counter++;
    }
    // whether char found or not, push current_node pointer forward
    current_node = current_node->next_;
  }
  return counter;
}

// Set the element at the specified index to the given value, overwriting the previous element.
// If index out of bounds, print an error message and do nothing.
void LinkedList::Set(char value, int index) {
  // Index check to prevent bugs.
  if (index < 0 || index >= LinkedList::size_) {
      std::cout << "Error in LinkedList::Set, index " << index << " out of bounds\n";
      return;
  }
  
  LLNode* current_node = LinkedList::head_;
  int counter = 0;

  // Traverse the LL until we reach the end or until the index is reached
  // typical case is to have the loop stop when counter == index
  while (current_node->next_ != 0 && counter < index) {
    current_node = current_node->next_;
    counter++;
  }
  // wherever loop stops (hopefully at index), set current data to value
  current_node->data_ = value;
}

// Remove the first node with the specified value remove_me from this linked list.
void LinkedList::Remove(char remove_me) {

  // Special case if removing from head.
  if (LinkedList::head_->data_ == remove_me) {
    // Create a temporary placeholder pointer to the new head, before we delete the original head.
    LLNode* new_head = LinkedList::head_->next_;
    // Disconnect the head node before deleting it.
    LinkedList::head_ = 0;
     // Delete the original head off the heap.
    delete LinkedList::head_;
    // Reconnect to the new head.
    LinkedList::head_ = new_head;
  }
  else {
    // We will try to stop the pointer 1 node BEFORE the node to be removed.
    LLNode* previous_node = LinkedList::head_;
    int counter = 0;

    // Traverse the LL until we reach the end or until the next node has the value we want to 
    // remove.
    while (previous_node->next_ != 0 && previous_node->next_->data_ != remove_me) {
      previous_node = previous_node->next_;
      counter++;
    }

    // If we've reached the end of the linked list, then we haven't found the value, which means
    // the value doesn't exist in the linked list to be removed! Throw an runtime error!
    if (previous_node->next_ == 0) {
      std::cout << "Error in Remove, " << remove_me << " not found\n";
      return;
    }

    // Save a pointer to the NEXT NEXT node, so we can reattach it later
    LLNode* next_node = previous_node->next_->next_;

    // Disconnect the node before deleting it.
    previous_node->next_->next_ = 0;
    // Delete the node we are popping
    delete previous_node->next_;
    // Reattach the next node to the previous node
    previous_node->next_ = next_node;
  }

  // Update size attribute.
  LinkedList::size_--;
}

// Create and return a slice of this linked list, beginning at index start and
// finishing at index end-1. New linked list is unrelated to this linked list.
LinkedList LinkedList::Slice(int start, int end) {
  // Index check to prevent bugs.
  if (start < 0 || start > end || end < start || end >= LinkedList::size_) {
    std::cout << "Error in Slice, invalid indices\n";
    return LinkedList();
  }
  
  LinkedList new_ll = LinkedList();

  // Move current_node pointer into position, at first node to be sliced.
  LLNode* current_node = LinkedList::head_;
  for (int i=0; i<start; i++) {
    current_node = current_node->next_;
  }

  // If start == end, there is nothing to do
  if (start < end) {
    // The node at start should become the head of our new slice.
    new_ll.head_ = new LLNode(current_node->data_);
  }

  // Pointer to iterate over new linked list.
  LLNode* new_node = new_ll.head_;

  // Loop end - start - 1 times, because 1 node was already attached as the head.
  for (int i = start + 1; i < end; i++) {
    current_node = current_node->next_;
    new_node->next_ = new LLNode(current_node->data_);
    new_node = new_node->next_;
  }

  // Update size attribute.
  new_ll.size_ = end - start;
  return new_ll;
}

// Add each node in the other linked list to this linked list, efficiently.
void LinkedList::Extend(LinkedList& other) {

  // Start a pointer to the other linked list's head.
  LLNode* other_node = other.head_;

  // If we have no nodes but other has nodes, copy their head to our head.
  if (LinkedList::head_ == 0 && other_node != 0) {
    LinkedList::head_ = new LLNode(other_node->data_);
    // Move other_node to point to next node.
    other_node = other_node->next_;
  }

  // other_node should point at next node to be added to this linked list.
  if (other_node != 0) {
    // Create and move last_node pointer to point to last node in this linked list.
    LLNode* last_node = LinkedList::head_;
    while (last_node->next_ != 0) {
      last_node = last_node->next_;
    }

    // As long as there are other nodes to be added...
    while (other_node != 0) {
      // Create a new node at the end of this linked list with the copied data
      last_node->next_ = new LLNode(other_node->data_);

      // Move pointers forward for next iteration
      last_node = last_node->next_;
      other_node = other_node->next_;
    }
  }

  // Update size attribute.
  LinkedList::size_ += other.size_;
}

// Empty out this LinkedList.
void LinkedList::Clear() {
  LinkedList::size_ = 0;
  delete LinkedList::head_;
}

// Reverse this LinkedList in place.
void LinkedList::Reverse() {
  // 3 pointers needed. One for the next_node, so traversal can continue. One for the current_node
  // being reversed. One for the previous_node so current_node can point back to it.
  LLNode* previous_node = 0;
  LLNode* current_node = LinkedList::head_;
  LLNode* next_node = 0;

  // While we still have a node to reverse...
  while (current_node != 0) {
    // Save the next node so the loop can move forward later.
    next_node = current_node->next_;
    // Point the current node back to the last node.
    current_node->next_ = previous_node;

    // Advance two pointers for next iteration.
    previous_node = current_node;
    current_node = next_node;
  }

  // New head is old tail!
  LinkedList::head_ = previous_node;
}

void LinkedList_main() {
  std::cout << "This is LinkedList_main()." << std::endl << std::endl;

  // students can use this for testing  
}