// .cpp file for the DenseGraph Class
// Authors:: Jules Weick and Jack Hansen
#include "DenseGraph.h"

// Default constructor for the DenseGraph class.
// Parameters:
// None.
// Instantiates:
// An instance of the class with zero vertices and zero edges.
DenseGraph::DenseGraph() {
  DenseGraph::num_vertices_ = 0;
  DenseGraph::edges_ = {};
}

// Non-default constructor for the DenseGraph class that makes 
// that has n vertices.
// Parameters:
// 1. n (int): The number of vertices the graph has.
// Instantiates:
// An instance of the class with n vertices and zero edges.
DenseGraph::DenseGraph(int n) {
  DenseGraph::num_vertices_ = n;
  // Make the edges_ 2D vector with all 0s to represent no edges existing yet.
  for (int i = 0; i < DenseGraph::num_vertices_; i++) {
    vector<double> row (DenseGraph::num_vertices_, 0);
    DenseGraph::edges_.push_back(row);
  }
}

// Makes the graph "complete" meaning that every possible edge
// is added to the edges_ 2D vector with the passed in weight.
// Parameters:
// 1. weight (int): The weight to assign each edge.
// Returns:
// Nothing. Rather, it adds every possible edge to edges_.
void DenseGraph::make_complete(double weight) {
  // To create a complete graph, we have an outer loop that runs
  // num_vertices times and an inner loop that does the same. We
  // check if j == i and if so put a zero there so we don't 
  // inadvertantly have a vertex pointing to itself.
  for (int i = 0; i < DenseGraph::edges_.size(); i++) {
    vector<double> row (DenseGraph::num_vertices_, 0);
    for (int j = 0; j < DenseGraph::edges_.size(); j++) {
      if (j == i) {
        row.at(j) = 0;
      } else {
        row.at(j) = weight;
      }
    }
    DenseGraph::edges_.at(i) = row;
  }
}

// Makes a cycle in a graph by changing (0, 1), (1, 2), (2, 3), ... 
// to the passed in weight
// Parameters:
// 1. weight (double): The weight to change edges to having.
// Returns:
// Nothing. Rather, updates the respective edges in the edges_ 2D vector.
void DenseGraph::make_cycle(double weight) {
  // The pattern follows (i, i + 1) so to create that pattern we have 
  // an outer for loop that runs num_vertices time and an inner loop 
  // that only runs once.
  for (int i = 0; i < edges_.size(); i++) {
    for (int j = i + 1; j < i + 2; j++) {
      DenseGraph::edges_.at(i).at(j % 6) = weight;
    }
  }
}

// Adds an edge to the edges_ 2D vector.
// Parameters:
// 1. new_edges (vector<tuple<int, int, double> >&): A vector of tuples
// that contain the coordinates of the edge in the first two positions 
// and the weight in the third positon of the tuple.
// Returns:
// Nothing. Rather, adds the edge to edges_.
void DenseGraph::add_edges(vector<tuple<int, int, double> >& new_edges) {
  for (int i = 0; i < new_edges.size(); i++) {
    // The 0th element of a tuple is the row coordinate and the second element
    // is the column position of an edge pair and weight is the third element.
    DenseGraph::edges_.at(get<0>(new_edges.at(i))).at(get<1>(new_edges.at(i))) = get<2>(new_edges.at(i));
  }
}

// Adds a new edge to the graph and connects it to those passed in via neighbors
// with the respective weights.
// Parameters:
// 1. neighbors (vector<pair<int, double>>& neighbors): A vector of pairs
//    that contain a vertex to be made a neighbor to the new node in the 
//    first position and the weight of the new edge in the second postion.
// Returns:
// Nothing. Rather, adds a new vertex and connects it to the nodes passed in
// with their corresponding weights.
void DenseGraph::add_vertex(vector<pair<int, double>>& neighbors) { 
  // Update the number of vertices.
  std::cout << "num of vertices before adding: " << DenseGraph::num_vertices_ << "\n";
  DenseGraph::num_vertices_++;
  std::cout << "num of vertices after adding: " << DenseGraph::num_vertices_ << "\n";
  // Create a new row for the new vertex to have edges added to it.
  std::vector<double> new_row (DenseGraph::num_vertices_, 0);

  // Go through the existing vertices and add the new vertex to them.
  for (int i = 0; i < DenseGraph::edges_.size(); i++) {
    DenseGraph::edges_.at(i).push_back(0);
  }

  // Create the edges of the new vertex from those passed in via neighbor.
  for (int i = 0; i < neighbors.size(); i++) {
    new_row.at(neighbors.at(i).first) = neighbors.at(i).second;
  }

  // Add the new row to the graph.
  DenseGraph::edges_.push_back(new_row);
}

// Disconnects the passed in vertex from all edges to and from it.
// Parameters:
// 1. v (int): The vertex to be disconnected.
// Returns:
// Nothing. Rather, it sets all edge weights to zero to and from v
// to reflect it being disconnected.
void DenseGraph::disconnect_vertex(int v) {
  // If v is not a valid vertex, stop.
  if (v < 0 || v >= DenseGraph::edges_.size()) {
    return;
  }
  
  // Go through existing vertices and set any pointing to v to 0.
  for (int i = 0; i < DenseGraph::edges_.size(); i++) {
    DenseGraph::edges_.at(i).at(v) = 0;
  }
  
  // Set all of v's out-edges to 0.
  for (int i = 0; i < DenseGraph::edges_.size(); i++) {
    DenseGraph::edges_.at(v).at(i) = 0;
  }
}

// "Deletes" every edge in the remove_edges vector by setting the weight 
// of the specific edge to 0.
// Parameters:
// 1. remove_edges (vector< pair<int, int> >&): A vector containing pairs
//    that represent the coordinate of the edge to be removed
// Returns:
// Nothing. Rather, sets the respective edges to zero to reflect being "deleted."
void DenseGraph::delete_edges(vector< pair<int, int> >& remove_edges) {
  for (int i = 0; i < remove_edges.size(); i++) {
    // Getting the vertices/coordinates from the pair
    int coordinate1 = remove_edges.at(i).first;
    int coordinate2 = remove_edges.at(i).second;

    // Validating that the coordinates/indices are actual vertices
    if (coordinate1 < 0 || coordinate1 >= DenseGraph::edges_.size()) continue;
    if (coordinate2 < 0 || coordinate2 >= DenseGraph::edges_.size()) continue;
 
    // If vertices/coordinates are valid, set the respective coordinate/vertex to 0.
    DenseGraph::edges_.at(coordinate1).at(coordinate2) = 0;
  }
}

// Returns the amount of edges v has where it is pointing out/to another vertex.
// Parameters:
// 1. v (int): The vertex to return the out-degree of.
int DenseGraph::out_degree(int v) {
  int out_degree = 0;
  for (int i = 0; i < DenseGraph::edges_.size(); i++) {
    if (DenseGraph::edges_.at(v).at(i) > 0) out_degree++;
  }
  return out_degree;
}

// Returns the out-degree of the vertex with the highest out-degree.
// Parameters:
// None.
// Returns:
// The out-degree of the vertex with the highest out-degree.
int DenseGraph::max_out_degree() {
  // to prevent running on an empty graph.
  if (DenseGraph::edges_.size() == 0) return 0;
  
  // set value to the out-degree of the 0th vertex, will then compare to 
  // all other vertices.
  int max_out_degree = DenseGraph::out_degree(0);
  
  int counter = 0;
  while (counter < DenseGraph::edges_.size()) {
    int out_degree_value = DenseGraph::out_degree(counter);
    if (out_degree_value > max_out_degree) {
      max_out_degree = out_degree_value;
    }
    counter++;
  }
  return max_out_degree;
}

// Returns the weight of the edge from v1 to v2. If there is no edge
// 0 is returned.
// Parameters:
// 1. v1 (int): The first coordinate of the edge pair to return the weight of.
// 2. v2 (int): The second coordinate of the edge pair to return the weight of.
// Returns:
// The value of the edge (v1, v2), including zero if there is no edge. 
double DenseGraph::adjacent_cost(int v1, int v2) {
  if (v1 < 0 || v1 > DenseGraph::edges_.size()) return 0;
  if (v2 < 0 || v2 > DenseGraph::edges_.size()) return 0;

  // No edge case needed to specifically return 0 as 0 is the default value of an edge.
  return DenseGraph::edges_.at(v1).at(v2);
}

// Returns the cost/total weight of a "path," which is a vector of pairs of edges.
// Parameters:
// 1. path (vector < pair<int, int> >&): The edges to sum the weight of.
// Returns:
// The sum of all of the edges weights.
double DenseGraph::path_cost(vector< pair<int, int> >& path) {
  int cost_of_path = 0;
  for (int i = 0; i < path.size(); i++) {
    int edge_cost = DenseGraph::adjacent_cost(path.at(i).first, path.at(i).second);
    if (edge_cost == 0) return 0;
    cost_of_path += edge_cost;
  }
  return cost_of_path;
}

// Returns the minimum cost of all two step or less paths. If there is a direct path,
// that is returned.
// Parameters:
// 1. v1 (int): The first/starting vertex.
// 2. v2 (int): The last/ending vertex.
// Returns:
// The path that has the least total cost/weight.
double DenseGraph::min_two_path(int v1, int v2) {
  // Check it v1 and v2 are directly connected.
  if (DenseGraph::adjacent_cost(v1, v2) > 0) {
    return DenseGraph::adjacent_cost(v1, v2);
  }
  // Set min_cost to a ridiculous value so that when checking against it, it will
  // guaranteed be set to at least one value checked against it
  int min_cost = 5000;

  // Loop through all out-edges of v1
  for (int i = 0; i < DenseGraph::edges_.at(v1).size(); i++) {
    // If v1 has an out-edge
    if (DenseGraph::edges_.at(v1).at(i) > 0 ) {
        // If the vertex pointed to by that previous out-edge shares an edge with v2
        if (DenseGraph::edges_.at(i).at(v2) > 0) {
          // Get the weight of the first out-edge plus that node's weight of its connection to v2
          int path_cost = DenseGraph::adjacent_cost(v1, i) + DenseGraph::adjacent_cost(i, v2);
          // If the path_cost is less than the current minimum cost, update minimum cost
          if (path_cost < min_cost) {
            min_cost = path_cost;
          }
        }
      }
    }
  return min_cost; 
}


// Prints out all vertices and edges, one per line.
// Parameters:
// None.
// Returns:
// Nothing. Rather, it outputs all vertices and edges to the console.
void DenseGraph::print() {
  // The reason for this if else is so that if we encounter a graph with
  // an empty edges_ 2D vector, we can create a graph of the appropriate size
  // with no edges.
  if (DenseGraph::edges_.size() > 0) {
    for (int i = 0; i < DenseGraph::edges_.size(); i++) {
      std::cout << i << ": ";
      for (int j = 0; j < DenseGraph::edges_.at(i).size(); j++) {
        std::cout << DenseGraph::edges_.at(i).at(j) << " ";
      }
      std::cout <<" size of row: " << DenseGraph::edges_.at(i).size();
      std::cout << "\n";
    }
  } 
}