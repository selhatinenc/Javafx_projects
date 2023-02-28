#include <iostream>

struct  AVL_Tree{
    int treeheight;
    int data;
    AVL_Tree(int x){
        data=x;
    }
    AVL_Tree* right= nullptr;
    AVL_Tree* left= nullptr;
};

int height(AVL_Tree* tree){
    if(tree== nullptr)return -1;
    else{
        int rightHeigth, leftHeigth;
        leftHeigth= height(tree->left);
        rightHeigth= height(tree->right);
        if(rightHeigth>leftHeigth)return rightHeigth+1;
        else return leftHeigth+1;
    }
}
AVL_Tree* Insert_Item(int x,AVL_Tree* tree){
    if(tree!= nullptr){
        int hOFright,hOfLeft;
        if(x>tree->data)
            tree->right= Insert_Item(x,tree->right);
        else
            tree->left= Insert_Item(x,tree->left);
        tree->treeheight= height(tree)+1;
        hOFright= height(tree->right);
        hOfLeft= height(tree->left);
        if(hOfLeft-hOFright>1&&x<tree->left->data){
            //rigth rotate
        }
        if(hOfLeft-hOFright>1&&x>tree->left->data){
           // tree->left=leftrotate(tree.left)
           //return rightrotate(tree);
            //left right rotate
        }
        //and for right
    }

    else return new AVL_Tree(x);
}
struct node{
    node(int y){
        x=y;
    }
    int x;
    struct node* next=NULL;
};

void Insert_begining(node* &head){
    node* pre,*old_head=head;
    for (;head->next;pre=head,head= head->next);
    std::cout<<"head:"<<head->x<<std::endl;
    std::cout<<"old head:"<<old_head->x<<std::endl;
    pre->next=NULL;
    head->next=old_head;
    std::cout<<"After  head->next=old_head    oldhead.x:"<<old_head->x<<std::endl;;
}
int main() {
    node* head=new node(1);
    head->next=new node(8);
    head->next->next=new node(4);
    head->next->next->next=new node(3);
    node* temp=head;
    for (; temp  ; temp=temp->next) {
        std::cout<<temp->x<<std::endl;
    }

    Insert_begining(head);
     temp=head;
    for (; temp  ; temp=temp->next) {
        std::cout<<temp->x<<std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
