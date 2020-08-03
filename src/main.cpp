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
    int size_graph = 6;
    float density_graph = 0.5;
    bool** edges_in_mst = bool2D(size_graph);
    bool** adj_mat = bool2D(size_graph);
    float** weight_mat = float2D(size_graph);
    std::vector <edge> edge_set;

    /* Populate adjancy and weight matrices with random data*/
    populate_adj_and_weight(adj_mat, weight_mat, size_graph, density_graph);

    /* Make edge vector */
    make_edge_set(adj_mat, weight_mat, edge_set, size_graph);

    /* Creating prim object myg */
    prim myg(edge_set, size_graph);

    /* Executing prims algorithm */
    myg.primalgo();

    /* Getting data */
    myg.get_edges_in_mst(edges_in_mst);
    float size_mst = myg.get_size_mst();

    /* Printing data */
    print_adj_mat(adj_mat, size_graph);
    print_weight_mat(weight_mat, size_graph);

    std::cout << "MST length: "
              << size_mst << std::endl;

    print_min_spanning_tree(edges_in_mst, weight_mat, size_graph);

    /* Free data */
    delete_bool2D(edges_in_mst, size_graph);
    delete_bool2D(adj_mat, size_graph);
    delete_float2D(weight_mat, size_graph);

    return 0;
}



