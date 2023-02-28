//
// Created by as_as on 13.11.2022.
//
#pragma once
#include "FlatNodeDoubleLinkedList.cpp"

class  ApartmentNode{

public:
    FlatNodeDoubleLinkedList* ApartmantDLL=new FlatNodeDoubleLinkedList();
    int Max_BandWith=0;
    std::string ApartmentName;
    ApartmentNode* nextNode=NULL;


};
