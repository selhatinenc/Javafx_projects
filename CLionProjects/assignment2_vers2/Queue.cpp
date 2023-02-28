#include "Queue.h"
#include "Customer.h"
using namespace std;
#include <iostream>

void Queue::deQueue(){
	if(front==NULL){
		return;
	}
	Node* temp = front;
	front = front->next;
	size--;
	if(front ==NULL){
		rear = NULL;
	}
	delete temp;
}

void Queue::enQueue(Customer customer){

	size++;
	Node* newnode = new Node(customer);
	if(rear==NULL){
		front = rear = newnode;
		return;
	}
	rear->next = newnode;
	rear = newnode;
}

void Queue::priorityEnqueue(Customer customer){

	size++;
	Node* newnode = new Node(customer);
	if(rear==NULL){
		front = rear = newnode;
		return;	
	}
	if(front->customer.price_of_order < customer.price_of_order){
		newnode->next = front;
		front = newnode;
		return;
	}
	
	Node* temp = front;
	while(temp->next != NULL && customer.price_of_order < temp->next->customer.price_of_order){
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}



void reverse(string str)
{
    int len = str.length();
    int n = len;
    while(n--)
        cout << str[n];
}

void Queue::printQueue(){
	if(front==NULL){
		return;
	}
	Node* temp = front;
	int index = 0;
	while(index < size){
		cout << temp->customer.id << " ";
		if(temp!=NULL){
			temp = temp->next;
		}
		index++;
		if(temp==NULL){
			size = index;
			break;
		}
	}
}
