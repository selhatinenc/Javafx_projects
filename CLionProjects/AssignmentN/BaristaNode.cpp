//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef BaristaNode_cpp
#define BaristaNode_cpp


#include <string>

struct BaristaNode{
    bool isworking=false;
    int worktime;// work which need to be completed at this time
    int sumofworktime=0;//The cashierNode's all works
    std::string name;
    BaristaNode* next= nullptr;

};






#endif
