// Linked List file for Part 1 and 2 of Lab6
// Authors: Jules Weick and Jack Hansen

#include "LinkedList.h"
#include <string>
#include <cstring>
#include <iostream>

// Default constructor for the LinkedList class when no parameters are passed.
// Parameters:
// None.
// Instantiates:
// An instance of the class with the head_ set to 0 and size_ to 0.
LinkedList::LinkedList() {
  LinkedList::head_ = 0;
  LinkedList::size_ = 0;
}

// Non-default constructor for the LinkedList class when a char array is passed in.
// Parameters:
// 1. char_array[] (char array): A cstring containing chars to instantiate the linked list with.
// Instantiates:
// An instance of the LinkedList class with nodes for each char of char_array.
LinkedList::LinkedList(char char_array[]) {
  if (strlen(char_array) == 0) {
    LinkedList();
  } else {
  LinkedList::head_ = new LLNode(char_array[0]);
  LLNode* current_node = LinkedList::head_;

  for (int i = 1; i < strlen(char_array); i++) {
    LLNode* new_node = new LLNode(char_array[i]);
    current_node->next_ = new_node;
    current_node = new_node;
  }
  LinkedList::size_ = strlen(char_array);
 }
}

// Copy constructor for the LinkedList class. Takes another
// instance of the LinkedList class and copies it to the instance
// that called the copy constructor.
// Parameters:
// other (const LinkedList&): Another instance of the LinkedList class
// that is passed-by-reference and set to const. This instance is the 
// one that will have its attributes copied.
// Instantiates:
// An instance of the LinkedList class that has the same attributes as other.
LinkedList::LinkedList(const LinkedList& other) {
  if (other.size_ == 0) {
    LinkedList();
  } else {
  char other_head_data = other.head_->data_;
  LinkedList::head_ = new LLNode(other_head_data);
  LLNode* current_node = LinkedList::head_;
  LLNode* other_current_node = other.head_;

  for (int i = 1; i < other.size_; i++) {
    char other_next_data = other_current_node->next_->data_;
    LLNode* new_node = new LLNode(other_next_data);
    current_node->next_ = new_node;
    current_node = new_node;
    other_current_node = other_current_node->next_;
  }
  LinkedList::size_ = other.size_;
 }
}

// Destructor for the LinkedList class.
// Parameters:
// None.
// Deconstructs:
// The head pointer stored in the instance of the class.
LinkedList::~LinkedList() {
  delete LinkedList::head_;
  LinkedList::head_ = 0;
}

// Gets the size stored in this instance of the class and returns it.
// Parameters:
// None.
// Returns:
// The size of the linked list as an integer.
int LinkedList::GetSize() {
  return LinkedList::size_;
}

// Loops through the linked list, adding each node to a string and returns said string.
// Parameters:
// None.
// Returns:
// A string containing the data from each node from the linked list.
std::string LinkedList::ToString() {
  std::string result ("");
  if (LinkedList::size_ == 0 || LinkedList::head_ == 0) {
    return result;
  }

  LLNode* current_node = LinkedList::head_;

  while (current_node != 0) {
    result += current_node->data_;
    current_node = current_node->next_;
  }

  return result;
}

// Appends a new node to the linked list.
// Parameters:
// 1. new_value(char): The new character to make a node from and append
//    to the linked list.
// Returns:
// Nothing. Rather, adds a new node to the end of the linked list.
void LinkedList::Append(char new_value) {
  LLNode* current_node = LinkedList::head_;
  LLNode* new_node = new LLNode(new_value);

  // Edge case for if the linked list is empty.
  if (LinkedList::size_ == 0) {
    LinkedList::head_ = new_node;
    LinkedList::size_++;
    return;
  }

  // Make sure that there is another node to go to, if not, we are
  // at the end of the linked list.
    while (current_node->next_ != 0) {
      current_node = current_node->next_;
    }

  std::cout << current_node->data_ << "\n";

  current_node->next_ = new_node;
  // Update size in accordance with adding a node.
  LinkedList::size_++;
}

// Inserts a node at the given index of the linked list. 
// Parameters:
// 1. value (char): The value from which to make a new node to insert.
// 2. index (int): The index to insert the new_node at.
// Returns:
// Nothing. Rather, adds a new_node with value at index in the linked list.
void LinkedList::Insert(char value, int index) {
  LLNode* current_node = LinkedList::head_;
  LLNode* new_node = new LLNode(value);

  // If index is greater than the size of the linked list, set index to size
  if (index > LinkedList::size_ || index < 0) {
    std::cout << "Error: Index is out of bounds.\n";
    return;
  }

  // Edge case of inserting at the start of a non-empty linked list
  if (index == 0 && LinkedList::size_ > 0) {
    new_node->next_ = LinkedList::head_;
    LinkedList::head_ = new_node;
  }

  // Edge case of inserting into an empty linked list
  if (LinkedList::size_ == 0) {
    LinkedList::head_ = new_node;
  }

  // Do not want to enter this loop if the linked list was previously empty
  // or if the index to insert at was 0.
  if (LinkedList::size_ > 0 && index > 0) {
    int counter = 0;
    // Handles inserting at the end of a linked list or in the middle.
    while (current_node->next_ != 0 && counter < index) {
      current_node = current_node->next_;
      counter++;
    }
  }

  // Do not want to set the next node if inserting into an empty linked list
  // or if the index to insert was 0.
  if (LinkedList::size_ > 0 && index != 0) {
    LLNode* next_node = current_node->next_;
    new_node->next_ = next_node;
    current_node->next_ = new_node;
  }

  // Update the size in accordance with indexing.
  LinkedList::size_++;
}

// Pops the node at index and returns its value.
// Parameters:
// 1. index (int): The index of the node to pop.
// Returns:
// The character that the poppped node stored.
char LinkedList::Pop(int index) {
  LLNode* previous_node = nullptr;
  LLNode* current_node = LinkedList::head_;
  char result = ' ';

  // if empty, return the space char currently in result, most importantly
  // this stops from any further functionality of Pop(int) being invoked
  if (LinkedList::size_ == 0) {
    return result;
  }

  // Set index to size if it is larger than size
  if (index > LinkedList::size_ || index < 0) {
    std::cout << "Error: Index is out of bounds.\n";
    return result;
  }

  // Procedure for popping the head node
  if (index == 0) {
    result = current_node->data_;
    LinkedList::head_ = LinkedList::head_->next_;
    current_node->next_ = 0;
    delete current_node;
    current_node = 0;
    LinkedList::size_--;
    return result;
  }

  // Normal traversing procedure 
  int counter = 0;
  while (current_node->next_ != 0 && counter < index) {
    previous_node = current_node;
    current_node = current_node->next_;
    counter++;
  }
  
  if (index < LinkedList::size_ && index != 0) {
    result = current_node->data_;
    previous_node->next_ = current_node->next_;
    delete current_node;
    current_node = 0;
    LinkedList::size_--;
    return result;
  } else {
    result = current_node->data_;
    delete current_node;
    current_node = 0;
    LinkedList::size_--;
    return result;
  }
}

// Pops the last node of the linked list and returns its value.
// Parameters:
// None.
// Returns:
// The character that the poppped node stored.
char LinkedList::Pop() {
  LLNode* previous_node = 0;
  LLNode* current_node = LinkedList::head_;
  char result = ' ';

  // if empty, return the space char currently in result, most importantly
  // this stops from any further functionality of Pop(int) being invoked
  if (LinkedList::size_ == 0) {
    std::cout << "Error: There is nothing to pop.";
    return result;
  }

  if (LinkedList::size_ == 1) {
    result = current_node->data_;
    delete current_node;
    current_node = 0;
    LinkedList::size_--;
    return result;
  }


  // Normal traversing procedure 
  while (current_node->next_ != 0) {
    previous_node = current_node;
    current_node = current_node->next_;
  }
  
  result = current_node->data_;
  previous_node->next_ = 0;
  delete current_node;
  current_node = 0;
  LinkedList::size_--;
  return result;
}

//start of part two

char LinkedList::Get(int index){
  //Returns the data value at given index
  //Parameters:
  //int index: the index
  //Returns:
  //the character at the given index
  if (index < 0 || index >= LinkedList::size_) {
    std::cout << "Error: Index is out of bounds.\n";
    return ' '; // Return a space char for invalid index.
  }

  LLNode* current_node = LinkedList::head_;
  int counter = 0;

  // Traverse to the node at the specified index.
  while (counter < index) {
    current_node = current_node->next_;
    counter++;
  }

  return current_node->data_;
}
bool LinkedList::Contains(char contains_me){
  //Checks whether a value exists in the LL or not
  //Parameters:
  //char contains_me: the character to be searched for
  //Returns:
  //Either true or false
  LLNode* current_node = LinkedList::head_;
  // Traverse through the linked list.
  while (current_node != 0) {
    if (current_node->data_ == contains_me) {
      return true; // Return true if the character is found.
    }
    current_node = current_node->next_;
  }

  return false;
}
int LinkedList::Count(char count_me){
    //Returns the number of instances of count_me
    //Parameters: 
    //char count_me: the character to be counted
    //Returns:
    //the number of times count_me occurs
    int count = 0;
    LLNode* current_node = LinkedList::head_;

    // Traverse through the linked list to count occurrences.
    while (current_node != 0) {
        if (current_node->data_ == count_me) {
            count++; // Increment count if the character matches.
        }
        current_node = current_node->next_; // Move to the next node.
    }

    return count;

}
void LinkedList::Set(char value, int index){
  //Changes the value at a given index
  //Parameters:
  //char value: the value to replace the existing value
  //int index: the place where it is to be replaced
  //Returns:
  //Nothing.
  if (index < 0 || index >= LinkedList::size_) {
    std::cout << "Error: Index is out of bounds.\n";
    return; // Return for invalid index.
  }

  LLNode* current_node = LinkedList::head_;
  int counter = 0;

  // Traverse to the node at the specified index.
  while (counter < index) {
    current_node = current_node->next_;
    counter++;
  }

  current_node->data_ = value;

}
void LinkedList::Remove(char remove_me){
  //Removes the first instance of the given char
  //Parameters:
  //char remove_me: the character to be removed
  //Returns:
  //Nothing.
  if (LinkedList::size_ == 0) {
    std::cout << "The linked list is empty, cannot remove\n";
    return; // No removal is done on an empty list.
  }

  LLNode* current_node = LinkedList::head_;
  LLNode* previous_node = 0;

  //If the head contains the value to remove.
  if (current_node->data_ == remove_me) {
    LinkedList::head_ = current_node->next_; // Update head to the next node.
    delete current_node;
    LinkedList::size_--;
    return;
  }

  //Traverse through the linked list to find the node to remove.
  while (current_node != 0 && current_node->data_ != remove_me) {
    previous_node = current_node;
    current_node = current_node->next_;
  }

  // If the character is found, remove the node.
  if (current_node != 0) {
    previous_node->next_ = current_node->next_; // Bypass the node to remove.
    delete current_node;
    LinkedList::size_--;
  } else {
    std::cout << "Character not found in the linked list.\n";
  }
} 
void LinkedList::Extend(LinkedList& other){
  //Adds the elements from another LL onto the existing LL
  //Parameters:
  //LinkedList& other: another LinkedList object
  //Returns:
  //Nothing.
  if (other.size_ == 0) {
    return;
  }

  // If the current list is empty, simply copy the other list into this list.
  if (LinkedList::size_ == 0) {
    // Call the copy constructor to create a deep copy of the other list.
    *this = LinkedList(other); 
    return;
  }

  // Traverse to the last node of the current list.
  LLNode* current_node = LinkedList::head_;
  while (current_node->next_ != 0) {
    current_node = current_node->next_;
  }

  // Now current_node is the last node of the current list.

  // Traverse through the other list and append each node to the current list.
  LLNode* other_node = other.head_;
  while (other_node != 0) {
    // Create a new node for each element in the other list and append it to this list.
    LLNode* new_node = new LLNode(other_node->data_);
    current_node->next_ = new_node;
    current_node = new_node;

    // Move to the next node in the other list.
    other_node = other_node->next_;
  }

  // Update the size of the current list to reflect the added nodes.
  LinkedList::size_ += other.size_;
}
LinkedList LinkedList::Slice(int start, int end){
  //Returns a portion of the LL object
  //Parameters:
  //start, end: both indexes on where to begin and end the slice
  //Returns:
  //A new LL object.
  if (start < 0 || end > LinkedList::size_ || start >= end) {
    std::cout << "Invalid indices.\n";
    return LinkedList(); // Return an empty LinkedList in case of invalid input.
  }

  // Create a new LinkedList to hold the slice.
  LinkedList new_list;
  LLNode* current_node = LinkedList::head_;
  LLNode* new_list_node = 0; // Pointer for adding nodes to the new list.

  // Traverse to the starting node of the slice.
  for (int i = 0; i < start; i++) {
    current_node = current_node->next_;
  }

  // Traverse from the start index to the end index, copying nodes to the new list.
  for (int i = start; i < end; i++) {
    LLNode* new_node = new LLNode(current_node->data_); // Create a new node with the current data.

    if (new_list_node == nullptr) {
      // For the first node, set the head of the new list.
      new_list.head_ = new_node;
      new_list_node = new_node; // Update the pointer to the new list's node.
    } else {
      // Link the new node to the previous one in the new list.
      new_list_node->next_ = new_node;
      new_list_node = new_node; // Move the pointer forward in the new list.
    }

    // Move to the next node in the original list.
    current_node = current_node->next_;
  }

  // Update the size of the new list.
  new_list.size_ = end - start;

  return new_list; 
}
void LinkedList::Clear(){
  //Clears the data in the LL object
  //Parameters:
  //None
  //Returns:
  //Nothing.
  delete LinkedList::head_;
  LinkedList::head_ = 0;
}
void LinkedList::Reverse(){
  //Reverses the arrows in the LL object
  //Parameters:
  //None
  //Returns:
  //Nothing.
  if (LinkedList::size_ <= 1) {
    return;
  }

  //Initialize three pointers: previous, current, and next.
  LLNode* previous = 0;
  LLNode* current = LinkedList::head_;
  LLNode* next = 0;

  //Traverse the list and reverse the direction of the next_ pointers.
  while (current != 0) {
    //Store the next node before changing the next_ pointer.
    next = current->next_;

    //Reverse the current node's pointer to point to the previous node.
    current->next_ = previous;

    //Move the previous and current pointers one step forward.
    previous = current;
    current = next;
  }
  LinkedList::head_ = previous;
}


void LinkedList_main() {
  // Test of default constructor.
  LinkedList LL0 = LinkedList();
  std::cout << "Linked List Zero: " << LL0.ToString() << " & size: " << LL0.GetSize() << "\n";
  
  // Test of non-default constructor.
  char char1[] = "IHateLinkedLists";
  LinkedList LL1 = LinkedList(char1);
  std::cout << "Linked List One: " << LL1.ToString() << " & size of LL1: " << LL1.GetSize() << "\n";

  // Test of copy constructor.
  LinkedList LL2 = LinkedList(LL1);
  std::cout << "Linked List Two: " << LL2.ToString() << " & size of LL2: " << LL2.GetSize() << "\n";

  // Test of append with empty edge case
  LL0.Append('H');
  std::cout << "Linked List Zero Append: " << LL0.ToString() << " & size of LL0: " << LL0.GetSize() << "\n";
  // Test of append under normal circumstances.
  LL1.Append('!');
  std::cout << "Linked List One Append: " << LL1.ToString() << " & size of LL1: " << LL1.GetSize() << "\n";

  LinkedList LL3 = LinkedList();
  LinkedList LL4 = LinkedList();
  //Test of insert with empty edge case at index 0.
  LL3.Insert('H', 0);
  std::cout << "Linked List Three Insert: " << LL3.ToString() << " & size of LL3: " << LL3.GetSize() << "\n";
  // Test of insert with empty edge case at index larger than 0. Should see an error.
  LL4.Insert('Q', 5);
  std::cout << "Linked List Four Insert: " << LL4.ToString() << " & size of LL4: " << LL4.GetSize() << "\n";
  // Test of insert on a non-empty linked list at index 0.
  LL2.Insert('P', 0);
  std::cout << "Linked List Two Insert at 0: " << LL2.ToString() << " & size of LL2: " << LL2.GetSize() << "\n";
  // Test of insert at the end of a linked list.
  LL2.Insert('Y', LL2.GetSize());
  std::cout << "Linked List Two Insert at end: " << LL2.ToString() << " & size of LL2: " << LL2.GetSize() << "\n";
  // Test of insert in the middle of a linked list.
  // expected: IHateJLinkedLists!
  LL1.Insert('J', 5);
  std::cout << "Linked List One Insert: " << LL1.ToString() << " & size of LL2: " << LL1.GetSize() << "\n";

  LinkedList LL5 = LinkedList();
  // Test of Pop (at) on an empty linked list.
  std::cout << "LL5 Pop at 5 Result: " << LL5.Pop(5) << "\n";
  std::cout << "Linked List Five Pop: " << LL5.ToString() << " & size of LL5: " << LL5.GetSize() << "\n";
  // Test of Pop (at) at the end of a linked list.
  std::cout << "LL2 Pop at End/17 Result: " << LL2.Pop(17) << "\n";
  std::cout << "Linked List Two Pop at end: " << LL2.ToString() << " & size of LL2: " << LL2.GetSize() << "\n";
  // Test of Pop (at) at index zero of a non-empty linked list.
  std::cout << "LL2 Pop at 0 Result: " << LL2.Pop(0) << "\n";
  std::cout << "Linked List Two Pop at 0: " << LL2.ToString() << " & size of LL2: " << LL2.GetSize() << "\n";
  // Test of Pop with an index larger than the size of the linked list. Should see an error.
  std::cout << "LL1 Pop at Index Larger than Size Result: " << LL1.Pop(20) << "\n";
  std::cout << "Linked List 1 Pop at Index Larger than Size: " << LL1.ToString() << " & size of LL1: " << 
  LL1.GetSize() << "\n";

  // Test of pop() on a linked list with 1 element.
  LL5.Append('G');
  std::cout << "LL5 Pop Result: " << LL5.Pop() << "\n";
  std::cout << "Linked List 5 after Pop of Only Element: " << LL5.ToString() << " & size of LL5: " <<
  LL5.GetSize() << "\n";
  // Test of pop() on an empty list.
  std::cout << "LL5 Empty Pop Result: " << LL5.Pop() << "\n";
  std::cout << "Linked List 5 after Pop when Empty: " << LL5.ToString() << " & size of LL5: " <<
  LL5.GetSize() << "\n";
  // Test of normal circumstance of pop().
  std::cout << "LL1 Pop Result: " << LL1.Pop() << "\n";
  std::cout << "Linked List 1 after Pop: " << LL1.ToString() << " & size of LL1: " << 
  LL1.GetSize() << "\n";
}