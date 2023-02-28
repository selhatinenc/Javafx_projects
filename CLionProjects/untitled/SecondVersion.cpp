//
// Created by Enc on 2.12.2022.
//
#ifndef SecondVersion_cpp
#define SecondVersion_cpp
#include "BaristaQueue.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include "CostumerQueue.cpp"
#include "cmp.cpp"
using std::string;
using std::cout;
using std::endl;
class  SecondVersion
{


public:



    void print_End_OfBarista(CostumerQueue *pQueue, BaristaQueue *baristaQueue, std::vector<double> *pVector) {
        BaristaNode* baristaNode=baristaQueue->head;
        while (baristaNode!= nullptr){
            //  cout<<"Barista node sum of work time:"<<baristaNode->sumofworktime<<std::endl;
            //     cout<<"util of barista:"<<baristaNode->sumofworktime/max<<std::endl;
            pVector->push_back(baristaNode->sumofworktime);
            baristaNode=baristaNode->next;
        }

        CostumerNode* temp1=pQueue->head;
        double max=0;
        while (temp1!= nullptr){
         //   pVector->push_back(temp1->outofbarista-temp1->arrivetime);
           // cout<<"Costumer Out of barista:"<<temp1->outofbarista-temp1->arrivetime <<" id:"<<temp1->id<<endl;
            if(temp1->outofbarista>max)max=temp1->outofbarista;

            temp1=temp1->next;
        }
        pVector->push_back(max);


        //     cout<<"Total running time:"<<max<<endl;
        //double max=0;

    }
    int maxlengthofbarista=0;
    SecondVersion(CostumerQueue *Costumerqueue_BeforeBQ, int BarisataQueue_length, std::vector<double> *pVector,CostumerQueue* ALL_AfterBaristaCostumerQueue) {
        BaristaQueue* baristaQueue=new BaristaQueue;
       // cout<<"Barista length:"<<BarisataQueue_length<<endl;
        baristaQueue->createBaristaQueue(BarisataQueue_length);
     //   cout<<baristaQueue->toString();




        Go_to_Barista(baristaQueue,Costumerqueue_BeforeBQ,ALL_AfterBaristaCostumerQueue);
        print_End_OfBarista(ALL_AfterBaristaCostumerQueue, baristaQueue, pVector);
        pVector->push_back(maxlengthofbarista);
     //   cout<<"Max of barista:"<<maxlengthofbarista<<endl;
    }

    //  recursive_FullFill(baristaQueue,Costumerqueue_BeforeBQ,ALL_AfterBaristaCostumerQueue);
    //sendCostumerToBarista(Costumerqueue_BeforeBQ,ALL_AfterBaristaCostumerQueue,BarisataQueue_length,baristaQueue);


    void   Go_to_Barista(BaristaQueue* baristaQueue, CostumerQueue* costqueue, CostumerQueue* All_after)
 {
     CostumerNode* temp1;
     CostumerNode* costnode;
     BaristaNode* bNode;
     BaristaNode* ansnode;
     while (!costqueue->isEmpty()){
      costnode= nullptr;
      bNode=baristaQueue->head;

     ansnode=bNode;
     double min=-1;

     while(bNode!= nullptr){
           // cout<<"Sum of work time:"<<bNode->sumofworktime<< endl;
         if(bNode->sumofworktime<min||min==-1){
             min=bNode->sumofworktime;
             ansnode=bNode;
         }
         bNode=bNode->next;

     }
         bNode=ansnode;
        // cout<<"Barista that is free:"<<ansnode->name<<std::endl;

     if(bNode->sumofworktime==0)costnode=costqueue->dequeue();
     else{
         double maxprice=-1;
         temp1=costqueue->head;
         int max=0;
         //cout<<"Cost queue head"<<temp1->price;
         while (temp1!= nullptr){
           //  cout<<"temp id : "<<temp1->id<<endl;

         //   cout<<"hooooooooooooo"<<endl;
             if(temp1->outofcashier<=bNode->timeofprecostumer){
                 max++;
                 if(temp1->price>maxprice){
                     maxprice=temp1->price;
                     costnode=temp1;
                     //cout<<"temp id : "<<temp1->id<<endl;
                 }

             }
             else {
                 //cout<<"here"<<endl;
                 break;
             }
             temp1=temp1->next;



         }
         if(max>maxlengthofbarista)maxlengthofbarista=max;

        // cout<<"costnode id : "<<costnode->id<<endl;

         if(costnode== nullptr)
             costnode=costqueue->dequeue();
         else
        costqueue->removeNode(costnode);
       //  cout<<"\nHasdere 1";
     }

    //cout<<"Heresad 1";
     All_after->enqueueNode(costnode);
   //  cout<<"CostNode brew time:"<<costnode->brewtime<<endl;
    // cout<<"bNodesumofworktime:"<<bNode->sumofworktime<<endl;
     bNode->sumofworktime+=costnode->brewtime;
     costnode->setoutofbarista(bNode->timeofprecostumer-costnode->outofcashier);//find time while waiting in queue
     bNode->timeofprecostumer=costnode->outofbarista;


 }


 }


};
#endif

/*
 *  void recursive_FullFill(BaristaQueue *BQueue, CostumerQueue *CostQueue_BeforeBQ, CostumerQueue *ALL_AfterBaristaCostumerQueue) {
        BaristaNode* n=BQueue->getnodeB();
        CostumerNode* costumerNode=CostQueue_BeforeBQ->dequeue();

        if(n== nullptr||costumerNode== nullptr) return ;

        //cout<<"Recursive fullfill is working \n";
        if(BQueue->prevnodearrivetime==-1)
            BQueue->skiptimeforinitial(0);

        else
            BQueue->skiptimeforinitial(costumerNode->outofcashier-BQueue->prevnodearrivetime);



        BQueue->prevnodearrivetime=costumerNode->outofcashier;
        costumerNode->setoutofbarista(n->timeofprecostumer- costumerNode->outofcashier);

        ALL_AfterBaristaCostumerQueue->enqueueNode(costumerNode);

        n->timeofprecostumer=costumerNode->outofcashier;
        n->isworking= true;
        n->setWorkTime(costumerNode->brewtime);

        recursive_FullFill(BQueue,CostQueue_BeforeBQ,ALL_AfterBaristaCostumerQueue);
    }


    int  min=-1;
     while(bNode!= nullptr)
     {
         if(bNode->sumofworktime<min||min==-1){
             bNode->sumofworktime+=costnode.brewtime;
             costnode.setoutofbarista(0);
             bNode->timeofprecostumer=costnode.outofbarista;
             return;
         }
         bNode=bNode->next;
     }



        sendCostumerToBarista(CostumerQueue *costqueue_beforeCash, CostumerQueue *costqueue_aftercash, int sizeofbarista,
                          BaristaQueue *baristaqueue) {


    }
 */