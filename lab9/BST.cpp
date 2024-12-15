// .cpp file for BST class 
// Provided by Professor Shallue, any modifications by: Jules Weick and Jack Hansen
#include "BST.h"
#include <iostream>

// function to create a leaf node.  Returns pointer to it.
Node* leaf(int v){
  Node* n = new Node;
  n->value = v;
  n->leftsubtree = NULL;
  n->rightsubtree = NULL;

  return(n);
}

// an empty tree
BST::BST(){
  root_ = NULL;
}

// destructor calls recursive function destroy
BST::~BST(){
  destroy(root_);
}

// constructor that inserts elements from a sorted list
// works from the middle, recursively, so that the tree is balanced
BST::BST(vector<int>& sorted_nums){
  root_ = 0;
  construct_helper(sorted_nums);
}

// helper function for destructor
// does a depth-first search
void BST::destroy(Node* current_node){
  // check if current is NULL.  If so, nothing to do
  if(current_node != NULL){
    // Apply recursive call to left and right subtrees
    destroy(current_node->leftsubtree);
    destroy(current_node->rightsubtree);
    
    // with those taken care of, we can delete the current node
    delete current_node;
  }
}

// return true if the tree is empty, i.e. root NULL
bool BST::isEmpty(){
  return root_ == NULL;
}

// print values in a tree-like structure.  Does v - left - right
void BST::print(){
  print_helper(root_, "  ");
  std::cout << "\n";
}

// print helper that tries to represent the tree structure
void BST::print_helper(Node* current_node, std::string spacing){
  // base case: if tree empty, print an E
  if(current_node == 0){
    std::cout << "E";
  }else{
    std::cout << current_node->value << "\n";
    std::cout << spacing << "|";
    print_helper(current_node->leftsubtree, spacing + "  ");
    std::cout << "\n" << spacing << "|";
    print_helper(current_node->rightsubtree, spacing + "  ");
  }
}

// print relies on a helper function as well
// depth-first search strategy
void BST::print_linear_helper(Node* current_node){
  if(current_node == NULL) std::cout << "";
  // first print the left-subtree, then the value, then 
  // the right subtree
  else{
    print_linear_helper(current_node->leftsubtree);
    std::cout << current_node->value << " ";
    print_linear_helper(current_node->rightsubtree);
  }
}

// print all values.  We utilize a depth-first search, 
// so values print starting with left-most leaf
void BST::print_linear(){
  if(root_ == NULL) std::cout << "Tree is empty\n";
  print_linear_helper(root_);
  std::cout << "\n";
}

/////////////////////// End of Andrew's code //////////////////////

// Helper function for insert. Recursively iterates through the three until 
// it finds the proper place to insert. 
// Parameters:
// 1. v (int): The value of the node to be inserted. 
// 2. current_node (Node*): The current node in the recursion process.
// Returns:
// Nothing. Goes through the tree and adds the new node made with value v to the 
// structure of the tree updating the appropriate pointers to reflect this.
void BST::insert_helper(int v, Node* current_node) {
  if (current_node->value > v) {
    if (current_node->leftsubtree == NULL) {
      current_node->leftsubtree = leaf(v);
    } else {
      insert_helper(v, current_node->leftsubtree);
    }
  } else {
    if(current_node->rightsubtree == NULL) {
      current_node->rightsubtree = leaf(v);
    } else {
      insert_helper(v, current_node->rightsubtree);
    }
  }
}

// Inserts a new node to the tree by calling the insert_helper function.
// Parameters:
// v (int): The value of the new node to be added to the tree.
// Returns:
// Nothing. Adds the new node to the tree and updates the proper pointers to 
// reflect this.
void BST::insert(int v) {
  if (BST::root_ == NULL) {
    BST::root_ = leaf(v);
  } else {
  insert_helper(v, root_);
  }
}

// Constructs a binary tree from a passed in vector of ints. This is done by 
// taking the middle index and then making subvectors from the elements on the left
// and right side of it, which should be lesser numbers and larger numbers respectively.
// The function is then recurively called with these subvectors until the numbers are 
// exhausted.
// Parameters:
// 1. nums (vector<int>&): A vector of ints to create nodes from and subsequently
//                         a tree.
// Returns:
// Nothing. Rather, it constructs a binary search tree from the passed in vector.
void BST::construct_helper(vector<int>& nums) {
  if (nums.size() == 0) return;
  std::sort(nums.begin(), nums.end());
  
  if (nums.size() == 1) {
    BST::insert(nums.at(0));
  } else {
    int middle_index = nums.size() / 2;
    BST::insert(nums[middle_index]);
    vector<int>::iterator start = nums.begin();
    vector<int>::iterator middle = nums.begin() + middle_index;
    vector<int>::iterator end = nums.end();

    std::vector<int> left_subvector (start, middle);
    std::vector<int> right_subvector (middle + 1, end);

    construct_helper(left_subvector);
    construct_helper(right_subvector);
    }
}

// Searches the binary tree for the passed in integer and returns
// true or false depending on whether or not it is found.
// Parameters:
// 1. check_me (int): The integer to check whether or not it is in the tree. 
// Returns:
// True or false (so a boolean value) depending on whether or not the value 
// is in the tree.
bool BST::contains(int check_me) {
  if (BST::root_ == NULL) return false;

  return BST::contains_helper(check_me, BST::root_);
}

// Helper for the contains method. Does the actual searching of the tree.
// Parameters:
// 1. check_me (int): The int to search through the tree for.
// 2. current_node (Node*): The current_node in the search process. 
// Returns:
// True or false depending on whether or not the value is found.
bool BST::contains_helper(int check_me, Node* current_node) {
  // if check_me is less, then go down the left subtree
  if (current_node->value > check_me) {
    // seperated instead of including in another if with && so that the else 
    // can take care of returning false
    if (current_node->leftsubtree != NULL) {
      // if the value is found, return true. Else, continue searching
      // down the leftsubtree.
      if (current_node->leftsubtree->value == check_me) {
        return true;
      } else {
        return BST::contains_helper(check_me, current_node->leftsubtree);
      }
    } else {
      return false;
    }
  } else {
    // If the right subtree is not null, check it. Else, return false.
    if (current_node->rightsubtree != NULL) {
      // If the right subtree is the searched for value, return true. Else,
      // continue seaching down the right subtree.
      if (current_node->rightsubtree->value == check_me) {
        return true;
      } else {
        return BST::contains_helper(check_me, current_node->rightsubtree);
      }
    } else {
      return false;
    }
  }
}

// Takes a vector of ints and returns a vector containing the ones in
// the tree. 
// Parameters:
// nums (vector<int>&): The vector of ints to search the tree for.
// Returns:
// A vector of ints containing those found in the tree.
vector<int> BST::subset_contains(vector<int>& nums) {
  // Vector that contains all numbers from nums in the tree.
  vector<int> in_the_tree; 
  // If the tree is empty, return an empty vector.
  if (BST::root_ == NULL) return in_the_tree; 
  // Counter to keep track of how many elements have been checked.
  int counter = 0;

  // While there are still elements to check
  while(counter < nums.size()) {
    bool result = BST::contains(nums.at(counter));
    // If the contains method found the elements, add it to the in_the_tree vector.
    // Otherwise, increment the counter and check the next element.
    if (result == true) {
      in_the_tree.push_back(nums.at(counter));
    }
    counter++;
  }
  return in_the_tree;
}
