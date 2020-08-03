/*
 * functions.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <fstream>
#include <iostream>
#include <time.h>

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

void set_edge_set(std::vector <edge>& edge_set, std::vector <edge> edge_set_ref) {
    for(unsigned int i = 0; i < edge_set_ref.size(); ++i) {
        edge_set[i] = edge_set_ref[i];
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

void populate_adj_and_weight(bool** adj_mat, float** weight_mat, int size_graph, float density) {
    init_adj_mat(adj_mat, size_graph);
    init_weight_mat(weight_mat, size_graph);

    srand(time(NULL));
    float max_weight = 10;
    for(int i = 0; i < size_graph; ++i)
        for(int j = i; j < size_graph; ++j) {
            float rand_num = (float) rand() / RAND_MAX;
            if(i != j) {
                adj_mat[j][i] = adj_mat[i][j] = rand_num > (1 - density);
                if(adj_mat[i][j] == true) {
                    rand_num = (float) rand() / RAND_MAX;
                    weight_mat[j][i] = weight_mat[i][j] = max_weight * rand_num;
                }
            }
        }
}

void make_edge_set(bool** adj_mat, float** weight_mat, std::vector <edge>& edge_set, int size_graph) {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
            if(adj_mat[i][j] == true) {
                edge_set.push_back({i, j, weight_mat[i][j]});
            }
        }
}

void print_min_spanning_tree(bool** edges_in_mst, float** weight_mat, int size_graph) {
    printf("\nMinimum spanning tree:\n\n");

    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j)
            if(edges_in_mst[i][j] == true) {
                printf("went from %i to %i, length: %f\n", i, j, weight_mat[i][j]);
            }
}

void print_adj_mat(bool** adj_mat, int size_graph) {
    printf("\n Adjancy matrix:\n");

    for(int i = 0; i < size_graph; ++i) {
        for(int j = 0; j < size_graph; ++j) {
            printf("(%i,%i): %d ", i, j, adj_mat[i][j]);
        }
        printf("\n");
    }

}

void print_weight_mat(float** weight_mat, int size_graph) {
    printf("\n Weight matrix:\n");

    for(int i = 0; i < size_graph; ++i) {
        for(int j = 0; j < size_graph; ++j) {
            printf("(%i,%i): %.2f ", i, j, weight_mat[i][j]);
        }
        printf("\n");
    }

}

bool check_unvisited(bool* node_visited, int size_graph) {
    for(int i = 0; i < size_graph; ++i) {
        if(node_visited[i] == false) {
            return false;
        }
    }

    return true;
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
