/*
 * prim.cpp
 *
 *  Created on: 6 mrt. 2016
 *      Author: dharrison
 *
 *      An implementation of Prims algorithm for computing minimum spanning tree of a given graph
 *      Derek W. Harrison
 *
 *      Solution to assignment 3, course C++ for C programmers
 */


#include <iostream>
#include <vector>

#include "../inc/functions.hpp"
#include "../inc/prim.hpp"
#include "../inc/user_types.hpp"

const char* file_name = "./src/data_3.txt";

int main(int argc, char* argv[])
{
    int size_graph, sizefile;
    float size_mst;
    std::vector <edge> edge_set;

    /* Retrieve graph data from file */
    read_data(size_graph, sizefile, edge_set, file_name);

    /* Allocate memory for adjancy matrix, weight matrix and edges in mst */
    bool** edges_in_mst = bool2D(size_graph);
    bool **adj_matrix = bool2D(size_graph);
    float **weight_mat = float2D(size_graph);

    /* Populate adjancy and weight matrices */
    adj_and_weight(sizefile, edge_set, weight_mat, adj_matrix, size_graph);

    /* Creating prim object myg */
    prim myg(adj_matrix, weight_mat, size_graph);

    /* Executing prims algorithm */
    myg.primalgo();

    /* Getting data */
    myg.get_edges_in_mst(edges_in_mst);
    size_mst = myg.get_size_mst();

    /* Printing data */
    std::cout << "MST length: "
              << size_mst << std::endl;

    myg.min_spanning_tree();

    /* Free data */
    delete_bool2D(edges_in_mst, size_graph);
    delete_bool2D(adj_matrix, size_graph);
    delete_float2D(weight_mat, size_graph);

    return 0;
}



