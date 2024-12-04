/* main file for Lab 10 with test code
Andrew Shallue, CS229, Fall 2024
*/

#include <iostream>
#include "Lab10Part1.h"
#include "Graph.h"
#include "DenseGraph.h"

void part2_test(){
    Graph G1 = Graph(5);
    vector<pair<int, int>> three_edges;
    pair<int, int> t1{0, 2};  three_edges.push_back(t1);
    pair<int, int> t2{2, 3};  three_edges.push_back(t2);
    pair<int, int> t3{2, 4};  three_edges.push_back(t3);
    G1.add_edges(three_edges);
    std::cout << "Graph with edges (0,2), (2,3), and (2,4):\n";
    G1.print();
    std::cout << "\n";

    // with a cycle, every vertex v is connected to two others: v+1 and v-1
    G1.make_cycle();
    G1.print();
    std::cout << "\n";

    // should see every vertex connected to the other 4
    G1.make_complete();
    G1.print();
    std::cout << "\n";

    // remove vertex 2 from the complete graph
    G1.disconnect_vertex(2);
    std::cout << "After disconnecting 2:\n";
    G1.print();
    std::cout << "\n";

    // add new vertex, connect to 0, 2, 4
    vector<int> connections = {0, 2, 4};
    G1.add_vertex(connections);
    std::cout << "Adding vertex 5, connected to 0, 2, 4:\n";
    G1.print();
    std::cout << "\n";

    // remove the 0-1-3 triangle
    vector<pair<int, int>> triangle_edges;
    pair<int, int> tr1{0, 1};  triangle_edges.push_back(tr1);
    pair<int, int> tr2{1, 3};  triangle_edges.push_back(tr2);
    pair<int, int> tr3{3, 0};  triangle_edges.push_back(tr3);
    G1.delete_edges(triangle_edges);
    std::cout << "after removing (0,1), (1,3), (3,0):\n";
    G1.print();
    std::cout << "\n";

    // new graph with 6 vertices using add edges, from the notes
    Graph G2 = Graph(6);
    std::cout << "Max degree of an empty graph should be 0: " << G2.max_degree() << "\n";

    vector<pair<int, int>> note_edges;
    pair<int, int> e1{0, 2};  note_edges.push_back(e1);
    pair<int, int> e2{2, 3};  note_edges.push_back(e2);
    pair<int, int> e3{3, 4};  note_edges.push_back(e3);
    pair<int, int> e4{3, 5};  note_edges.push_back(e4);
    pair<int, int> e5{3, 1};  note_edges.push_back(e5);
    pair<int, int> e6{4, 1};  note_edges.push_back(e6);
    pair<int, int> e7{5, 1};  note_edges.push_back(e7);

    G2.add_edges(note_edges);
    G2.print();
    std::cout << "After adding edges, max degree should be 4: " << G2.max_degree() << "\n";

    // 1 is adjacent to 3, 4, 5 but not adjacent to 0, 1, 2
    if(G2.is_adjacent(1, 3) && G2.is_adjacent(1, 4) && G2.is_adjacent(1, 5) && 
       !G2.is_adjacent(1, 1) && !G2.is_adjacent(1, 0) && !G2.is_adjacent(1, 2)){
        std::cout << "is_adjacent passed all tests on G2\n";
    }else{
        std::cout << "is_adjacent failed at least one test on G2\n";
    }

    // 0 is two-path adjacent to 2 and 3, not to 1, 4, 5
    if(G2.is_two_path(0, 2) && G2.is_two_path(0, 3) && !G2.is_two_path(0, 5) && !G2.is_two_path(0, 1)){
        std::cout << "is_two_path passed all tests on G2\n";
    }else{
        std::cout << "is_two_path failed at least one test on G2\n";
    }
}

void part3_test(){
    DenseGraph G1 = DenseGraph();
    G1.print();
    std::cout << "\n";

    DenseGraph G2 = DenseGraph(6);
    G2.print();
    std::cout << "\n";

    // complete graph
    double weight = 1;
    G2.make_complete(weight);
    std::cout << "Complete graph with weight " << weight << ": \n";
    G2.print();
    std::cout << "\n";

    // // cycle graph
    weight = 3.7;
    G2.make_cycle(weight);
    std::cout << "Cycle graph with weight " << weight << ": \n";
    G2.print();
    std::cout << "\n";

    // // add a new vertex to the cycle that points at 1 and 4
    vector<pair<int, double>> new_edges;
    pair<int, double> e1{1, 0.5};  new_edges.push_back(e1);
    pair<int, double> e2{4, 0.8};  new_edges.push_back(e2);
    G2.add_vertex(new_edges);
    std::cout << "added a new vertex to the cycle: \n";
    G2.print();
    std::cout << "\n";

    // remove a vertex and some edges from the cycle graph
    G2.disconnect_vertex(4);
    vector<pair<int, int>> remove_edges;
    pair<int, int> r1{0, 1};  remove_edges.push_back(r1);
    pair<int, int> r2{5, 0};  remove_edges.push_back(r2);
    G2.delete_edges(remove_edges);
    std::cout << "Cycle with vertex 4 removed and edges in and out of 0: \n";
    G2.print();
    std::cout << "\n";

    // // create the directed graph from the notes
    DenseGraph G3 = DenseGraph(6);
    vector<tuple<int, int, double>> notes_edges;
    tuple<int, int, double> n1{0, 1, 21};  notes_edges.push_back(n1);
    tuple<int, int, double> n2{1, 2, 11};  notes_edges.push_back(n2);
    tuple<int, int, double> n3{1, 3, 15};  notes_edges.push_back(n3);
    tuple<int, int, double> n4{3, 2, 8};  notes_edges.push_back(n4);
    tuple<int, int, double> n5{5, 1, 28};  notes_edges.push_back(n5);
    tuple<int, int, double> n6{5, 2, 43};  notes_edges.push_back(n6);
    tuple<int, int, double> n7{5, 4, 21};  notes_edges.push_back(n7);
    tuple<int, int, double> n8{4, 3, 10};  notes_edges.push_back(n8);
    G3.add_edges(notes_edges);
    std::cout << "Directed, weighted graph from the notes: \n";
    G3.print();
    std::cout << "\n";

    // testing out_degree
    if(G3.out_degree(0) == 1 && G3.out_degree(2) == 0 && G3.out_degree(5) == 3){
        std::cout << "Out degree is working on graph G3\n";
    }else{
        std::cout << "Out degree failed for at least one vertex of G3\n";
    }
    // testing max_out_degree
    // G2 is currently causing this to fail. G1 and G3 return the expected values.
    if(G1.max_out_degree() == 0 && G2.max_out_degree() == 1 && G3.max_out_degree() == 3){
        std::cout << "Max_out_degree correct for G1, G2, and G3\n";
    }else{
        std::cout << "Something wrong with max_out_degree\n";
    }
    
    // testing adj_cost and path cost
    if(G3.adjacent_cost(0, 1) == 21 && G3.adjacent_cost(0, 5) == 0 &&
       G3.adjacent_cost(1, 0) == 0 && G3.adjacent_cost(5, 2) == 43){
        std::cout << "adjacent_cost passed all tests on G3\n";
    }else{
        std::cout << "adjacent_cost failed at least one test\n";
    }
    vector<pair<int, int>> path1;
    pair<int, int> d1{0, 1};  path1.push_back(d1);
    pair<int, int> d2{1, 3};  path1.push_back(d2);
    pair<int, int> d3{3, 2};  path1.push_back(d3);
    vector<pair<int, int>> path2 = path1;
    pair<int, int> d4{2, 1};  path2.push_back(d4);
    path2.push_back(d2);

    // path1 has a total cost of 44, path2 is invalid so 0
    if(G3.path_cost(path1) == 44 && G3.path_cost(path2) == 0){
        std::cout << "path_cost passes all tests\n";
    }else{
        std::cout << "path_cost failed at least one test\n";
    }
    
    // testing min_path_cost.  Looking at graph in the Notes.
    // There are two paths from 5 to 3, cheapest is 31
    if(G3.min_two_path(5, 3) == 31 && G3.min_two_path(1, 2) == 11){
        std::cout << "min_two_path passes all tests\n";
    }else{
        std::cout << "min_two_path failed at least one test\n";
    }
}

int main(){
    std::cout << "Hello from Graph world\n";
    lab10_part1_main();
    // part2_test();
    // part3_test();
}