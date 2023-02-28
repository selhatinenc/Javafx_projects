//
//
//
// Created by Enc on 29.11.2022.
//
#ifndef CostumerQueue_cpp
#define CostumerQueue_cpp
#include "CostumerNode.cpp"

#include <iostream>


#include <string>



//typedef CostumerCostumerNode CostumerNode;
struct CostumerQueue{
private:
    CostumerNode* temp;
    std::string printstr="";
public:
    CostumerNode* last= nullptr;
    CostumerNode* head= nullptr;
    int CostumerNodeid=0;

    void enqueueNode(CostumerNode* enq){

        if(head== nullptr){


            head=enq;
            last=enq;
            return;
        }
        last->next=enq;
        last=enq;
    }
  void enqueue(int price,int arrivetime,int ordertime,int brewtime){
        auto* enq=new CostumerNode;
        enq->price=price;
        enq->id=CostumerNodeid;
        enq->arrivetime=arrivetime;
        enq->ordertime=ordertime;
        enq->brewtime=brewtime;
        CostumerNodeid++;

      enqueueNode(enq);

    }
    CostumerNode* dequeue(){
        if(head!= nullptr){
            temp =head;
            head=head->next;
          //  delete(temp);
            return temp;


        }
        return nullptr;


    }

 bool isEmpty(){
     if(head== nullptr) return true;
     return false;
    }
    std::string  toString(){
        printstr="";
        temp=head;
        while (temp!= nullptr){
            printstr+= std::to_string(temp->id)+" ("+std::to_string(temp->price)+")\t";
            temp=temp->next;
        }
        return printstr;

    }
    std::string  toStringforarrivetime(){
        printstr="";
        temp=head;
        while (temp!= nullptr){
            printstr+= std::to_string(temp->id)+" ("+std::to_string(temp->arrivetime)+")\t";
            temp=temp->next;
        }
        return printstr;

    }
    std::string  toStringforOrderTime(){
        printstr="";
        temp=head;
        while (temp!= nullptr){
            printstr+= std::to_string(temp->id)+" ("+std::to_string(temp->ordertime)+")\t";
            temp=temp->next;
        }
        return printstr;

    }
    void clonequeue(CostumerNode* headofcopy,CostumerNode* lastofcopy){
      head=headofcopy;
      last=lastofcopy;
  }


};






#endif

/*
 * it delete from end
 *     if(head->next== nullptr){
                delete(head);
                head= nullptr;
                return;
            }
            temp=head;
            while (temp->next!=last)temp=temp->next;
            //   std:://cout<<last->id;
            delete(temp->next);
            last=temp;
            temp->next= nullptr;
 */