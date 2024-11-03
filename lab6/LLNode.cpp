/* Node class for Linked Lists.  One char stored per node.  Single link.
Written by Brian law, modified by Andrew Shallue
For CS229, Data Structures, Fall 2024
*/

#include <iostream>
#include <string>

#include "LLNode.h"

// Create a new linked list node with the given data and no next node.
LLNode::LLNode(char data) {
  LLNode::data_ = data;
  LLNode::next_ = 0;
}

// (Recursively) destroy this LLNode and all following it.
LLNode::~LLNode() {
  // When each LLNode is deallocated, it should deallocate following it.
  //std::cout << "Deallocating " << LLNode::value_ << std::endl;
  
  // IF there's a next node, call delete on it.
  if (LLNode::next_ != 0) {
    delete LLNode::next_;
  }
}


void LLNode_main() {
  // manually create and link nodes that spell "Andrew"
  // While creating, we also print each letter to check.

  LLNode* head = new LLNode('A');
  std::cout << head->data_;
  //std::cout << (*head).data_ << std::endl;
  
  LLNode* node2 = new LLNode('n');
  head->next_ = node2;

  std::cout << head->next_->data_;

  head->next_->next_ = new LLNode('d');
  std::cout << head->next_->next_->data_;

  head->next_->next_->next_ = new LLNode('r');
  std::cout << head->next_->next_->next_->data_;

  head->next_->next_->next_->next_ = new LLNode('e');
  std::cout << head->next_->next_->next_->next_->data_;

  head->next_->next_->next_->next_->next_ = new LLNode('w');
  std::cout << head->next_->next_->next_->next_->next_->data_;

  // create a current_node pointer.  Currently pointing at head of the list
  LLNode* current_node = head;
  
  /* Example of traversal.  While current node not null, 
  print data and follow the arrow to move current_node to the next.
  Sometimes you want to traverse with a "next" node rather than current.
  */
  std::cout << std::endl;
  while (current_node != 0) {
    std::cout << current_node->data_;
    current_node = current_node->next_;
  }
  std::cout << std::endl;

  
}
