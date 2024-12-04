/* A Graph class that uses a dense representation.
This class treats the graph as directed and weighted.
The 2D vector will hold either 0 (meaning no edge) or 
non-0, meaning a directed edge with that weight.

Andrew Shallue, Lab10, CS229, Data Structures, Fall 2024
*/
// Header file for the DenseGraph class
// Provided by Professor Shallue

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::tuple;
using std::pair;
using std::get;

class DenseGraph{
    private:
        int num_vertices_;
        vector<vector<double>> edges_;

    public:
        // graph with no vertices and no edges
        DenseGraph();
        // graph with n vertices and no edges
        DenseGraph(int n);
        // make a graph complete, i.e. add all possible edges in both directions
        // all edges will have the given input weight
        void make_complete(double weight);
        // make a graph a cycle, i.e. edges (0,1), (1,2), (2,3) ...
        // all edges will have the given input weight
        void make_cycle(double weight);

        // Add edges from a vector.  Directed, so (0,1) means (0,1) only
        // If the edge already exists, update the weight.  The third entry is the weight
        void add_edges(vector< tuple<int, int, double> >& new_edges);
        // add a vertex, and connect it to the vertices given in neighbors
        void add_vertex(vector<pair<int, double>>& neighbors);
        // disconnect a vertex, meaning all edges to it and from it are removed
        void disconnect_vertex(int v);
        // delete edges.  If the given edge isn't in the graph, ignore it.
        void delete_edges(vector< pair<int, int> >& remove_edges);

        // return the out-degree of the given vertex
        int out_degree(int v);
        // calculate the max out-degree among all vertices
        int max_out_degree();
        // return weight of an edge from v1 to v2.  If no edge, return 0.
        double adjacent_cost(int v1, int v2);
        // return the total path cost of the given path.  If the path is broken, return 0;
        double path_cost(vector< pair<int, int> >& path);
        // return the minimum total weight among all paths of length at most 2
        double min_two_path(int v1, int v2);
        

        // list all vertices and edges, one vertex per line
        void print();
        
};

#endif