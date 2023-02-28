//
// Created by as_as on 24.12.2022.
//
// C++ program to implement insert operation
// in Red Black Tree.
#include <bits/stdc++.h>
using namespace std;



class LLRB_TREE{

public:
// Utility function to create a node.
LLRB_NODE* createLLRB_NODE(string product,int price, bool color)
{
    LLRB_NODE *myNode = new node();
    myNode -> left = myNode -> right = NULL;
    myNode -> product = product;
    myNode->price=price;
    // New Node which is created is
    // always red in color.
    myNode -> color = true;
    return myNode;
}

// Utility function to rotate node anticlockwise.
node* rotateLeft(node* myNode)
{
    cout << "left rotation!!\n";
    node *child = myNode -> right;
    node *childLeft = child -> left;

    child -> left = myNode;
    myNode -> right = childLeft;

    return child;
}

// Utility function to rotate node clockwise.
node* rotateRight(node* myNode)
{
    cout << "right rotation\n";
    node *child = myNode -> left;
    node *childRight =  child -> right;

    child -> right = myNode;
    myNode -> left = childRight;

    return child;
}

// Utility function to check whether
// node is red in color or not.
int isRed(node *myNode)
{
    if (myNode == NULL)
        return 0;

    return myNode->color;
}

// Utility function to swap color of two
// nodes.
void swapColors(node *node1, node *node2)
{
    bool temp = node1 -> color;
    node1 -> color = node2 -> color;
    node2 -> color = temp;
}

// Inorder traversal
void inorder(node *node)
{
    if (node)
    {
        inorder(node -> left);
        cout<< node -> product << " ";
        inorder(node -> right);
    }
}

// Insertion into Left Leaning Red Black Tree.
node* insert(node* myNode,const string& product, int price)
{

    // Normal insertion code for any Binary
    // Search tree.
    if (myNode == NULL)
        return createNode(product,price, false);

    if (product < myNode -> product)
        myNode -> left = insert(myNode -> left, product ,price);

    else if (product > myNode -> product)
        myNode -> right = insert(myNode -> right, product,price);

    else
        return myNode;

    // case 1.
    // when right child is Red but left child is
    // Black or doesn't exist.
    if (isRed(myNode -> right) &&
        !isRed(myNode -> left))
    {

        // Left rotate the node to make it into
        // valid structure.
        myNode = rotateLeft(myNode);

        // Swap the colors as the child node
        // should always be red
        swapColors(myNode, myNode -> left);
    }

    // case 2
    // when left child as well as left grand
    // child in Red
    if (isRed(myNode -> left) &&
        isRed(myNode -> left -> left))
    {

        // Right rotate the current node to make
        // it into a valid structure.
        myNode = rotateRight(myNode);
        swapColors(myNode, myNode -> right);
    }

    // case 3
    // when both left and right child are Red in color.
    if (isRed(myNode -> left) && isRed(myNode -> right))
    {

        // Invert the color of node as well
        // it's left and right child.
        myNode -> color = !myNode -> color;

        // Change the color to black.
        myNode -> left -> color = false;
        myNode -> right -> color = false;
    }
    return myNode;
}
};