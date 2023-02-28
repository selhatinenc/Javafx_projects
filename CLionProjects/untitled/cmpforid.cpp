//
// Created by enc on 1.12.2022.
//
#ifndef cmpforid_cpp
#define cmpforid_cpp



#include "CostumerNode.cpp"
class cmpforid{
public:
    bool operator()(CostumerNode const* a,CostumerNode const* b){
                return    a->id <        b->id;
    }
};



#endif