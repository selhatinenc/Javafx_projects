//
// Created by as_as on 16.12.2022.
//
#ifndef BST_NODE_cpp
#define BST_NODE_cpp
#include "string"
#include "AVL_TREE_SECONDKEY.cpp"



struct BST_NODE{
    std::string Name;
    BST_NODE* Right_Child= nullptr;
    BST_NODE* Left_Child= nullptr;
    AVL_TREE_SECONDKEY* TREE_OF_SECOND=new AVL_TREE_SECONDKEY;



};


#endif