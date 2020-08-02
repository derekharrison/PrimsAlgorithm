/*
 * functions.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <fstream>
#include <iostream>

#include "../inc/functions.hpp"

void init_node_visited(bool* node_visited, int size_graph) {
	node_visited[0] = true;

    for(int i = 1; i < size_graph; ++i)
    	node_visited[i] = false;
}

void set_adj_mat(bool** adj_mat, bool** adj_mat_ref, int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j) {
            adj_mat[i][j] = adj_mat_ref[i][j];
        }
}

void set_weight_mat(float** weight_mat, float** weight_mat_ref, int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j) {
            weight_mat[i][j] = weight_mat_ref[i][j];
        }
}

void init_adj_mat(bool** adj_mat, int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j) {
            adj_mat[i][j] = false;
        }
}

void init_weight_mat(float** weight_mat, int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j) {
            weight_mat[i][j] = 0.0;
        }
}

void init_edges_in_mst(bool** visited, int size) {
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j) {
        	visited[i][j] = false;
        }
}

void adj_and_weight(int sizefile, std::vector <edge> edge_set, float** weight2d, bool** adj_matrix, int size_graph) {
    int ic, jc;

    init_adj_mat(adj_matrix, size_graph);
    init_weight_mat(weight2d, size_graph);

    for(int i = 0; i < sizefile; ++i) {
        ic = edge_set[i].start_vertex;
        jc = edge_set[i].end_vertex;
        weight2d[ic][jc] = edge_set[i].weight;
        adj_matrix[ic][jc] = true;
    }
}

void read_data(int& size_graph, int& sizefile, std::vector <edge>& edge_set, const char* file_name) {
    int start_vertex, end_vertex;
    int counter = 0;
    float weight_edge;
    std::fstream file;

    file.open(file_name);

    if(!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }

    file >> size_graph;

    while(file >> start_vertex >> end_vertex >> weight_edge) {
        edge_set.push_back({start_vertex, end_vertex, weight_edge});
        counter++;
    }

    file.close();

    sizefile = counter;
}

bool** bool2D(const int size) {
    bool** p = new bool*[size];

    for(int i = 0; i < size; ++i)
        p[i] = new bool[size];

    return p;
}

float** float2D(const int size) {
    float** p = new float*[size];

    for(int i = 0; i < size; ++i)
        p[i] = new float[size];

    return p;
}

void delete_bool2D(bool **p, int size) {
    for(int i = 0; i < size; ++i)
            delete [] p[i];

    delete [] p;
}

void delete_float2D(float **p, int size) {
    for(int i = 0; i < size; ++i)
            delete [] p[i];

    delete [] p;
}
