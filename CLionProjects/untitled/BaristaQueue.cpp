//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef BaristaQueue_cpp
#define BaristaQueue_cpp
#include "BaristaNode.cpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
typedef BaristaNode nodeB;// type defintion
struct BaristaQueue{
private:
    string printstr;
    nodeB* temp1;

public:

    double prevnodearrivetime= -1;

    nodeB* head= nullptr;
    nodeB* last= nullptr;
    void enqueue(nodeB* node){
        if(head== nullptr){
            last=node;
            head=node;
            return;
        }
        last->next=node;
        last=node;
    }
    nodeB* getnodeB(){
        temp1=head;
        while(temp1!= nullptr&&!temp1->isworking)temp1=temp1->next;
        return temp1;
    }
    bool Notwork(){
        temp1=head;
        while(temp1!= nullptr ){
            if(!temp1->isworking)return true;
            temp1=temp1->next;
        }
        return false;

    }

    void createBaristaQueue(int i) {
        nodeB* newnode;
        int index=0;
        while (index<i){
            newnode=new nodeB;
            newnode->name="Barista "+ std::to_string(index);
            enqueue(newnode);
            index++;

        }
    }
    string toString(){
        printstr="";
        temp1=head;
        while(temp1!= nullptr){
            printstr+=temp1->name+"\t";
            temp1=temp1->next;
        }
        printstr+="\n";
        return printstr;
    }
    int findmintime(){
        temp1=head;
        int min=-1;
        while (temp1!= nullptr){

            if(temp1->worktime<min||min==-1)min=temp1->worktime;
            temp1=temp1->next;
        }
        return min;
    }

    nodeB* skiptime(int x){
        temp1=head;
        nodeB* returnnode= nullptr;
        bool control= true;
        //cout<<x<<endl;

        while (temp1!= nullptr){
            //cout<<temp1->worktime<<endl;
            temp1->decreaseworktime(x);
            //cout<<temp1->worktime<<endl;
            if(temp1->worktime==0&&control){
                control= false;
                returnnode=temp1;
            }



            temp1=temp1->next;

        }
        return returnnode;
    }
    void skiptimeforinitial(int i) {

        temp1=head;
        while (temp1!= nullptr){
            temp1->decreaseworktime(i);
            temp1=temp1->next;
        }
    }
};





#endif
