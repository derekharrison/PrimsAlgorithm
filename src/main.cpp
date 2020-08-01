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

#include "../inc/prim.hpp"


int main(int argc, char* argv[])
{
    /* Creating prim object myg. Note: constructor reads file containing graph data */
    prim myg;

    /* Allocate memory for edges in msp */
    int size_graph = myg.get_size_graph();
    bool** edges_in_mst = bool2D(size_graph);

    /* Executing prims algorithm */
    myg.primalgo();

    /* Getting data */
    myg.get_edges_in_mst(edges_in_mst);
    float size_mst = myg.get_size_mst();

    /* Printing data */
    std::cout << "MST length: "
              << size_mst << std::endl;

    myg.min_spanning_tree();

    return 0;
}



