/* Tree class where there could be multiple children of each Node.
We will use a vector to store the children.

Andrew Shallue, CS229, Fall 2024
*/
// .cpp file for Tree class 
// Provided by Professor Shallue, any modifications by: Jules Weick and Jack Hansen

#include "Tree.h"
#include <iostream>

// function to create a leaf node.  Returns pointer to it.
TreeNode* tree_leaf(int v){
  TreeNode* n = new TreeNode;
  n->value = v;
  n->subtrees = vector<TreeNode*>();

  return(n);
}

// an empty tree
Tree::Tree(){
  root_ = NULL;
}

// destructor calls recursive function destroy
Tree::~Tree(){
  destroy(root_);
}


// helper function for destructor
// does a depth-first search
void Tree::destroy(TreeNode* current_node){
  // check if current is NULL.  If so, nothing to do
  if(current_node != NULL){
    // Apply recursive call to all subtrees
    for(int i = 0; i < current_node->subtrees.size(); ++i){
        destroy(current_node->subtrees.at(i));
    }
    
    // with those taken care of, we can delete the current node
    delete current_node;
  }
}

// return true if the tree is empty, i.e. root NULL
bool Tree::isEmpty(){
  return root_ == NULL;
}

// print values in a tree-like structure.  Does v - left - right
void Tree::print(){
  print_helper(root_, "  ");
  std::cout << "\n";
}

// print helper that tries to represent the tree structure
void Tree::print_helper(TreeNode* current_node, std::string spacing){
    // base case: if tree empty, print an E
    if(current_node == 0){
        std::cout << "E";
    }else{
        std::cout << current_node->value << "\n";
        for(int i = 0; i < current_node->subtrees.size(); ++i){
            std::cout << spacing << "|";
            print_helper(current_node->subtrees.at(i), spacing + "   ");
        }
    }
}

///////////////////// End of Andrew's Code /////////////////////////

// Helper to insert a node into the tree. Finds the first available space to insert
// into the tree and does so.
// Parameters:
// 1. v (int): The value of the node to be inserted into the tree.
// 2. branching_factor (int): The maximum amount of children a node is to have.
// 3. current_node (TreeNode*): The node to start searching for a space to insert from.
// Returns:
// Nothing. Rather, puts the new node into the data structure.
void Tree::insert_helper(int v, int branching_factor, TreeNode* current_node) {
  std::queue<TreeNode*> node_queue;
  node_queue.push(current_node);

  while (current_node->subtrees.size() >= branching_factor) {
    current_node = node_queue.front();
    node_queue.pop();
    for (int i = 0; i < current_node->subtrees.size(); i++) {
      node_queue.push(current_node->subtrees.at(i));
    }
  } 
  TreeNode* new_leaf = tree_leaf(v);
  current_node->subtrees.push_back(new_leaf);  
}

// Inserts a node into a tree by checking if the root node exists and if so,
// passing along the variables to the helper function to insert the node where 
// it belongs in the tree.
// Parameters:
// 1. v (int): The value of the node to be inserted.
// 2. branching_factor (int): The maximum amount of children a node should have.
// Returns:
// Nothing. Rather, it puts the new node into the data structure.
void Tree::insert(int v, int branching_factor) {
  if (Tree::root_ == NULL) {
    TreeNode* leaf = tree_leaf(v);
    Tree::root_ = leaf;
  } else {
    Tree::insert_helper(v, branching_factor, Tree::root_);
  }
}

// Checks the tree for a value and returns true if it finds it and 
// false if it does not find the value.
// Parameters:
// 1. check_me (int): The value to search the tree for.
// Returns:
// A boolean value: true if found, false if not found.
bool Tree::contains(int check_me) {
  return contains_helper(check_me, root_);
}

// Helper method for the contains method that does the actual
// work of searching the tree for the value and returning whether
// or not it finds the value/
// Parameters:
// 1. check_me (int): The value being searched for.
// 2. current_node (TreeNode*): The node to check the children for in the
//                              current call of the method.
// Returns:
// A boolean value: true if the value is found, false if it is not.
bool Tree::contains_helper(int check_me, TreeNode* current_node) {
  if (current_node == nullptr) {
    return false; // Empty tree, value not found
  }

  std::queue<TreeNode*> node_queue;
  node_queue.push(current_node);

  while (!node_queue.empty()) {
    TreeNode* node = node_queue.front();
    node_queue.pop();

    if (node->value == check_me) {
      return true; // Value found
    }

    for (size_t i = 0; i < node->subtrees.size(); ++i) {
      node_queue.push(node->subtrees[i]);
    }
  }

  return false; // Value not found after BFS traversal
}

// Takes a vector of ints and returns a vector containing the 
// ints that are found in the tree.
// Parameters:
// 1. nums (vector<int>&): The vector of ints to check the tree for.
// Returns:
// A vector containing all the ints from nums that are in the tree.
vector<int> Tree::subset_contains(vector<int>& nums) {
  vector<int> result;

  // Iterate through the input list and check containment
  for (int num : nums) {
    if (contains(num)) {
      result.push_back(num);
    }
  }

  return result;
}



