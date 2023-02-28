//
// Created by as_as on 16.12.2022.
//
//
// Created by as_as on 16.12.2022.
//
#ifndef AVL_TREE_SECONDKEY_cpp
#define AVL_TREE_SECONDKEY_cpp
#include "string"
#include "AVL_SECOND_NODE.cpp"

#include <iostream>
#include <cstring>
#include <utility>


using std::string;
using std::cout;
using std::endl;

struct AVL_TREE_SECONDKEY{
private:
    AVL_SECOND_NODE* root= nullptr;
    AVL_SECOND_NODE* temp;// for temp task

    void Change_Item(string productname, AVL_SECOND_NODE* &pNode,int price) {
        if(!pNode){
            //cout<<""<<endl;
            return;
        }
        if(strcmp(productname.c_str(),pNode->product_name.c_str())<0)Change_Item(productname,pNode->Left_Child,price);
        else if(strcmp(productname.c_str(),pNode->product_name.c_str())>0)Change_Item(productname,pNode->Right_Child,price);
        else pNode->price=price;


    }
    string Print_item(const string& productname, AVL_SECOND_NODE* &pNode) {
      //  cout<<"whre\n";
        if(!pNode){
            return "\t{}\n";
        }
        if(strcmp(productname.c_str(),pNode->product_name.c_str())<0)return Print_item(productname,pNode->Left_Child);
        else if(strcmp(productname.c_str(),pNode->product_name.c_str())>0)return Print_item(productname,pNode->Right_Child);
        else return "\t\""+productname+": "+ std::to_string(pNode->price)+"\"\n";


    }
    int findHeight(AVL_SECOND_NODE* X){
        if(!X)return 0;
        return X->height;
    }
    AVL_SECOND_NODE* Insertion_Item_to_tree_2(const string& productname, AVL_SECOND_NODE* pNode,int price) {
        if(!pNode){
     //       cout<<" WTF 2 "+ std::to_string(price)+"\n";

            pNode=new AVL_SECOND_NODE;
            pNode->product_name=productname;
            pNode->price=price;
            return pNode;
        }
       // cout<<" WTF \n";
        if(strcmp(productname.c_str(),pNode->product_name.c_str())<0)pNode->Left_Child=Insertion_Item_to_tree_2(productname,pNode->Left_Child,price);
        else if(strcmp(productname.c_str(),pNode->product_name.c_str())>0)pNode->Right_Child=Insertion_Item_to_tree_2(productname,pNode->Right_Child,price);
        else {
            //cout<<"here\n";
            pNode->price=price;
            return pNode;
        }
        height(pNode);
     //   cout<<" WTF 3 \n";
        int left_heigth,right_heigth;
        left_heigth= findHeight(pNode->Left_Child);
        right_heigth= findHeight(pNode->Right_Child);
        if(left_heigth-right_heigth>1&& strcmp(productname.c_str(),pNode->Left_Child->product_name.c_str())<0){
            return Right_Rotate(pNode);
        }

        if(left_heigth-right_heigth>1&& strcmp(productname.c_str(),pNode->Left_Child->product_name.c_str())>0){
            return Left_Right_Rotation(pNode);
        }

        if(left_heigth-right_heigth<-1&& strcmp(productname.c_str(),pNode->Right_Child->product_name.c_str())>0){
            return Left_Rotate(pNode);
        }
        if(left_heigth-right_heigth<-1&& strcmp(productname.c_str(),pNode->Right_Child->product_name.c_str())<0){
            return Right_Left_Rotation(pNode);
        }
        return pNode;

    }
    int height(AVL_SECOND_NODE* X){
        if(!X)return 0;
      int  left_height= height( X->Left_Child);
      int  right_height= height( X->Right_Child);
        X->height=(left_height>right_height)?left_height+1:right_height+1;
        //cout<< X->height<<endl;
        return X->height;
    }
    AVL_SECOND_NODE* Left_Rotate(AVL_SECOND_NODE* X){
        temp=X->Right_Child;
        X->Right_Child=temp->Left_Child;
        temp->Left_Child=X;
        //cout<<"Height of left rotate:"<<height(X)<<endl;
        return temp;
    }
    AVL_SECOND_NODE* Right_Rotate(AVL_SECOND_NODE* X){
         temp=X->Left_Child;
         X->Left_Child=temp->Right_Child;
         temp->Right_Child=X;
        //cout<<"Height of Right rotate:"<<height(X)<< endl;
        return temp;

    }
    AVL_SECOND_NODE* Left_Right_Rotation(AVL_SECOND_NODE* X){
        X->Left_Child= Left_Rotate(X->Left_Child);
        return Right_Rotate(X);

    }
    AVL_SECOND_NODE* Right_Left_Rotation(AVL_SECOND_NODE* X){
        X->Right_Child= Right_Rotate(X->Right_Child);
        return Left_Rotate(X);
    }
    string procces_In_order(AVL_SECOND_NODE *pNode) {
        if(!pNode) return "";
        return pNode->product_name+"\n"+ procces_In_order(pNode->Left_Child)+ procces_In_order(pNode->Right_Child);
    }

    AVL_SECOND_NODE *procces_right_Of_left_Child(AVL_SECOND_NODE *pNode) {
        if(!pNode->Right_Child) return pNode;
        else return procces_right_Of_left_Child(pNode->Right_Child);
    }
    int  calc_Balance(AVL_SECOND_NODE* X){
        if(!X)return 0;
        int left_heigth,right_heigth;
        left_heigth= findHeight(X->Left_Child);
        right_heigth= findHeight(X->Right_Child);
        return left_heigth-right_heigth;
    }
    AVL_SECOND_NODE* delete_Node(AVL_SECOND_NODE *pNode, string product_name) {
        if(!pNode)
            return pNode;


        if(strcmp(product_name.c_str(), pNode->product_name.c_str())<0)pNode->Left_Child=delete_Node(pNode->Left_Child,std::move(product_name));
        else if(strcmp(product_name.c_str(), pNode->product_name.c_str())>0)pNode->Right_Child=delete_Node(pNode->Right_Child,std::move(product_name));
        else{
            if(pNode->Right_Child== nullptr||pNode->Left_Child== nullptr){
                temp=(pNode->Right_Child)?pNode->Right_Child:pNode->Left_Child;
                if(!temp){
                    pNode= nullptr;

                }
                else {
                    pNode=temp;
                }

            }
            else{
            temp=procces_right_Of_left_Child(pNode->Left_Child);
            pNode->product_name=temp->product_name;
            pNode->price=temp->price;

            pNode->Left_Child= delete_Node(pNode->Left_Child,temp->product_name);
            }
        }
        if(!pNode)return nullptr;

        height(pNode);
        //   cout<<" WTF 3 \n";

        if(calc_Balance(pNode)>1&& calc_Balance(pNode->Left_Child)>=0){

            pNode= Right_Rotate(pNode);

        }

        if(calc_Balance(pNode)>1&& calc_Balance(pNode->Left_Child)<0){
            pNode= Left_Right_Rotation(pNode);
        }
        if(calc_Balance(pNode)<-1&& calc_Balance(pNode->Right_Child)>=0){

            pNode= Left_Rotate(pNode);
        }
        if(calc_Balance(pNode)>1&& calc_Balance(pNode->Right_Child)<0){
            pNode= Right_Left_Rotation(pNode);
        }
        return pNode;
    }
    string  Print_Current_level(int i,AVL_SECOND_NODE* X){
        if(!X)return "";
        if(i==1){
            //cout<<"HOYDA\n"+std::to_string(X->price)<<X->product_name;

            return "\t\""+X->product_name+"\":\""+ std::to_string(X->price)+"\",";
        }
        else{
            --i;
            return Print_Current_level(i,X->Left_Child)+ Print_Current_level(i,X->Right_Child);
        }
    }
public:


    string Print_Level_Order(){

        if(root){
            string print_str;

            for (int i = 1; i < height(root)+1 ; ++i) {


                 print_str +=Print_Current_level(i,root)+"\n";
            }

            return     print_str;

            }

        return "\t{}\n";
    }

    string Print_InOrder(){

        if(!root){
            //cout<<" Empty";
            return "";
        }
        return procces_In_order(root)+"\n";


    }
    string print_Item(string const& product_name){
    //   cout<<Print_item(product_name,root);
        return Print_item(product_name,root);

    }



    void  delete_Node(string product_name){
        root=delete_Node(root,std::move(product_name));
    }
    void Insert_Item_to_AVL_TREE(const string& productname,int price){
        if(!root){
      //      cout<<"price"<<price<<endl;
            root=new AVL_SECOND_NODE;
            root->product_name=productname;
            root->price=price;
            return;
        }
        //       cout<<" Go to tree_2 \n";
       root= Insertion_Item_to_tree_2(productname,root,price);
    }
    void Change_Item(string product_name,int price){
       // cout<<"price:"<<price<<endl;
        Change_Item(std::move(product_name),root,price);

    }

};


#endif