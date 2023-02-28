//
// Created by enc on 1.12.2022.
//
#ifndef cmp_cpp
#define cmp_cpp



#include "CostumerNode.cpp"
class cmp{
public:
    bool operator()(CostumerNode const* a,CostumerNode const* b){
        return a->outofcashier<b->outofcashier;
    }
};



#endif