/*
 * functions.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include <vector>

#include "../inc/user_types.hpp"

void init_node_visited(bool* node_visited, int size_graph);
void set_adj_mat(bool** adj_mat, bool** adj_mat_ref, int size);
void set_weight_mat(float** weight_mat, float** weight_mat_ref, int size);
void set_edge_set(std::vector <edge>& edge_set, std::vector <edge> edge_set_ref);
void init_adj_mat(bool** adj_mat, int size);
void init_weight_mat(float** weight_mat, int size);
void init_edges_in_mst(bool** visited, int size);
void populate_adj_and_weight(bool** adj_mat, float** weight_mat, int size_graph, float density);
void make_edge_set(bool** adj_mat, float** weight_mat, std::vector <edge>& edge_set, int size_graph);
void print_min_spanning_tree(bool** edges_in_mst, float** weight_mat, int size_graph);
void print_adj_mat(bool** adj_mat, int size_graph);
void print_weight_mat(float** weight_mat, int size_graph);
bool check_unvisited(bool* node_visited, int size_graph);
bool** bool2D(const int size);
float** float2D(const int size);
void delete_bool2D(bool **p, int size);
void delete_float2D(float **p, int size);

#endif /* FUNCTIONS_HPP_ */
