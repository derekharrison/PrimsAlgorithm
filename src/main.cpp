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

const char* file_name = "./src/data_5.txt";

int main(int argc, char* argv[])
{
    int size_graph, num_edges;
    float size_mst;
    std::vector <edge> edge_set;

    /* Retrieve graph data from file */
    read_data(size_graph, num_edges, edge_set, file_name);

    /* Allocate memory edges in mst */
    bool** edges_in_mst = bool2D(size_graph);

    /* Creating prim object myg */
    prim myg(edge_set, size_graph, num_edges);

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

    return 0;
}



