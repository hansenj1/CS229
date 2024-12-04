// .cpp file for HashMapLinear class
// Authors: Jules Weick and Jack Hansen

#include "HashMapLinear.h"

// Default constructor for the HashMapLinear class.
// Parameters:
// None.
// Instantiates:
// An instance of the class with default values set for the attributes.
HashMapLinear::HashMapLinear() {
  HashMapLinear::capacity_ = 5; // maximum amount of elements, should never be reached as the load should be less than 1
  HashMapLinear::size_ = 0; // amount of elements in the arrays
  HashMapLinear::loadlimit_ = 0.5; // if load is greater, then arrays are reallocated
  HashMapLinear::load_ = 0; // load = size / capacity
  HashMapLinear::contents_ = new char[HashMapLinear::capacity_]; // Array for the elements 
  HashMapLinear::status_ = new char[HashMapLinear::capacity_]; // Array for the status of indexes in contents_

  // set contents_ to all null characters and status to all 'E,' representing "Empty"
  for (int i = 0; i < HashMapLinear::capacity_; i++) {
    HashMapLinear::contents_[i] = '\0';
    HashMapLinear::status_[i] = 'E';
  }
}

// Destructor for HashMapLinear Class. Zeroes out and deletes both array.
// Parameters:
// None.
// Returns:
// Nothing. Rather, deallocates both internal arrays of the HashMapLinear class.
HashMapLinear::~HashMapLinear() {
  HashMapLinear::contents_ = 0;
  HashMapLinear::status_ = 0;

  delete[] HashMapLinear::contents_;
  delete[] HashMapLinear::status_;
}

// Creates an instance of the HashMapLinear class from another instance of the class.
// Parameters:
// 1. other (HashMapLinear&): The instance of the class to copy attributes from.
// Instantiates:
// An instance of the class with the same attributes as the other instance of the class.
HashMapLinear::HashMapLinear(const HashMapLinear& other) {
  HashMapLinear::capacity_ = other.capacity_;
  HashMapLinear::size_ = other.size_;
  HashMapLinear::load_ = other.load_;
  HashMapLinear::loadlimit_ = other.loadlimit_;

  HashMapLinear::contents_ = new char[HashMapLinear::capacity_];
  HashMapLinear::status_ = new char[HashMapLinear::capacity_];

  for (int i = 0; i < HashMapLinear::capacity_; i++) {
    HashMapLinear::contents_[i] = other.contents_[i];
    HashMapLinear::status_[i] = other.status_[i];
  }
}

// Assignment operator for the HashMapLinear class.
// Parameters:
// 1. other (HashMapLinear&): The instance of the class to set this instance of the class to.
// Returns:
// An instance of the HashMapLinear class that has the same attributes as the other instance.
HashMapLinear& HashMapLinear::operator=(const HashMapLinear& other) {
  if (this == &other) {
    return *this;
  } else {
    delete[] HashMapLinear::contents_;
    delete[] HashMapLinear::status_;

    HashMapLinear::capacity_ = other.capacity_;
    HashMapLinear::size_ = other.size_;
    HashMapLinear::load_ = other.load_;
    HashMapLinear::loadlimit_ = other.loadlimit_;

    HashMapLinear::contents_ = new char[HashMapLinear::capacity_];
    HashMapLinear::status_ = new char[HashMapLinear::capacity_];
    for (int i = 0; i < HashMapLinear::capacity_; i++) {
        HashMapLinear::contents_[i] = other.contents_[i];
        HashMapLinear::status_[i] = other.status_[i];
    }
    return *this;
  }
}

// Prints out the array with an index, its key, and the status of the entry per line.
// Parameters:
// None.
// Returns:
// Nothing. Rather, prints as specified to the terminal.
void HashMapLinear::print() {
  for (int i = 0; i < HashMapLinear::capacity_; i++) {
    // should print each index on seperate lines like: <index>: key -- <key> & status -- <status>
    std::cout << i << ": " << "key -- " << HashMapLinear::contents_[i] << 
    " & status -- " << HashMapLinear::status_[i] << "\n";
  }
}

// Returns the size of this instance of the HashMapLinear class.
// Parameters:
// None.
// Returns:
// The size of the internal arrays which is equal to the amount of elements.
int HashMapLinear::get_size() {
  return HashMapLinear::size_;
}

// Returns the capacity of this instance of the HashMapLinear class.
// Parameters:
// None.
// Returns:
// The capacity of the internal arrays.
int HashMapLinear::get_capacity() {
  return HashMapLinear::capacity_;  
}

// Returns the load of this instance of the HashMapLinear class.
// Parameters:
// None.
// Returns:
// The load variable of this instance of the class.
double HashMapLinear::get_load() {
  return HashMapLinear::load_; 
}

// Increments the index passed into the function, resetting to 0 if needed.
// Parameters:
// 1. index (int&): The index to increment, passed by reference so that changes stick.
// Returns:
// Nothing. Rather, increments the index and that change sticks so there is no need to return.
void HashMapLinear::inc_index(int& index) {
  index += 1;

  if (index >= HashMapLinear::capacity_) index = 0;
}

// Hashes the key to get the index to store the key at by doing key mod capacity.
// Parameters:
// key (char): The character to store in the array.
// Returns:
// The index to store the key at.
int HashMapLinear::hash(char key) {
  return key % HashMapLinear::capacity_;
}

// Increases the capacity of the array by doubling it.
// Parameters:
// None.
// Returns:
// Nothing. Rather, creates new arrays with the same elements and an updated capacity.
void HashMapLinear::reallocate() {
  // Need to store the old capacity in order to loop through the old arrays before doubling capacity.
  int old_capacity = HashMapLinear::capacity_;
  HashMapLinear::capacity_ *= 2;

  // Need to create pointers to the old arrays before establishing new arrays.
  char* old_contents = HashMapLinear::contents_;
  char* old_status = HashMapLinear::status_;

  // Need to create new arrays with the new capacity and initialize them to what the functions are expecting.
  HashMapLinear::contents_ = new char[HashMapLinear::capacity_];
  HashMapLinear::status_ = new char[HashMapLinear::capacity_];
  for (int i = 0; i < HashMapLinear::capacity_; i++) {
    HashMapLinear::contents_[i] = '\0';
    HashMapLinear::status_[i] = 'E';
  }

  // Want to loop through the elements of old_contents, so loop terminates at old_capacity
  for (int i = 0; i < old_capacity; i++) {
    // If there is an element present at the index in the old arrays
    if (old_status[i] == 'O') {
      // Get the new index to store the element at in the new arrays
      int index = HashMapLinear::hash(old_contents[i]);

      // If the space is available, add it. Else, find the next available space.
      if (HashMapLinear::status_[index] == 'E' || HashMapLinear::status_[index] == 'D') {
        // Set the index to the element, update the status and size.
        HashMapLinear::contents_[index] = old_contents[i];
        HashMapLinear::status_[index] = 'O';
      } else {
        // If the initial index is taken, find the next avaialble index.
        // There will always be enough available spaces after having doubled the capacity, so
        // no need to worry about all spaces being occupied.
        while (HashMapLinear::status_[index] != 'E' && HashMapLinear::status_[index] != 'D') {
          inc_index(index);
        }
        HashMapLinear::contents_[index] = old_contents[i];
        HashMapLinear::status_[index] = 'O';
      } 
    }
  }
  // Update the load, should be lower as size does not change but capacity does
  HashMapLinear::load_ = double(HashMapLinear::size_) / HashMapLinear::capacity_;
}

// Adds a new key to the array.
// Parameters:
// 1. key (char): The character to add to the array.
// Returns:
// Nothing. Rather, it adds the key to the to the array.
void HashMapLinear::add(char key) {
  // If the amount of elements is over the load limit, double the available space.
  if (((double(HashMapLinear::size_ + 1)) / HashMapLinear::capacity_) > HashMapLinear::loadlimit_) {
    HashMapLinear::reallocate();
  }

  // Get the index to start searching for somewhere to store at.
  int index = HashMapLinear::hash(key);

  // If the initial space is available, set the index to the key, update the status and size.
  if (HashMapLinear::status_[index] == 'E' || HashMapLinear::status_[index] == 'D') {
    HashMapLinear::contents_[index] = key;
    HashMapLinear::status_[index] = 'O';
    HashMapLinear::size_++;
    // size increased, therefore need to update the load
    HashMapLinear::load_ = double(HashMapLinear::size_) / HashMapLinear::capacity_;
  } else {
    // If the initial space is not available, find the next available index.
    while (HashMapLinear::status_[index] != 'E' && HashMapLinear::status_[index] != 'D') {
      inc_index(index);
    }

    HashMapLinear::contents_[index] = key;
    HashMapLinear::status_[index] = 'O';
    HashMapLinear::size_++;
    // size increases, therefore need to recalculate the load
    HashMapLinear::load_ = double(HashMapLinear::size_) / HashMapLinear::capacity_;
  }
}

// Checks whether or not a key is in the array.
// Parameters:
// 1. key (char): The character to check if it is in the array.
// Returns:
// True or false depending on if the character is in the array.
bool HashMapLinear::check(char key) {
  int index = HashMapLinear::hash(key);
  bool key_is_present = false;

  // check if the initial index is the key, if so return true
  if(HashMapLinear::contents_[index] == key) {
    key_is_present = true;
    return key_is_present;
  } else {
    // iterate through the list starting at the hash index seeing if the key is present at all.
    // if found, return it. the amount of elements seen is tracked to exit out of the while sooner
    // if we've seen all of the elements in the list already.
    int count = 0;
    while (count < HashMapLinear::size_ && HashMapLinear::status_[index] != 'E' &&
    HashMapLinear::contents_[index] != key) {
      inc_index(index);
      if (HashMapLinear::contents_[index] == key) {
        key_is_present = true;
      }
      count++;
    }
  }
  return key_is_present;
}

// Erases the key if it is found.
// Parameters:
// 1. key (char): The character to search for and erase if found.
// Returns:
// Nothing. Erases the key if it finds it.
void HashMapLinear::erase(char key) {
  // check that they key exists
  if (HashMapLinear::check(key) == false) {
    std::cout << "That key is not present, thus cannot be erased.\n";
  }

  // get initial index
  int index = HashMapLinear::hash(key);

  // if the initial index is the key, delete it and update the status, size, and load
  if(HashMapLinear::contents_[index] == key) {
    HashMapLinear::contents_[index] = '\0';
    HashMapLinear::status_[index] = 'D';
    HashMapLinear::size_--;
    HashMapLinear::load_ = double(HashMapLinear::size_) / HashMapLinear::capacity_;
  } else {
    // if the initial index is not the key, search through the rest of the list and if found 
    // elsewhere, delete it and update the status, size, and load accordingly
    int count = 0;
    while (count < HashMapLinear::size_ && HashMapLinear::status_[index] == 'O' &&
    HashMapLinear::contents_[index] != key) {
      inc_index(index);
      if (HashMapLinear::contents_[index] == key) {
        HashMapLinear::contents_[index] = '\0';
        HashMapLinear::status_[index] = 'D';
        HashMapLinear::size_--;
        HashMapLinear::load_ = double(HashMapLinear::size_) / HashMapLinear::capacity_;
      }
      count++;
    }
  }
}