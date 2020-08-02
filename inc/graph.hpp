/*
 * graph.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

class graph {
protected:
    bool **adj_mat;
    float **weight_mat;
    int size_graph;

public:
    graph(bool** adj_mat, float** weight, int size_graph);
    ~graph();

    bool is_connected(int i, int j);
    float get_weight(int i, int j);
    void print_adj_mat();
    void print_weight_matrix();
};

#endif /* GRAPH_HPP_ */
