/* main file for binary search tree class called BST
Stores a collection of ints
Andrew Shallue, CS229, Fall 2024
*/
// Main file for lab 9
// Provided by Professor Shallue, any modifications by Jules Weick and Jack Hansen

#include <iostream>
#include "BST.h"
#include "Tree.h"
#include "Lab9Part1.h"

void part2_test(){
    std::cout << "Hello World, are you ready for a BST?\n";

    // let's create the a tree with 2 as the root, vals 1 2 3 4 5
    // leafs are 1 3 5
    Node* l1 = leaf(1);
    Node* l3 = leaf(3);
    Node* l5 = leaf(5);
    // create n4 as the parent of l3 and l5
    Node* n4 = new Node;
    n4->value = 4;
    n4->leftsubtree = l3;
    n4->rightsubtree = l5;
    // create n2 as the parent of l1 and n4
    Node* n2 = new Node;
    n2->value = 2;
    n2->leftsubtree = l1;
    n2->rightsubtree = n4;

    // now create BST object and set root to n2
    BST tree1 = BST();
    tree1.root_ = n2;
    tree1.print();

    // create a BST object using insert
    BST tree2 = BST();
    for(int i = 0; i < 7; i++){
        tree2.insert(i);
    }
    tree2.print();

    std::cout << "\n";
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<int>::iterator i1 = nums1.begin();
    vector<int>::iterator i2 = nums1.begin() + 3;
    
    vector<int> nums2 = vector<int>(i1, i2);
    for(int i = 0; i < nums2.size(); i++){
        std::cout << nums2.at(i) << " ";
    }
    std::cout << "\n";

    BST tree3 = BST(nums1);
    tree3.print();

    bool check1 = tree3.contains(0);
    bool check2 = tree3.contains(1);
    bool check3 = tree3.contains(12);
    bool check4 = tree3.contains(30);
    if(!check1 && check2 && check3 && !check4){
        std::cout << "passed all contains checks\n";
    }else{
        std::cout << "failed at least one contains check\n";
    }

    vector<int> nums3 = {5, 10, 15, 20, 25, 30};
    vector<int> in_tree = tree3.subset_contains(nums3);
    std::cout << "subset in tree3 should be [5, 10, 15]: ";
    for(int i = 0; i < in_tree.size(); ++i){
        std::cout << in_tree.at(i) << " ";
    }
    std::cout << "\n";
}

void part3_test(){
    // create a tree with branching factor 3.  Tree should be balanced.
    Tree t1 = Tree();
    int b = 3;
    for(int i = 4; i < 26; ++i){
        t1.insert(i, b);
    }
    t1.print();

    // test subset_contains (and hence contains)
    // should see 10 20 13
    vector<int> nums = {10, 20, 30, 40, 50, 13};
    vector<int> sub = t1.subset_contains(nums);
    print_vector(sub);
}

int main(){
    lab9_part1_main();
    part2_test();
    part3_test();   
    
}