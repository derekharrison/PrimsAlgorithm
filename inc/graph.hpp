/*
 * graph.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <fstream>
#include <vector>

class graph {
protected:
    bool **adj_matrix, **visited;
    float **weight2d;
    int size_graph;
    int sizefile;
    std::vector <int> start_v;
    std::vector <int> end_v;
    std::vector <float> weight;
    std::fstream file;

public:
    graph();
    ~graph();

    void adj_and_weight(const int size_graph);
    bool get_bool_val(int i, int j);
    float get_weight_val(int i, int j);
    void print_adj_matrix();
    void print_weight_matrix();
    void read_data();
};

#endif /* GRAPH_HPP_ */
