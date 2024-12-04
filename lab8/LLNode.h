/* Node class for Linked Lists.  One char stored per node.  Single link.
Written by Brian law, modified by Andrew Shallue
For CS229, Data Structures, Fall 2024
*/

#ifndef LL_NODE_H_
#define LL_NODE_H_

#include <string>

class LLNode {
  public:
    // constructor and destructor.  Don't need to implement rule-of-three
    // because no internal element of the Node is allocated on the heap.
    LLNode(char data);
    ~LLNode();

    char data_;
    LLNode* next_;      // This is a pointer to the next node in the LL
};

void LLNode_main();

#endif