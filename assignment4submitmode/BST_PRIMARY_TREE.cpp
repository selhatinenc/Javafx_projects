//
// Created by as_as on 16.12.2022.
//
#ifndef BST_PRIMARY_TREE_cpp
#define BST_PRIMARY_TREE_cpp
#include <iostream>
#include "BST_NODE.cpp"
#include <cstring>
#include <utility>


typedef  BST_NODE node;
typedef  node* ptr_node;

using std::string;
using std::cout;
using std::endl;
struct BST_PRIMARY_TREE{


private:
    void Update_item_2(const string& insert_str,const string& CategoryString,int price, ptr_node &pNode){
        if(pNode== nullptr){

            return;
        }
        if(insert_str<pNode->Name)  Update_item_2(insert_str,  CategoryString, price,pNode->Left_Child);
        else if(insert_str>pNode->Name)  Update_item_2(insert_str,  CategoryString, price,pNode->Right_Child);
        else {

            pNode->TREE_OF_SECOND->Change_Item(CategoryString,price);

        }
    }
    ptr_node root= nullptr;
    ptr_node temp_node;

    void Insert_PrimaryItem_2(const char *insert_str,const string& CategoryString,int price, ptr_node &pNode) {
        if(pNode== nullptr){
            pNode=new node;
            pNode->Name=insert_str;
            pNode->TREE_OF_SECOND->Insert_Item_to_AVL_TREE(CategoryString,price);
            return;
        }
        if(strcmp(insert_str,pNode->Name.c_str())<0) return Insert_PrimaryItem_2(insert_str,  CategoryString, price,pNode->Left_Child);
        else if(strcmp(insert_str,pNode->Name.c_str())>0) return Insert_PrimaryItem_2(insert_str,  CategoryString, price,pNode->Right_Child);
        else {

            pNode->TREE_OF_SECOND->Insert_Item_to_AVL_TREE(CategoryString,price);

        }
    }
    string procces_Print_InOrder( ptr_node temp_node) {
        string str;
        if(!temp_node) return " ";
        str+=temp_node->Name+"\t";
        str+= procces_Print_InOrder(temp_node->Left_Child);
        str+= procces_Print_InOrder(temp_node->Right_Child);
        return str;
    }

    string find_rightmost_of_leftchild(BST_NODE *pNode) {
        if(!pNode->Right_Child){

            string ans=pNode->Name;
             temp_node=pNode;
            pNode= nullptr;
            delete(temp_node);
            temp_node= nullptr;
            return ans;
        }
        return find_rightmost_of_leftchild(pNode->Right_Child);

    }
    // this delete category
    void Delete_Item_2(const string& CategoryString, ptr_node &pNode) {
        if(!pNode) {
            //cout<<"No  element"<<endl;
            return;
        }
        if(strcmp(CategoryString.c_str(),pNode->Name.c_str())<0)  Delete_Item_2(CategoryString,pNode->Left_Child);
        else if(strcmp(CategoryString.c_str(),pNode->Name.c_str())>0)  Delete_Item_2(CategoryString,pNode->Right_Child);
        else {

            if(pNode->Left_Child!= nullptr&&pNode->Right_Child!= nullptr){
                pNode->Name=find_rightmost_of_leftchild(pNode->Left_Child);
            }
            else if(pNode->Left_Child== nullptr){
                temp_node=pNode;
                pNode=pNode->Right_Child;
                delete(temp_node);
                temp_node= nullptr;
            }
            else {
                temp_node=pNode;
                pNode=pNode->Left_Child;
                delete(temp_node);
                temp_node= nullptr;

            }

        }
    }
    void Delete_Product_item_2(const string &Category, const string &product, ptr_node pNode) {
        if(!pNode)return;
        if(Category<pNode->Name)Delete_Product_item_2(Category,product,pNode->Left_Child);
        else if(Category>pNode->Name)Delete_Product_item_2(Category,product,pNode->Right_Child);
        else{
            pNode->TREE_OF_SECOND->delete_Node(product);
        }
    }
    int height(ptr_node node){
        if(!node)return 0;
        else{
            int left_height= height(node->Left_Child);
            int right_height=height(node->Right_Child);
            return (left_height>right_height)?left_height+1:right_height+1;

        }
    }
    string print_Category_2(const string& Category, ptr_node pNode) {
        if(!pNode)return "NO Category of "+Category+"\n";

        if(Category<pNode->Name)return print_Category_2(Category,pNode->Left_Child);
        else      if(Category>pNode->Name)return print_Category_2(Category,pNode->Right_Child);
        else {


            return "\""+pNode->Name+"\":\n"+pNode->TREE_OF_SECOND->Print_Level_Order();
        }
    }
    string print_current_level(int level,ptr_node node){
        if(!node)return"";
        if(level==1){
            //cout<<"WHERE\n";
            return  print_Category_2(node->Name,node);
        }
        else {
            level--;
            return print_current_level(level,node->Left_Child)+ print_current_level(level,node->Right_Child);
        }
    }
//print one item
    string print_item_2(const string& Category,const string& product,ptr_node pNode){
        if(!pNode)return "NO Category of "+Category+"\n";
        if(Category<pNode->Name)return print_item_2(Category,product,pNode->Left_Child);
        else if(Category>pNode->Name)return print_item_2(Category,product,pNode->Right_Child);
        else{
           // cout<<"\""+pNode->Name+"\":\n"+pNode->TREE_OF_SECOND->print_Item(product);
            return "\""+pNode->Name+"\":\n"+pNode->TREE_OF_SECOND->print_Item(product);
        }
    }

public:
    string print_item(const string& Category,const string& product){
    //    cout<<print_item_2(Category,product,root);
        return print_item_2(Category,product,root);
    }
// print only one category
    string print_Category(const string& category_name){
        if(root)
            return print_Category_2(category_name,root);
        else return "NO Category of "+category_name+"\n";
    }

// Print ALL category
    string  print_ALL_Category(){
        if(root){
            string print_str;
            for (int i = 1; i < height(root)+1 ; i++) {
                //cout<<"FOR\n";
                print_str+=print_current_level(i,root);
            }

            return print_str;
        }
        return "FREE\n";
    }

    void insert_PrimaryItem(const string& category_name,const string& product_name,int price){
            if(!root){
            //    cout<<"price:"<<price<<endl;
            root=new BST_NODE;
            root->Name=category_name;
            root->TREE_OF_SECOND->Insert_Item_to_AVL_TREE(product_name,price);

                return;
            }
            Insert_PrimaryItem_2(category_name.c_str(),product_name,price,root);
        }



    void Delete_Item(const string& category_name){
        Delete_Item_2(category_name,root);
    }



    void Delete_Product_item(const string& category_name, const string& product_name){
        Delete_Product_item_2(category_name,product_name,root);
    }

    string Print_InOrder() {
        string str;
        if(!root){
            str="NULL";
            return str;
        }
        temp_node=root;
        str=procces_Print_InOrder(temp_node);
        //cout<<str<<std::endl;
        return str;
    }
    void Update_item(const string& CategoryString,const string& product,int price){
        Update_item_2(CategoryString,product,price,root);
    }




};
typedef node BST_NODE;
#endif