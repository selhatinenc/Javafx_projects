#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "FlatNode.cpp"
//
// Created by as_as on 11.11.2022.
//
class FlatNodeDoubleLinkedList {



public:
     FlatNode* head=NULL;
     FlatNode* last=NULL;
     FlatNode* temp1=NULL;
     int sizeoflist=0;
     int max_BandWidth;
     int current_sum_Bandwidth=0;
     void Add_Flat_Node(int index,FlatNode* node){
          if(head== NULL) Add_FlattoHead(node);
          else if(index>=sizeoflist) Append_NewNode(node);
          else{
              temp1=head;
              while (index>1&&temp1->nextnode!= NULL){
                  index--;
                  temp1=temp1->nextnode;
              }
              if(index<1)Add_FlattoHead(node);
              else if(temp1->nextnode== NULL)Append_NewNode(node);
              else{
                  sizeoflist++;
                  temp1->nextnode->prevnode= node;
                  node->nextnode=temp1->nextnode;
                  node->prevnode=temp1;
                  temp1->nextnode=node;
              }
          }



     }
     FlatNode* CreateNewNode(int Flat_Id,int BandWith){
         FlatNode* newnode=new FlatNode();
         newnode->flat_id=Flat_Id;
         newnode->initial_bandwith=BandWith;
         return newnode;

     }
     void CreateNewNode(int Flat_Id,int BandWith,int index){
        FlatNode* newnode=new FlatNode();
        newnode->flat_id=Flat_Id;

        int temp1=BandWith;
         if(temp1+current_sum_Bandwidth>max_BandWidth){
            newnode->initial_bandwith=max_BandWidth-current_sum_Bandwidth;
            current_sum_Bandwidth=max_BandWidth;
         }
         else{
             newnode->initial_bandwith=temp1;

             current_sum_Bandwidth+=temp1;
         }
        Add_Flat_Node(index,newnode);

    }

     void Add_beforenode(FlatNode* node,FlatNode* Addnode){
        sizeoflist++;
         current_sum_Bandwidth+=Addnode->initial_bandwith;
         if(head->flat_id==node->flat_id) Add_FlattoHead(Addnode);
         else {

             Addnode->nextnode=node;

             node->prevnode->nextnode=Addnode;
        //     std::cout<<"hy ";

             Addnode->prevnode=node->prevnode;
             node->prevnode=Addnode;
           //  std::cout<<"hy";

             /////// perfect design
         }
     }
     FlatNode* get_Node(int flat_Id){
         temp1=head;
         while (temp1!= NULL) {
             if(temp1->flat_id==flat_Id) return  temp1;
             temp1=temp1->nextnode;
         }
         return NULL;
     }
     void Add_FlattoHead(FlatNode* node){
         sizeoflist++;
         if(head== NULL){

             head=node;
             last=node;
        //   std:: cout<< std::to_string(head->flat_id)+" ";

         }
         else{

           //  std::cout<<"here";
             node->nextnode=head;
             head->prevnode=node;
             head=node;
           //  std:: cout<< std::to_string(head->flat_id)+" ";

         }
     }
     void Append_NewNode(FlatNode * node){
         sizeoflist++;

         if(head== NULL) Add_FlattoHead(node);


         else{
             last->nextnode= node;
             node->prevnode=last;
             last=node;
         }
     }
        std::string Displays_Nodes(std::string str){
         if(head== NULL) str="";
         else{
             temp1=head;
             while (temp1!= NULL){
                 str+=" Flat"+std::to_string(temp1->flat_id)+"("+ std::to_string(temp1->initial_bandwith)+")\t ";
                 temp1=temp1->nextnode;
               // std::cout<<str;
             }
         }
            return str;
     }
     int MergeTwoList(FlatNode *headnode,FlatNode* lastnode,int size){
         sizeoflist+=size;
      //   std::cout<<"merge func \n";

         if(head==NULL){ head=headnode; last=headnode;  return 0;}
         last->nextnode= headnode;
         headnode->prevnode=last;
      //   if(head->nextnode==NULL)         std::cout<<" here ";
        // headnode->nextnode=lastnode->nextnode;
         last=lastnode;
         return 1;
     }
     int MakeFlatEmpty(int Flat_Id){
         temp1= get_Node(Flat_Id);
         if(temp1==NULL)return 0;
         temp1->initial_bandwith=0;
         return 1;
     }


     FlatNode* TakeawayFlatNode(int x){// x equals node's flat_id that wanted

         if(head== NULL) return NULL;

         else if(x==head->flat_id) {
             max_BandWidth-=head->initial_bandwith;
             current_sum_Bandwidth-=head->initial_bandwith;
             sizeoflist--;
            temp1 = head;
            if(head->nextnode!= NULL){
                head = head->nextnode;
                head->prevnode= NULL;

            }
            else{
                head= NULL;
                last=NULL;
            }
                temp1->nextnode= NULL;
                temp1->prevnode= NULL;
               // std::cout<< std::to_string(temp1->flat_id);
                 return temp1;
        }
        else if(x== last->flat_id){
             std::cout<<"Take away -last x:" <<x<<std::endl;
             current_sum_Bandwidth-=last->initial_bandwith;
             max_BandWidth-=last->initial_bandwith;

             sizeoflist--;
            last->prevnode->nextnode= NULL;
            temp1=last;
            last=last->prevnode;
            temp1->prevnode= NULL;
            temp1->nextnode= NULL;
             return temp1;
        } else{
             std::cout<<"Take away -else x:" <<x<<std::endl;

             //std::cout<<" here ";
            temp1=head->nextnode;
            if(temp1!=NULL)
             while (temp1->nextnode!= NULL){
                 if(temp1->flat_id==x){
                     current_sum_Bandwidth-=temp1->initial_bandwith;
                     max_BandWidth-=temp1->initial_bandwith;

                     sizeoflist--;
                     temp1->prevnode->nextnode=temp1->nextnode;
                     temp1->nextnode->prevnode=temp1->prevnode;
                     temp1->nextnode=NULL;
                     temp1->prevnode=NULL;

                     return temp1;
                 }

                 temp1=temp1->nextnode;


             }
        }






        return NULL;
     };

};
