/*
 * graph.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <iostream>
#include <vector>

#include "../inc/functions.hpp"
#include "../inc/graph.hpp"
#include "../inc/user_types.hpp"

graph::graph(std::vector <edge> edge_set, int size_graph) {
    this->size_graph = size_graph;
    set_edges(this->edge_set, edge_set);
}

