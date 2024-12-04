#include "Lab10Part1.h"

// Takes a vector of vectors containing ints and returns the position of n
// in each of the vectors of ints.
// Parameters:
// 1. n (int): The number to search the vectors of ints for.
// 2. g (vector<vector<int>>&): The 2D vector to search through.
// Returns:
// A vector of vector<int> iterators. Each iterator points at the positon
// of n in a vector of ints. If n is not in a certain vector, then the 
// iterator will be pointing to whatever is off the end of the vector. 
vector<vector<int>::iterator> positions(int n, vector<vector<int>>& g) {
  vector<vector<int>::iterator> positions_of_n;
  for (int i = 0; i < g.size(); i++) {
    vector<int>::iterator it = find(g.at(i).begin(), g.at(i).end(), n);
    positions_of_n.push_back(it);
  }
  return positions_of_n;
}

// Main function for lab 10 part 1.
// Parameters:
// None.
// Returns:
// Nothing. Rather, contains code that pertains to lab 10 part 1 that is 
// compiled and ran.
void lab10_part1_main() {
  vector<vector<int>> vec1 = { { 1, 2, 3, 4, 5 },
                               { 2, 3, 4, 5, 0 },
                               { 3, 4, 5, 0, 1 },
                               { 4, 5, 0, 1, 2 },
                               { 5, 0, 1, 2, 3 },
                               { 0, 1, 2, 3, 4 } };

  // This prints out the above 2D vector
  for (int i = 0; i < vec1.size(); i++) {
    for (int j = 0; j < vec1.at(i).size(); j++) {
      std::cout << vec1.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }
  
  vec1.clear();
  std::cout << "vec1 size after clearing: " << vec1.size() << "\n";

  for (int i = 0; i < 6; i++) {
    // Create a row vector to modify and then add to vec1.
    vector<int> row = {1, 2, 3, 4, 5};
    // This inner loop creates the "shifting" effect seen in the 
    // 2D vector itself.
    for (int j = 0; j < row.size(); j++) {
      row.at(j) = (row.at(j) + i) % 6;
    }
    // Add row to vec1.
    vec1.push_back(row);
  }

  // Prints out the 2D vector after filling it via the above code
  for (int i = 0; i < vec1.size(); i++) {
    for (int j = 0; j < vec1.at(i).size(); j++) {
      std::cout << vec1.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }

  // Gets a vector containing iterators pointing to all of the 3s in vec1
  vector<vector<int>::iterator> vec2 = positions(3, vec1);

  std::cout << "vec2 after setting it equal to postions(3, vec1): ";
  for (int i = 0; i < vec2.size(); i++) {
    std::cout << *vec2.at(i) << " ";
  }
  std::cout << "\n";

   // Erases all the 3s in vec 1 by using the iterators in vec2
   for (int i = 0; i < vec2.size(); i++) {
     if (*vec2.at(i) == 3) {
       vec1.at(i).erase(vec2.at(i));
     }
   }

   // Prints out vec1 after erasing all of the 3s
   for (int i = 0; i < vec1.size(); i++) {
    for (int j = 0; j < vec1.at(i).size(); j++) {
      std::cout << vec1.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }

  // Unweighted edges stored in pairs
  std::pair<int, int> e1 (0, 5);
  std::pair<int, int> e2 (5, 2);
  std::pair<int, int> e3 (2, 0);

  // Weighted edges stored in tuples
  std::tuple<int, int, double> e4 (0, 5, 622.42);
  std::tuple<int, int, double> e5 (5, 2, 35.6);
  std::tuple<int, int, double> e6 (2, 0, 0.77);

  // Put the pairs into a vector together
  vector<std::pair<int, int>> vec3 = {e1, e2, e3};
  // Put the tuples into a vector together
  vector<std::tuple<int, int, double>> vec4 = {e4, e5, e6};

  // For loop to loop over the pairs in vec3 and print out the contents of each pair
  for (int i = 0; i < vec3.size(); i++) {
    std::cout<< "edge from " << vec3.at(i).first << " to " << vec3.at(i).second << "\n";
  }
 
  // For loop to loop over the tuples in vec4 and print out the contents of each tuple
  for (int i = 0; i < vec4.size(); i++) {
    std::cout<< "edge from " << std::get<0>(vec4.at(i)) << " to " << std::get<1>(vec4.at(i))  << 
    " with a weight of " << std::get<2>(vec4.at(i)) << "\n";
  }
}