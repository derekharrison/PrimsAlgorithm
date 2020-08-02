/*
 * graph.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <iostream>

#include "../inc/functions.hpp"
#include "../inc/graph.hpp"

graph::graph(bool** adj_mat, float** weight, int size_graph) {
    this->size_graph = size_graph;
    this->adj_mat = bool2D(size_graph);
    this->weight_mat = float2D(size_graph);
    set_adj_mat(this->adj_mat, adj_mat, size_graph);
    set_weight_mat(this->weight_mat, weight, size_graph);
}

graph::~graph() {
	delete_bool2D(this->adj_mat, this->size_graph);
	delete_float2D(this->weight_mat, this->size_graph);
}

bool graph::get_bool_val(int i, int j) {
    return this->adj_mat[i][j];
}

float graph::get_weight_val(int i, int j) {
    return this->weight_mat[i][j];
}

void graph::print_adj_mat() {
    for(int i = 0; i < this->size_graph; ++i) {
        for(int j = 0; j < this->size_graph; ++j)
            printf("adj_mat[%i][%i]: %i\t", i, j, this->adj_mat[i][j]);
        printf("\n");
    }
}

void graph::print_weight_matrix() {
    for(int i = 0; i < this->size_graph; ++i)
        for(int j = 0; j < this->size_graph; ++j)
            printf("weight_mat[%i][%i]: %f\t", i, j, this->weight_mat[i][j]);
    printf("\n");
}
