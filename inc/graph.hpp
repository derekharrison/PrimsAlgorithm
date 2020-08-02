/*
 * graph.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>

class graph {
protected:
    bool **adj_matrix;
    float **weight2d;
    int size_graph;

public:
    graph(bool** adj_mat, float** weight, int size_graph);
    ~graph();

    bool get_bool_val(int i, int j);
    float get_weight_val(int i, int j);
    void print_adj_matrix();
    void print_weight_matrix();
};

#endif /* GRAPH_HPP_ */
