#ifndef QUEUE_H
#define QUEUE_H
#include <cstddef>
#include "Customer.h"
class Node{
	public:
		Customer customer;
		Node* next;
		Node(Customer customer){
			this->customer = customer;
			this->next = NULL;
		}
		
};

class Queue
{
	
	public:	
		float busy_time,finish_time=0;
        float price_of_order;
		int size=0;
		Node *front,*rear;
		Queue(){
			busy_time = 0;
			finish_time = 0;
			front = rear = NULL;
		}
		void enQueue(Customer customer);
		void deQueue();
		void priorityEnqueue(Customer customer);
		void printQueue();
	protected:
};

#endif
