//
// Created by as_as on 16.12.2022.
//
#ifndef LLRB_NODE_cpp
#define LLRB_NODE_cpp
#include "string"



struct LLRB_NODE{
    std::string Name;
    BST_NODE* Right_Child= nullptr;
    BST_NODE* Left_Child= nullptr;
    AVL_TREE_SECONDKEY* TREE_OF_SECOND=new AVL_TREE_SECONDKEY;



};


#endi