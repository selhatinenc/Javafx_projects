//
// Created by as_as on 13.11.2022.
//
#pragma once4
#include "ApartmentNode.cpp"
#include <string>
#include <vector>
#include <algorithm>

class ApartmentLinkedList{

public:
    typedef  ApartmentNode Node;

 //   Node* node; no need
    Node* head=NULL;
    Node* temp1;
    int findMax_BandWidth(){
        int sum=0;
        temp1=head;
        while (temp1){
            sum+=temp1->Max_BandWith;
            temp1=temp1->nextNode;
        }
        return sum;
    }
    void Add_to_Head(Node *pNode) {
        if (head != NULL) {
            pNode->nextNode=head;
          //  std::cout<<"here";
            head=pNode;
        }
        else {
            head = pNode;
        }

    }

    void Add_Before(Node* node, Node* beforeNode){
        if(node==head)Add_to_Head(beforeNode);
        else{
            temp1=head;
          //  std::cout<<node->ApartmentName+" "+ beforeNode->ApartmentName;
            std::cout<<node->ApartmentName+" (before) "+ beforeNode->ApartmentName+"  \n ";

            while(temp1->nextNode!=node) temp1=temp1->nextNode;
            beforeNode->nextNode=node;
            temp1->nextNode=beforeNode;

        }


    }
    void Add_After(Node* node, Node* AfterNode){
        temp1=head;
       // std::cout<<node->ApartmentName+" (after) "+ AfterNode->ApartmentName+"  \n ";

        while (temp1){
            if(temp1==node){
                AfterNode->nextNode= node->nextNode;
                node->nextNode=AfterNode;
                break;
            }
            temp1=temp1->nextNode;

        }

    }
    void Add_Before(std::string node,std::string beforenode){
        Add_Before(getNode(node), getNode(beforenode));
    }
    void Add_After(std::string node,std::string afternode){
        Add_After(getNode(node), getNode(afternode));
    }
    std::string removeSpaces(std::string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());

        return str;
    }
    std::string remove_spaces(const std::string &s)
    {
        int last = s.size() - 1;
        while (last >= 0 && s[last] == ' ')
            --last;
        return s.substr(0, last + 1);
    }
    Node* getNode(std::string str) {
        temp1=head;
      //  std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        //str.erase(end_pos, str.end());
       str= str.substr(0,1);
         //std::cout<<"x"+str+"x\n";


        while (temp1!=NULL){

            if(str==temp1->ApartmentName){

                return temp1;
            }
            temp1=temp1->nextNode;
        }
        return NULL;


    }

    ApartmentNode Remove_Apartment(std::string ApName){
        std::cout<<" here ";
     Node* removeNode=getNode(ApName);
     std::cout<<" Remove Node: "+removeNode->ApartmentName+"\n";
     if(removeNode==NULL);
     else {
         if(removeNode==head) head=head->nextNode;
         else{


                temp1=head;
                  while (temp1->nextNode!=NULL) {
                      if(temp1->nextNode==removeNode) break;  //dont forget here //It works
                      temp1 = temp1->nextNode;

                  }
                  temp1->nextNode=temp1->nextNode->nextNode;




         }
         delete(removeNode);
     }

    }
    void Remove_Apartment(Node* removeNode){

        if(removeNode==NULL);
        else {
            if(removeNode->ApartmentName==head->ApartmentName) head=head->nextNode;
            else{

                temp1=head;
                while (temp1->nextNode!=NULL) {
                    if(temp1->nextNode==removeNode) break;  //dont forget here
                    temp1 = temp1->nextNode;

                }
           //     std::cout<<temp1->nextNode->ApartmentName;
              //  std::cout<<removeNode->ApartmentName;

                temp1->nextNode=temp1->nextNode->nextNode;




            }
            delete(removeNode);
        }

    }
    void MergeTwoList(const std::string& apart1, const std::string& apart2){
       // std::cout<<" Merge two list"+apart1+ " "+apart2+ "\n";

        Node* ap1= getNode(apart1);

        Node* ap2= getNode(apart2);
        ap1->Max_BandWith+=ap2->Max_BandWith;
        ap1->ApartmantDLL->max_BandWidth=ap1->Max_BandWith;
      //  std::cout<<ap2->ApartmentName;

        if(ap2->ApartmantDLL->sizeoflist!=0){

        ap1->ApartmantDLL->MergeTwoList(ap2->ApartmantDLL->head,ap2->ApartmantDLL->last,ap2->ApartmantDLL->sizeoflist);

        Remove_Apartment(ap2);
    }
        else{
            Remove_Apartment(ap2);
        }

    }

    ApartmentNode* CreateApartmentNode(std::string apname,int max_bandwith){
        ApartmentNode* newNode=new ApartmentNode();
        newNode->ApartmentName=apname;
        newNode->Max_BandWith=max_bandwith;
        newNode->ApartmantDLL->max_BandWidth=max_bandwith;
        return newNode;
    }
    std::string toString(std::string str){
        temp1=head;
        while (temp1!=NULL){
            str+=temp1->ApartmentName+"("+ std::to_string(temp1->Max_BandWith)+") "+ temp1->ApartmantDLL->Displays_Nodes("")+"\n";
            temp1=temp1->nextNode;

        }
       // std::cout<<str;
        if(str=="") return "NULL";
        return  str+"\n";
    }
    std::string SumOfBandwith(){
        temp1=head;
        int sum=0;
        while (temp1!=NULL){
            sum+=temp1->Max_BandWith;
            temp1=temp1->nextNode;
        }
        return "sum of bandwith: "+ std::to_string(sum)+"\n";
    }
    int MakeFLatEmpty(std::string apName,int Flat_Id){
        temp1= getNode(apName);
        if(temp1==NULL) return 0;
        temp1->ApartmantDLL->MakeFlatEmpty(Flat_Id);
        return 1;
    }
    int relocate_flats_to_same_apartment(std::string apName,int MainFlat_Id,std::vector<int> BeforeFlats)

    {
        //  Controled function
        temp1= getNode(apName);
        if(temp1==NULL) return 0;
        FlatNode* flatNode=temp1->ApartmantDLL->get_Node(MainFlat_Id);
        FlatNode* BefFLatNode;

        for (int i = 0; i <BeforeFlats.size() ; ++i) {
            Node* temp2=head;
            while(temp2!=NULL){

                BefFLatNode= temp2->ApartmantDLL->TakeawayFlatNode(BeforeFlats[i]);
               // std::cout<<"relocate_flats_to_same_apartment control!! "+temp2->ApartmentName <<std::endl;

                if (NULL == BefFLatNode) {
                    temp2 = temp2->nextNode;

                } else {
                    //std::cout << "relocate_flats_to_same_apartment control!!  id:" << BefFLatNode->flat_id << std::endl;
                    temp2->Max_BandWith-=BefFLatNode->initial_bandwith;
                    break;
                }
            }
            if(BefFLatNode!=NULL){
                temp1->ApartmantDLL->Add_beforenode(flatNode,BefFLatNode);
                temp1->Max_BandWith+=BefFLatNode->initial_bandwith;
                temp1->ApartmantDLL->max_BandWidth =temp1->Max_BandWith;
                std::cout << "relocate_flats_to_same_apartment control!!  max_band:" << temp1->Max_BandWith<< std::endl;

            }
        }
        return 1;


    }


};
