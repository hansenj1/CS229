/* Tree class where there could be multiple children of each node.
We will use a vector to store the children.

Andrew Shallue, CS229, Fall 2024
*/
// Header file for Tree class 
// Provided by Professor Shallue, any modifications by: Jules Weick and Jack Hansen

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode{
  int value;
  vector<TreeNode*> subtrees;
};

// function to create a leaf node
TreeNode* tree_leaf(int v);

class Tree{
public:
    TreeNode* root_; // pointer to root of the tree

  public:
    // default constructor points root to NULL
    Tree();  
    // destructor calls recursive function destroy
    ~Tree();
    // I should implement rule of 3, but haven't done so yet.

    // return true if the tree is empty, i.e. root NULL
    bool isEmpty();

    // create a new leaf with value v, insert into the tree 
    // fill up current level according to branching factor, then increase depth
    void insert(int v, int branching_factor);

    // check whether the tree contains the given integer.  Strategy: DFS
    bool contains(int check_me);

    // return the sublist of nums which is contained in the tree
    vector<int> subset_contains(vector<int>& nums);

    // print values in a tree-like structure.  Does v - left - right
    void print();

  // a variety of helper functions.
  private:
    // insert relies on a helper function which tracks current node
    void insert_helper(int v, int branching_factor, TreeNode* current_node);

    // helper functions for contains which performs a DFS
    bool contains_helper(int check_me, TreeNode* current_node);
    
    // print helper that tries to represent the tree structure
    void print_helper(TreeNode* current_node, std::string spacing);

    // helper function for destructor
    void destroy(TreeNode* current_node);
};

#endif