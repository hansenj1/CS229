/* A Graph class that uses a sparse representation.
This class treats the graph as bidirectional and unweighted.

Jack Hansen and Jules Weick, Lab10, CS229, Data Structures, November 2024
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::tuple;
using std::pair;

class Graph {
    private:
        int num_vertices_; // Number of vertices in the graph
        vector<vector<int>> edges_; // Adjacency list representation of edges

    public:
        // Default constructor to create a Graph with no vertices or edges
        Graph();

        // Constructor to create a Graph with n vertices, initialized with no edges
        Graph(int n);

        // Print function to display each vertex and its connected edges
        void print();

        // Function to transform the graph into a complete graph (all possible edges added)
        void make_complete();

        // Function to transform the graph into a cycle (vertices connected in a circular manner)
        void make_cycle();

        // Function to add all edge pairs from a given vector of pairs
        void add_edges(vector<pair<int, int>>& pairs);

        // Function to create a new vertex connected to a given set of vertices
        void add_vertex(vector<int>& vertex);

        // Function to disconnect all edges of the given vertex
        void disconnect_vertex(int v);

        // Function to delete specific edge pairs from the graph
        void delete_edges(vector<pair<int, int>>& pairs);

        // Returns the maximum degree (number of edges) of any vertex in the graph
        int max_degree();

        // Checks if an edge exists between two vertices
        bool is_adjacent(int v1, int v2);

        // Checks if there exists a path of length one or two between two vertices
        bool is_two_path(int v1, int v2);
};

#endif