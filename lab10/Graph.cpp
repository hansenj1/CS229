/*
Implementation of Graph class which utilizes a sparse representation
Jules Weick and Jack Hansen, Lab 10, CS229 November 2024
*/

#include "Graph.h"

Graph::Graph(){
    //default constructor to make an empty Graph object
    Graph::num_vertices_ = 0;
    Graph::edges_ = vector<vector<int>>();

}

Graph::Graph(int n){
    //non-default constructor to create a graph with num_vertices n and create n empty vectors
    Graph::num_vertices_ = n;
    for(int i = 0; i < num_vertices_; i++){
        //instantiate n empty rows within edges
        Graph::edges_.push_back(vector<int>());
    }
}

void Graph::print(){
    /*Function to print the edge connections of each vertex
    Parameters:
        - None
    Returns:
        - Nothing. This function will print it's output
    
    */
   for(int i = 0; i < Graph::edges_.size(); i++){
	    vector<int>& row = Graph::edges_.at(i);
	    //print everything in each row
        std::cout << i << ": ";
        for(int j = 0; j < row.size(); j++){
            std::cout << row.at(j) << " ";
        }
        std::cout << "\n";
    }
}

void Graph::make_complete() {
    /*Function to make an edge between every vertex
    Parameters:
        - None
    Returns:
        - Nothing. This function works in-place
    */
    for (int i = 0; i < Graph::edges_.size(); i++) {
        vector<int>& row = Graph::edges_.at(i);
        for (int j = 0; j < num_vertices_; j++) { // Iterate over all vertices
            if (j != i && std::find(row.begin(), row.end(), j) == row.end()) {
                row.push_back(j); // Add edge to j if not already present
                Graph::edges_.at(j).push_back(i); // Add edge back to i
            }
        }
    }
}

void Graph::make_cycle() {
    /*This function will turn the existing Graph into a cycle
    Parameters:
        - None
    Returns:
        - Nothing
    
    */
    for(int i = 0; i < num_vertices_; ++i) {
        edges_[i].clear();
    }

    //turn into a cycle
    for(int i = 0; i < num_vertices_; ++i) {
        int next_vertex = (i + 1) % num_vertices_;
        edges_[i].push_back(next_vertex);  // Add edge from i to next_vertex
        edges_[next_vertex].push_back(i); // Add edge from next_vertex to i
    }
}

void Graph::add_edges(vector<pair<int, int>>& pairs) {
    /* Adds edges specified by a vector of vertex pairs.
    Parameters:
        - vector<pair<int, int>>& pairs: List of vertex pairs to connect.
    Returns:
        - Nothing. Updates the Graph with new edges.
    */
    for (auto& pair : pairs) {
        int u = pair.first;
        int v = pair.second;
        if (find(edges_[u].begin(), edges_[u].end(), v) == edges_[u].end()) {
            edges_[u].push_back(v);
        }
        if (find(edges_[v].begin(), edges_[v].end(), u) == edges_[v].end()) {
            edges_[v].push_back(u);
        }
    }
}


void Graph::add_vertex(vector<int>& vertex){
    /*This function will add a row within the edges_ vector and connect it to all vertices given
    Parameters:
        - vector<int>& vertex: the row to be added
    Returns:
        - Nothing
    
    */
   Graph::num_vertices_++;
   Graph::edges_.push_back(vertex);
   int new_vertex_index = num_vertices_;
   for(int i = 0; i < vertex.size(); i++){
        int index = vertex.at(i);
        //add new vertex to edge pairs so that it is bidirectional
        Graph::edges_.at(index).push_back(num_vertices_);
   }

    
}

void Graph::disconnect_vertex(int v) {
    /* Disconnects a vertex from all other vertices.
    Parameters:
        - int v: Vertex to disconnect.
    Returns:
        - Nothing. Removes all edges associated with the vertex.
    */
    for (int i = 0; i < edges_.size(); ++i) {
        edges_.at(i).erase(remove(edges_.at(i).begin(), edges_.at(i).end(), v), edges_.at(i).end());
    }
    edges_.at(v).clear();
}


void Graph::delete_edges(vector<pair<int, int>>& pairs) {
    /* Deletes edges specified by a vector of vertex pairs.
    Parameters:
        - vector<pair<int, int>>& pairs: List of vertex pairs to disconnect.
    Returns:
        - Nothing. Removes the specified edges from the Graph.
    */
    for (auto& pair : pairs) {
        int u = pair.first;
        int v = pair.second;
        edges_.at(u).erase(remove(edges_.at(u).begin(), edges_.at(u).end(), v), edges_.at(u).end());
        edges_.at(v).erase(remove(edges_.at(v).begin(), edges_.at(v).end(), u), edges_.at(v).end());
    }
}

int Graph::max_degree() {
    /* Finds the maximum degree (number of edges) of any vertex in the Graph.
    Parameters:
        - None
    Returns:
        - int: The maximum degree of any vertex.
    */
    int max_deg = 0;
    for (int i = 0; i < edges_.size(); ++i) {
        int current_degree = edges_.at(i).size();
        if (current_degree > max_deg) {
            max_deg = current_degree;
        }
    }
    return max_deg;
}

bool Graph::is_adjacent(int v1, int v2) {
    /* Checks if there is an edge between v1 and v2.
    Parameters:
        - v1, v2: Vertices to check for adjacency.
    Returns:
        - true if there is an edge between v1 and v2, false otherwise.
    */
    const vector<int>& row = Graph::edges_.at(v1);
    return std::find(row.begin(), row.end(), v2) != row.end();
}


bool Graph::is_two_path(int v1, int v2) {
    /* Checks if there is a path of length 1 or 2 between v1 and v2.
    Parameters:
        - v1, v2: Start and end vertices.
    Returns:
        - true if there is a direct edge (length 1) or a path of length 2 from v1 to v2, false otherwise.
    */
    if (is_adjacent(v1, v2)) {
        return true; // Direct edge exists
    }

    // Check for two-path using neighbors of v1
    for (int neighbor : Graph::edges_.at(v1)) {
        if (is_adjacent(neighbor, v2)) {
            return true; // Path exists through a neighbor
        }
    }

    return false; // No valid path of length 1 or 2
}
