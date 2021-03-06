/*
 * prim.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include <iostream>

#include "../inc/functions.hpp"
#include "../inc/prim.hpp"
#include "../inc/user_types.hpp"

const float inf = 3e+8; //Arbitrary large value

prim::prim(std::vector <edge> edge_set, int size_graph){
    this->size_graph = size_graph;
    this->edge_set = edge_set;
    this->node_visited = new bool[size_graph];
    init_node_visited(this->node_visited, size_graph);
    this->edges_in_mst = bool2D(size_graph);
    init_edges_in_mst(this->edges_in_mst, size_graph);

}

prim::~prim() {
    delete_bool2D(this->edges_in_mst, this->size_graph);
    delete [] this->node_visited;
}

void prim::primalgo() {
    float temp;
    int js = 0;
    int ks = 0;
    int it_counter = 0;
    bool unvisited_is_empty = check_unvisited(this->node_visited, this->size_graph);
    while(unvisited_is_empty == false) {
        temp = inf;
        for(unsigned int i = 0; i < this->edge_set.size(); ++i) {
            int start_vertex = this->edge_set[i].start_vertex;
            int end_vertex = this->edge_set[i].end_vertex;
            float weight = this->edge_set[i].weight;
            if(this->node_visited[start_vertex] && !this->node_visited[end_vertex] && temp > weight) {
                temp = weight;
                js = start_vertex;
                ks = end_vertex;
            }
        }

        this->edges_in_mst[js][ks] = true;
        this->node_visited[ks] = true;
        unvisited_is_empty = check_unvisited(this->node_visited, this->size_graph);
        it_counter++;
        if(it_counter > this->size_graph + 2) {
            printf("Entered infinite loop, some nodes could not be reached\n");
            break;
        }
    }
}

void prim::get_edges_in_mst(bool** edges_in_mst) {
    for(int i = 0; i < this->size_graph; ++i)
        for(int j = 0; j < this->size_graph; ++j) {
            edges_in_mst[i][j] = this->edges_in_mst[i][j];
        }
}
