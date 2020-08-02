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
    bool *node_visited;
    float pathcounter;

public:
    prim(bool** adj_mat, float** weight, int size_graph) : graph(adj_mat, weight, size_graph) {
    	node_visited = new bool[size_graph];
        pathcounter = 0.0;
        init(node_visited, size_graph);
    }
    ~prim() {
        delete [] node_visited;
    }

    void primalgo();
    void min_spanning_tree();
    float get_size_mst();
};

#endif /* PRIM_HPP_ */
