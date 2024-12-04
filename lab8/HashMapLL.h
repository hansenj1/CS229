/* An implementation of a hashmap using separate chaining.
This means the core data structure is an array of linked lists.
Our keys will be of type char.  The hash function will be simple modular reduction.
Andrew Shallue, CS229, Fall 2024
*/
// Provided by professor Shallue.
// Header file for HashMapLL.

#ifndef HASHMAPLL_H
#define HASHMAPLL_H

#include "LinkedList.h"
#include <iostream>

class HashMapLL{
    private:
        // contents is an array of LinkedLists
        LinkedList* contents_;
        int capacity_;
        int size_;
        double load_;
        // load limit is the maximum load can get.  Larger and we reallocate.
        double loadlimit_;
    
    public:
        // constructor and rule of 3
        HashMapLL();
        ~HashMapLL();
        HashMapLL(HashMapLL& other);
        HashMapLL operator=(HashMapLL& other);

        // print and getter functions
        void print();
        int get_capacity();
        int get_size();
        double get_load();

        // standard operations are add, check, erase
        void reallocate();
        int hash(char key);
        void add(char key);
        bool check(char key);
        void erase(char key);

};

#endif