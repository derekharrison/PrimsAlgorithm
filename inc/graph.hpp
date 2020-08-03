/*
 * graph.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>

#include "user_types.hpp"

class graph {
protected:
    std::vector <edge> edge_set;
    int size_graph;

public:
    graph(std::vector <edge> edge_set, int size_graph);
};

#endif /* GRAPH_HPP_ */
