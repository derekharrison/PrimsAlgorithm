/*
 * functions.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include "../inc/functions.hpp"

void init(bool* arrP, int size_graph) {
    arrP[0] = true;

    for(int i = 1; i < size_graph; ++i)
        arrP[i] = false;
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
