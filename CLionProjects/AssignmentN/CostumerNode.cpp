//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef CostumerNode_cpp
#define CostumerNode_cpp
#include <iostream>

using std::cout;



struct CostumerNode{
    int price,arrivetime,ordertime,brewtime,outofcashier,outofbarista;
   // bool isout=false;
    CostumerNode* next= nullptr;
    int id;
    int Wait_CashierQueue=0;
    int Wait_BaristaQueue=0;
    void setoutoutbarista(int x){
        Wait_BaristaQueue=x;
        outofbarista=outofcashier+Wait_BaristaQueue+brewtime;
    }
    void setoutofCashier(int x){
        if(x<0)x=0;
        Wait_CashierQueue=x;
        outofcashier=arrivetime+Wait_CashierQueue+ordertime;
        std::cout<<"\nOut of Cashier: "<<outofcashier<<std::endl;
        std::cout<<"\nOut of Cashier for Wait_CashierQueue: "<<Wait_CashierQueue<<std::endl;

    }



};






#endif

