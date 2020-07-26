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

    /* Executing prims algorithm */
    myg.primalgo();

    /* printing data */
    std::cout << std::endl << "MST length: "
              << myg.minpath() << std::endl;

    myg.min_spanning_tree();

    return 0;
}



