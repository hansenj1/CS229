/* Hashmap ADT using linear probing as the collision resolution.
Stores characters, has same functionality as HashMapSeq
Andrew Shallue, Fall 2024, CS229
*/
// Provided by professor Shallue.
// Header file for HashMapLinear.

#ifndef HASHMAPLINEAR_H
#define HASHMAPLINEAR_H

#include <iostream>

class HashMapLinear{
    private:
        // contents contains the keys, 
        // status could be (E)mpty, (O)ccupied, (D)eleted
        char* contents_;
        char* status_;

        int capacity_;
        int size_;
        double load_;
        double loadlimit_;

        // helper function to increment.  If you reach end, loop back to 0
        void inc_index(int& index);
    
    public:
        HashMapLinear();
        ~HashMapLinear();
        HashMapLinear(const HashMapLinear& other);
        HashMapLinear& operator=(const HashMapLinear& other);

        void print();
        int get_size();
        int get_capacity();
        double get_load();

        void reallocate();
        int hash(char key);
        void add(char key);
        bool check(char key);
        void erase(char key);

};


#endif