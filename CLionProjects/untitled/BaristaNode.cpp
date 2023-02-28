//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef BaristaNode_cpp
#define BaristaNode_cpp


#include <string>

struct BaristaNode{
public:
    bool isworking=false;
    double worktime;// work which need to be completed at this time
    double sumofworktime=0;//The cashierNode's all works
    double outofBarista=0;// when costumer go out of barista
    double timeofprecostumer=0;//this holds costumer's leave time we find new costumer waiting in queue time= precostleavetime-(new costumer arrive time);
    std::string name;// barista name
    BaristaNode* next= nullptr;
    void setWorkTime(double x){
        sumofworktime+=x;
        worktime=x;
        isworking= true;
    }
    void setOutOfBarista(double x){
        outofBarista=x;
        isworking= false;
    }
    void decreaseworktime(double x){
        worktime-=x;
        if(worktime<=0){
          //  sumofworktime+=(-x); it maybe reason
            worktime=0;
            isworking= false;
        }
    }




};






#endif
