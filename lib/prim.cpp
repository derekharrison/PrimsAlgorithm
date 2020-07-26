/*
 * prim.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include "../inc/prim.hpp"

const float inf = 3e+8; //Arbitrary large value

void prim::primalgo() {
    float temp;
    pathcounter = 0.0;
    int js, ks;

    for(int i = 0; i < size_graph - 1; ++i) {
        temp = inf;
        for(int j = 0; j < size_graph; ++j) {
            if(arrP[j]) {
                for(int k = 0; k < size_graph; ++k) {
                    if(get_bool_val(j, k) && temp > get_weight_val(j, k) && !arrP[k]) {
                        temp = get_weight_val(j, k);
                        js = j;
                        ks = k;
                    }
                }
            }
        }
        visited[js][ks] = true;
        arrP[ks] = true;
        pathcounter += temp;
    }
}

float prim::minpath() {
    return pathcounter;
}

void prim::min_spanning_tree() {
    printf("\nMinimum spanning tree:\n\n");

    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j)
            if(visited[i][j] == true) {
                printf("went from %i to %i, length: %f\n", i, j, weight2d[i][j]);
            }
}
