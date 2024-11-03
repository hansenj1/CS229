/* LinkedList class.  Built on nodes that store single char.
Singly-linked, so any action that doesn't operate on the head
needs to traverse, and thus has O(n) running time.
Code built by Brian Law, modified by Andrew Shallue
CS229, Data Structures, Fall 2024
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "LLNode.h"

// This is a class that wraps around/contains the Node class. By putting Nodes inside a LinkedList class like this,
// we can add additional functionality and safeguards against misuse.
class LinkedList {
  protected:
    // attributes are a pointer to the first node, and the size (i.e. count of nodes)
    LLNode* head_;
    int size_;
    // note that it is the nodes themselves that store data.  In this case a char

  public:
    ////////////// Part 1 implementation list //////////////////////
    LinkedList();
    LinkedList(char char_array[]);          
    LinkedList(const LinkedList& other);    
    ~LinkedList();
    int GetSize();
    std::string ToString();
    void Append(char new_value);
    void Insert(char value, int index);
    char Pop(int index);
    char Pop();

    /////////////// Part 2 implementation list ////////////////////
    char Get(int index);
    bool Contains(char contains_me);
    int Count(char count_me);
    void Set(char value, int index);
    void Remove(char remove_me); 
    void Extend(LinkedList& other);
    LinkedList Slice(int start, int end);
    void Clear();
    void Reverse();
};

// This function can be used for your own test code
void LinkedList_main();

#endif