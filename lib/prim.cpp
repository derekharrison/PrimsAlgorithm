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
        for(int j = 0; j < this->size_graph; ++j) {
            if(this->node_visited[j]) {
                for(int k = 0; k < this->size_graph; ++k) {
                    if(get_bool_val(j, k) && temp > get_weight_val(j, k) && !this->node_visited[k]) {
                        temp = get_weight_val(j, k);
                        js = j;
                        ks = k;
                    }
                }
            }
        }
        this->edges_in_mst[js][ks] = true;
        this->node_visited[ks] = true;
        this->total_path_mst += temp;
    }
}

float prim::get_size_mst() {
    return total_path_mst;
}

void prim::min_spanning_tree() {
    printf("\nMinimum spanning tree:\n\n");

    for(int i = 0; i < this->size_graph; ++i)
        for(int j = 0; j < this->size_graph; ++j)
            if(this->edges_in_mst[i][j] == true) {
                printf("went from %i to %i, length: %f\n", i, j, this->weight_mat[i][j]);
            }
}

void prim::get_edges_in_mst(bool** edges_in_mst) {
    for(int i = 0; i < this->size_graph; ++i)
        for(int j = 0; j < this->size_graph; ++j) {
        	edges_in_mst[i][j] = this->edges_in_mst[i][j];
        }
}
