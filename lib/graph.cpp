/*
 * graph.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <stdio.h>
#include <iostream>

#include "../inc/functions.hpp"
#include "../inc/graph.hpp"

graph::graph(bool** adj_mat, float** weight, int size_graph) {
    this->size_graph = size_graph;
    adj_matrix = bool2D(size_graph);
    weight2d = float2D(size_graph);
    visited = bool2D(size_graph);
    init_visited(visited, size_graph);
    set_adj_mat(this->adj_matrix, adj_mat, size_graph);
    set_weight_mat(this->weight2d, weight, size_graph);
}

graph::~graph() {
	delete_bool2D(adj_matrix, size_graph);
	delete_bool2D(visited, size_graph);
	delete_float2D(weight2d, size_graph);
}

bool graph::get_bool_val(int i, int j) {
    return adj_matrix[i][j];
}

float graph::get_weight_val(int i, int j) {
    return weight2d[i][j];
}

void graph::print_adj_matrix() {
    for(int i = 0; i < size_graph; ++i) {
        for(int j = 0; j < size_graph; ++j)
            printf("adj_matrix[%i][%i]: %i\t", i, j, adj_matrix[i][j]);
        printf("\n");
    }
}

void graph::print_weight_matrix() {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j)
            printf("weight2d[%i][%i]: %f\t", i, j, weight2d[i][j]);
    printf("\n");
}

void graph::get_edges_in_mst(bool** visited) {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
            visited[i][j] = this->visited[i][j];
        }
}
