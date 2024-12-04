// .cpp file for Lab 8 Part 1
// Authors: Jules Weick and Jack Hansen

#include "Lab8Part1.h"

// Increments the index, and if index is greater than capacity it 
// sets increment to 0.
// Parameters:
// 1. index (int): The index to increment from.
// 2. capacity(int): The capacity of the array we are using.
// Returns:
// Nothing. Rather, it increments the index.
void increment(int& index, int capacity) {
  index += 1;

  if (index >= capacity) index = 0;
}

// Returns the remainder from key mod capacity. This will serve as the index
// to start trying to store at.
// Parameters:
// 1. key (int): The number to store into the array.
// 2. capacity (int): The amount of memory of the array currently in use.
// Returns:
// The index to start attempting to store the key at, gotten by doing key mod capacity.
int hash(int key, int capacity) {
  return key % capacity;
}

// Adds the key to the array arr. If that spot is taken, it employs
// linear probing in order to store the key in the array.
// Parameters:
// 1. key(int): The key to be stored in the array.
// 2. arr[] (int): The array to store key in.
// 3. size (int): The amount of elements stored in the array.
// 4. capacity (int): The amount of memory assigned to the array currently in use.
// Returns:
// Nothing. Rather, it adds the key to the array if possible.
void add_basic(int key, int arr[], int& size, int capacity) {
  // if the list is full, don't add
  if (size == capacity) return;
  
  int index = hash(key, capacity);

  // if the initial index is free store the element at the index and size
  if (arr[index] == 0) {
    arr[index] = key;
    size++;
  } else {
    // find the next available index, store element and update size
    while (arr[index] != 0) {
      increment(index, capacity);
    }
    arr[index] = key;
    size++;
  }
}

// Checks if the key is in the array.
// Parameters:
// 1. key(int): The key to be stored in the array.
// 2. arr[] (int): The array to store key in.
// 3. size (int): The amount of elements stored in the array.
// 4. capacity (int): The amount of memory assigned to the array currently in use.
// Returns true or false depending on if the key is in the array.
bool check_basic(int key, int arr[], int& size, int capacity) {
  int index = hash(key, capacity);
  bool key_is_present = false; 

  // if initial index is the key
  if (arr[index] == key) {
    key_is_present = true;
    return key_is_present;
  } else {
    // search the rest of the present elements of the list for the key
    int count = 0; // tracks elements checked
    while (arr[index] != key && arr[index] != 0 && count < size) {
      increment(index, capacity);
      if (arr[index] == key) {
        key_is_present = true;
      }
      count++;
    }
  }
  return key_is_present;
}

// Prints the array to the terminal.
// Parameters:
// None.
// Returns:
// Nothing. Rather, prints straight to the terminal.
void print(int arr[], int capacity) {
  // want to print like a list in Python, so square brackets and commas seperating elements
  // in the list itself
  std::cout << "[";

  for (int i = 0; i < capacity; i++) {
    if (i != capacity - 1) { // Want commas seperating elements except the last one where a closing bracket is wanted
      std::cout << arr[i] << ", ";
    } else {
      std::cout << arr[i] << "]\n";
    }
  }
}

// Tests of lab 8 part 1.
// Parameters:
// None.
// Returns:
// Nothing. All tests are printed to the terminal.
void lab8_part1_main() {
  int capacity1 = 5;
  int size1 = 0;
  int capacity2 = 20;
  int size2 = 0;
  int table1[capacity1] = {0, 0, 0, 0, 0}; // want list to be "empty," which 0 represents in this context
  int table2[capacity2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  add_basic(4, table1, size1, capacity1);
  add_basic(14, table1, size1, capacity1);
  add_basic(24, table1, size1, capacity1);
  add_basic(34, table1, size1, capacity1);

  print(table1, capacity1);

  std::cout << "is 34 in table1?: " << check_basic(34, table1, size1, capacity1) << "\n"; // returns 1 for true
  std::cout << "is 11 in table1?: " << check_basic(11, table1, size1, capacity1) << "\n"; // returns 0 for false

  add_basic(6, table2, size2, capacity2);
  add_basic(26, table2, size2, capacity2);
  add_basic(46, table2, size2, capacity2);
  add_basic(66, table2, size2, capacity2);
  add_basic(9, table2, size2, capacity2);
  add_basic(19, table2, size2, capacity2);
  add_basic(29, table2, size2, capacity2);
  add_basic(39, table2, size2, capacity2);

  print(table2, capacity2);

  std::cout << "is 29 in table2?: " << check_basic(29, table2, size2, capacity2) << "\n"; // returns 1 for true
  std::cout << "is 39 in table2?: " << check_basic(39, table2, size2, capacity2) << "\n"; // returns 1 for true
   std::cout << "is 8 in table2?: " << check_basic(8, table2, size2, capacity2) << "\n"; // returns 0 for false

}

