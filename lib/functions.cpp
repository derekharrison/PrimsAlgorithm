/*
 * functions.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#include "../inc/functions.hpp"

void init(bool* arrP, int size_graph)
{
    arrP[0] = true;

    for(int i = 1; i < size_graph; ++i)
        arrP[i] = false;
}
