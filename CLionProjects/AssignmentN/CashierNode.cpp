//
// Created by Enc on 29.11.2022.
//
#ifndef CashierNode_cpp
#define CashierNode_cpp


#include <string>

struct CashierNode{
    bool isworking=false;

    int worktime=0;// work which need to be completed at this time
    int sumofworktime=0;//The cashierNode's all works
    int timeofprecostumer=0;//this holds costumer's leave time we find new costumer waiting in queue time= precostleavetime-(new costumer arrive time);
    std::string name;
    CashierNode* next= nullptr;
    void setwork(int x){
        worktime=x;
        sumofworktime+=x;
    }
    void decreaseworktime(int x){
        worktime-=x;
        if(worktime<=0){
            worktime=0;
            isworking= false;
        }
    }
};






#endif
