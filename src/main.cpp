/*
 * prim.cpp
 *
 *  Created on: 6 mrt. 2016
 *      Author: dharrison
 *
 *      An implementation of Prims algorithm for computing a
 *      minimum spanning tree of a given graph.
 */


#include <iostream>
#include <vector>

#include "../inc/functions.hpp"
#include "../inc/prim.hpp"
#include "../inc/user_types.hpp"

int main(int argc, char* argv[])
{
    int size_graph = 5;
    float size_mst = 0.0;
    float density_graph = 0.5;
    bool** edges_in_mst = bool2D(size_graph);
    bool **adj_mat = bool2D(size_graph);
    float **weight_mat = float2D(size_graph);

    /* Populate adjancy and weight matrices with random data*/
    populate_adj_and_weight(adj_mat, weight_mat, size_graph, density_graph);

    /* Creating prim object myg */
    prim myg(adj_mat, weight_mat, size_graph);

    /* Executing prims algorithm */
    myg.primalgo();

    /* Getting data */
    myg.get_edges_in_mst(edges_in_mst);
    size_mst = myg.get_size_mst();

    /* Printing data */
    myg.print_adj_mat();
    myg.print_weight_matrix();

    std::cout << "MST length: "
              << size_mst << std::endl;

    myg.min_spanning_tree();

    /* Free data */
    delete_bool2D(edges_in_mst, size_graph);
    delete_bool2D(adj_mat, size_graph);
    delete_float2D(weight_mat, size_graph);

    return 0;
}



