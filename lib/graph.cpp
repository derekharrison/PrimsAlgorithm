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

const char* fname = "./src/data_2.txt";

template <class T>
void initarray2D(T **p, const int size);

template <class T>
void free2D(T **p, int nodes);

graph::graph() {
    graph::read_data();
    adj_matrix = bool2D(size_graph);
    weight2d = float2D(size_graph);
    visited = bool2D(size_graph);
    initarray2D(adj_matrix, size_graph);
    initarray2D(weight2d, size_graph);
    initarray2D(visited, size_graph);
    graph::adj_and_weight();
}

graph::~graph() {
    free2D(adj_matrix, size_graph);
    free2D(visited, size_graph);
    free2D(weight2d, size_graph);
}

void graph::read_data() {
    int start_vertex, end_vertex;
    int counter = 0;
    float weight_edge;

    file.open(fname);

    if(!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }

    file >> size_graph;

    while(file >> start_vertex >> end_vertex >> weight_edge) {
        start_v.push_back(start_vertex);
        end_v.push_back(end_vertex);
        weight.push_back(weight_edge);
        counter++;
    }

    file.close();

    sizefile = counter;
}

void graph::adj_and_weight() {
    int ic, jc;

    for(int i = 0; i < sizefile; ++i) {
        ic = start_v[i];
        jc = end_v[i];
        weight2d[ic][jc] = weight[i];
        adj_matrix[ic][jc] = true;
    }
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

template <class T>
void initarray2D(T **p, const int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            p[i][j] = 0;
}

template <class T>
void free2D(T **p, int size) {
    for(int i = 0; i < size; ++i)
            delete [] p[i];

    delete [] p;
}
