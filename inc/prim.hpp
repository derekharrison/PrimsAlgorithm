/*
 * prim.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include <vector>

#include "functions.hpp"
#include "graph.hpp"

class prim : public graph {
private:
    bool *node_visited, **edges_in_mst;
    float total_path_mst;

public:
    prim(std::vector <edge> edge_set, int size_graph) : graph(edge_set, size_graph) {
    	this->node_visited = new bool[size_graph];
    	this->total_path_mst = 0.0;
    	init_node_visited(this->node_visited, size_graph);
        this->edges_in_mst = bool2D(size_graph);
        init_edges_in_mst(this->edges_in_mst, size_graph);
    }
    ~prim() {
    	delete_bool2D(this->edges_in_mst, this->size_graph);
        delete [] this->node_visited;
    }

    void primalgo();
    void min_spanning_tree();
    float get_size_mst();
    void get_edges_in_mst(bool** edges_in_mst);
};

#endif /* PRIM_HPP_ */
