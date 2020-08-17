/*
 * prim.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include <vector>

#include "user_types.hpp"

class prim {
private:
    bool *node_visited, **edges_in_mst;
    std::vector <edge> edge_set;
    int size_graph;

public:
    prim(std::vector <edge> edge_set, int size_graph);
    ~prim();

    void primalgo();
    void get_edges_in_mst(bool** edges_in_mst);
};

#endif /* PRIM_HPP_ */
