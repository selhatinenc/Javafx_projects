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
    void enqueue(double price,double arrivetime,double ordertime,double brewtime){
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
        //    cout<<"head id:"<<head->id<<std::endl;
            temp =head;
            head=head->next;
            //  delete(temp);
            temp->next= nullptr;
           // cout<<"prev head id:"<<temp->id<<std::endl;

        //    cout<<"head id:"<<head->id<<std::endl;
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
           // printstr+= std::to_string(temp->id)+" ("+std::to_string(temp->arrivetime)+")\t";
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


    void removeNode(CostumerNode *pNode) {
    if(pNode==head)dequeue();
    else{
        //cout<<"\nhead cost:"<<head->id;

        //cout<<"\ncurr cost:"<<pNode->id;

        temp=head;
        while(temp->next!=pNode){
            //cout<<"\ncurr in search cost:"<<temp->id;

            temp=temp->next;
        }
        //cout<<"\ntemp that choosed cost:"<<temp->id;
      //  //cout<<"\ntemp.next that choosed cost:"<<temp->next->next->id;

        //  while(temp->next!=pNode&&temp!= nullptr)temp=temp->next;
        temp->next=temp->next->next;
        pNode->next= nullptr;
        //if(temp== nullptr)cout<<"null"<<std::endl;
    }
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