//
// Created by Enc on 29.11.2022.
//
#ifndef CashierQueue_cpp
#define CashierQueue_cpp
#include <iostream>
#include <string>
#include "CashierNode.cpp"

using std::string;
using std::cout;
using std::endl;
typedef CashierNode node;
struct CashierQueue{
private:
    string printstr;
    node* temp1;
public:

    node* head= nullptr;
    node* last= nullptr;
    double prevnodearrivetime=0;

    void enqueue(node* node){
        if(head== nullptr){
            last=node;
            head=node;
            return;
        }
        last=  last->next=node;

    }
    node* getNode(){
        temp1=head;

        while(temp1!= nullptr){
            if(!temp1->isworking)return  temp1;
            temp1=temp1->next;
        }
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
    void createCashierQueue(int n){//this method create n length queue
        head=new node;
        head->name="Cashier 0";
        head->id=0;
        temp1=head;
        node* newnode;
        int i=1;
        while(i<n){
            newnode=new node;
            newnode->name="Cashier "+ std::to_string(i);
            newnode->id=i;
            temp1->next=newnode;
            temp1=newnode;
            i++;

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


    double findmintime(){
        temp1=head;
        double min=-1;
        while (temp1!= nullptr){

            if(temp1->worktime<min||min==-1)min=temp1->worktime;
            temp1=temp1->next;
        }
        return min;
    }
    node* skiptime(double x){
        temp1=head;
        node* returnnode= nullptr;
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


    void skiptimeforinitial(double i) {
        temp1=head;
        while (temp1!= nullptr){
            temp1->decreaseworktime(i);
            temp1=temp1->next;
        }
    }
};







#endif
