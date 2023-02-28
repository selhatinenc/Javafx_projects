//
// Created by as_as on 16.12.2022.
//
#ifndef AVL_SECOND_NODE_cpp
#define AVL_SECOND_NODE_cpp
#include "string"



struct AVL_SECOND_NODE{
    std::string product_name;
    int price;
    AVL_SECOND_NODE* Right_Child= nullptr;
    AVL_SECOND_NODE* Left_Child= nullptr;
    int height;

};


#endif