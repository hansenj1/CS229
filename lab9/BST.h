/* Creating binary search trees in C++
// Andrew Shallue, Fall 2019, CS 355
// adapted for Fall 2024, CS229

// A binary search tree has a value, a left subtree, and a right subtree.  It is fundamentally recursive in nature.

// I am closely following the code at this link:
// https://www.cprogramming.com/tutorial/lesson18.html

I don't want to worry about rotations, so removal is not part of the class.
*/
// Header file for BST class 
// Provided by Professor Shallue, any modifications by: Jules Weick and Jack Hansen

#include<string>
#include<vector>
#include<algorithm>

using std::vector;

#ifndef BST_H
#define BST_H

struct Node{
  int value;
  Node* leftsubtree;  // pointer to left child
  Node* rightsubtree;  // pointer to right child
};

// function to create a leaf node
Node* leaf(int v);

class BST{
  public:
    Node* root_; // pointer to root of the tree

  public:
    // default constructor points root to NULL
    BST();  
    // destructor calls recursive function destroy
    ~BST();
    // constructor that inserts elements from a sorted list
    // works from the middle, recursively, so that the tree is balanced
    BST(vector<int>& sorted_nums);

    // I should implement rule of 3, but haven't done so yet.

    // return true if the tree is empty, i.e. root NULL
    bool isEmpty();

    // create a new leaf with value v, insert into the tree 
    // so that binary property is preserved.  Recursive.
    void insert(int v); 

    // check whether the tree contains the given integer
    bool contains(int check_me); // need to implement

    // return the sublist of nums which is contained in the tree
    vector<int> subset_contains(vector<int>& nums); 

    // print values in a tree-like structure.  Does v - left - right
    void print();

    // print all values.  We utilize a depth-first search, 
    // so values print starting with left-most leaf
    void print_linear();

  // a variety of helper functions.
  private:
    // insert relies on a helper function which tracks current node
    void insert_helper(int v, Node* current_node); 

    // helper functions for contains which utilize binary search property
    bool contains_helper(int check_me, Node* current_node); 

    // construct a balanced tree from a sorted vector
    void construct_helper(vector<int>& nums); 
    
    // print helper that tries to represent the tree structure
    void print_helper(Node* current_node, std::string spacing);

    // print relies on a helper function as well
    void print_linear_helper(Node* current_node);
    // helper function for destructor
    void destroy(Node* current_node);
};

#endif

