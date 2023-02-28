//
// Created by Enc on 29.11.2022.
//
#ifndef CashierNode_cpp
#define CashierNode_cpp

#include "CostumerQueue.cpp"
#include <string>

struct CashierNode{
    bool isworking=false;

    double worktime=0;// work which need to be completed at this time
    double sumofworktime=0;//The cashierNode's all works
    double timeofprecostumer=0;//this holds costumer's leave time we find new costumer waiting in queue time= precostleavetime-(new costumer arrive time);
    CostumerQueue* selfcostqueue;
    std::string name;
    int id;
    CashierNode* next= nullptr;
    void setwork(double x){
        worktime=x;
        sumofworktime+=x;
    }
    void decreaseworktime(double x){
        worktime-=x;
        if(worktime<=0){
            sumofworktime+=(-worktime);
            worktime=0;
            isworking= false;
        }
    }
};






#endif
