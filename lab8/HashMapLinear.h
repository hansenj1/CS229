//implementation of HashMapLL for lab
//Lab 8 Part 2
//Jack Hansen and Jules Weick
//10/29/24

#include "HashMapLL.h"
#include <iostream>

HashMapLL::HashMapLL(){
    // Default constructor for the HashMapLL object
    // Takes no parameters instantiates a HashMapLL object
    capacity_ = 5;
    size_ = 0;
    load_ = 0;
    loadlimit_ = 0.5;
    contents_ = new LinkedList[capacity_];
}

HashMapLL::~HashMapLL(){
    // Deconstructor to deallocate each LinkedList as well as the contents_ attribute
    delete[] contents_;
    contents_ = nullptr;
}

HashMapLL::HashMapLL(HashMapLL& other){
    // Copy Constructor to create a new HashMapLL that is a copy of another
    capacity_ = other.capacity_;
    size_ = other.size_;
    load_ = other.load_;
    loadlimit_ = other.loadlimit_;
    contents_ = new LinkedList[capacity_];
    for(int i = 0; i < capacity_; i++){
        contents_[i] = other.contents_[i];
    }
}

HashMapLL HashMapLL::operator=(HashMapLL& other){
    // Following rule of 3, assignment operator for HashMapLL objects
    if(this == &other){
        return *this;
    }
    
    delete[] contents_;
    
    capacity_ = other.capacity_;
    size_ = other.size_;
    load_ = other.load_;
    loadlimit_ = other.loadlimit_;
    contents_ = new LinkedList[capacity_];
    for(int i = 0; i < capacity_; i++){
        contents_[i] = other.contents_[i];
    }
    return *this;
}

void HashMapLL::print(){
    // Print function for the HashMapLL object
    // Parameters:
    // None
    // Returns:
    // Nothing. this will print each index followed by its contents, with each index having one line
    for(int i = 0; i < capacity_; i++){
        std::cout << "Index: " << i << " LL Contents: " << contents_[i].ToString() << "\n";
    }
}

int HashMapLL::get_capacity(){
    // Getter function for capacity attribute
    // Parameters:
    // None
    // Returns:
    // the capacity attribute
    return capacity_;
}

int HashMapLL::get_size(){
    // Getter function for size attribute
    // Parameters:
    // None
    // Returns:
    // the size attribute
    return size_;
}

double HashMapLL::get_load(){
    // Getter function for load attribute
    // Parameters:
    // None
    // Returns:
    // the load attribute 
    return load_;
}

void HashMapLL::reallocate(){
    // This function will reallocate the HashMapLL so that it can store more good stuff. also rehashes the keys using the new capacity
    // Parameters:
    // None
    // Returns:
    // Nothing, this function reallocates the object with double the capacity 
    int old_capacity = capacity_;
    capacity_ *= 2;
    LinkedList* old_contents = contents_;
    contents_ = new LinkedList[capacity_];
    for(int j = 0; j < old_capacity; j++){
        for(int k = 0; k < old_contents[j].GetSize(); k++){
            char found_key = old_contents[j].Get(k);
            int result = hash(found_key);
            contents_[result].Append(found_key);
        }
    }
    delete[] old_contents;
    old_contents = nullptr; 
}

int HashMapLL::hash(char key){
    // This function will hash a key using the capacity and return the result
    // Parameters:
    // char key: the key to be hashed
    // Returns:
    // The result after hashing the key
    return key % capacity_;
}

void HashMapLL::add(char key){
    // This function will add a key to the Hashmap
    // Parameters:
    // char key: the key to be hashed and added
    // Returns:
    // nothing
    if(load_ > loadlimit_){
        reallocate();
    }
    int result = hash(key);
    contents_[result].Append(key);
    size_++;
    load_ = (double)(size_) / capacity_;
}

bool HashMapLL::check(char key){
    // This function will check whether a key is in the Hashmap or not
    // Parameters:
    // char key: the key to be searched for
    // Returns:
    // true or false
    int result = hash(key);
    return contents_[result].Contains(key);
}

void HashMapLL::erase(char key){
    // This function will erase a key from the Hashmap
    // Parameters:
    // char key: the key to be removed
    // Returns:
    // nothing
    int result = hash(key);
    if(check(key)){
        contents_[result].Remove(key);
        size_--;
        load_ = (double)(size_) / capacity_;
    }
    else{
        std::cout << "Key was not found in HashMap \n";
    }
}
