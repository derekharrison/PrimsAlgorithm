/*
 * prim.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <stdio.h>

#include "../inc/prim.hpp"

const float inf = 3e+8; //Arbitrary large value

void prim::primalgo() {
    float temp;
    int js, ks;
    this->total_path_mst = 0.0;

    for(int i = 0; i < this->size_graph - 1; ++i) {
        temp = inf;
        for(int j = 0; j < this->num_of_edges; ++j) {
            int start_vertex = this->edge_set[j].start_vertex;
            int end_vertex = this->edge_set[j].end_vertex;
            float weight = this->edge_set[j].weight;
            if(this->node_visited[start_vertex] && !this->node_visited[end_vertex] && temp > weight) {
                temp = weight;
                js = start_vertex;
                ks = end_vertex;
            }
        }
        this->edges_in_mst[js][ks] = true;
        this->node_visited[ks] = true;
        this->total_path_mst += temp;
    }
}

float prim::get_size_mst() {
    return this->total_path_mst;
}

void prim::min_spanning_tree() {
    printf("\nMinimum spanning tree:\n\n");

    for(int edge = 0; edge < this->num_of_edges; ++edge) {
        int j = this->edge_set[edge].start_vertex;
        int k = this->edge_set[edge].end_vertex;
        if(this->edges_in_mst[j][k] == true) {
            printf("went from %i to %i, length: %f\n", j, k, this->edge_set[edge].weight);
        }
    }
}

void prim::get_edges_in_mst(bool** edges_in_mst) {
    for(int i = 0; i < this->size_graph; ++i)
        for(int j = 0; j < this->size_graph; ++j) {
        	edges_in_mst[i][j] = this->edges_in_mst[i][j];
        }
}
