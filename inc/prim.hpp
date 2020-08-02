/*
 * prim.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "functions.hpp"
#include "graph.hpp"

class prim : public graph {
private:
    bool *node_visited, **edges_in_mst;
    float pathcounter;

public:
    prim(bool** adj_mat, float** weight, int size_graph) : graph(adj_mat, weight, size_graph) {
    	this->node_visited = new bool[size_graph];
    	this->pathcounter = 0.0;
        init(this->node_visited, size_graph);
        this->edges_in_mst = bool2D(size_graph);
        init_visited(this->edges_in_mst, size_graph);
    }
    ~prim() {
    	delete_bool2D(this->edges_in_mst, size_graph);
        delete [] this->node_visited;
    }

    void primalgo();
    void min_spanning_tree();
    float get_size_mst();
    void get_edges_in_mst(bool** edges_in_mst);
};

#endif /* PRIM_HPP_ */
