/*
 * prim.hpp
 *
 *  Created on: Jul 26, 2020
 *      Author: d-w-h
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "functions.hpp"
#include "graph.hpp"

class prim : public graph {
private:
    bool *arrP;
    float pathcounter;

public:
    prim() {
        arrP = new bool[size_graph];
        pathcounter = 0.0;
        init(arrP, size_graph);
    }
    ~prim() {
        delete [] arrP;
    }

    void primalgo();
    float minpath();
    void min_spanning_tree();
};

#endif /* PRIM_HPP_ */
