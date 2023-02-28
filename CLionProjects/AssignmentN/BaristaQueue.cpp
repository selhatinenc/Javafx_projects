//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef BaristaQueue_cpp
#define BaristaQueue_cpp
#include "BaristaNode.cpp"


#include <string>
typedef BaristaNode nodeB;// type defintion
struct BaristaQueue{
    nodeB* head= nullptr;
    nodeB* last= nullptr;
    nodeB* temp1;
    void enqueue(nodeB* node){
        if(head== nullptr){
            last=node;
            head=node;
            return;
        }
        last=  last->next=node;

    }
    nodeB* getnodeB(){
        temp1=head;
        while(temp1!= nullptr&&!temp1->isworking)temp1=temp1->next;
        return temp1;
    }

};






#endif
