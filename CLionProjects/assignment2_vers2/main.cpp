#include <bits/stdc++.h>
#include <fstream>
#include "Queue.h"
#include "Restaurant.h"
#include <string>
#include <vector>
#include "Customer.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void simple_tokenizer(string s)
{
    stringstream ss(s);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }
}


Restaurant initialize_restaurant(string type,string input_name){
	Restaurant restaurant;
	ifstream readFile;
	readFile.open("input.txt");
    if(!readFile.is_open()){
        cout<<"error";
        exit(1);
    }
	string word;
	getline(readFile,word);
	restaurant.number_of_cashier = std::stoi(word);
	getline(readFile,word);
	restaurant.number_of_order =std:: stoi(word);
	restaurant.array = new float*[restaurant.number_of_order];
	stringstream buffer;
	restaurant.number_of_barista = restaurant.number_of_cashier/3;	
	int index = 0;
	while(index< restaurant.number_of_order){
		
		getline(readFile,word);
		stringstream ss(word);
		int inner_index = 0;
		restaurant.array[index] = new float[4];
		while(ss>>word){
			restaurant.array[index][inner_index++] = stof(word);
		}
		index++;
	}
	readFile.close();
	return restaurant;
}


int main(int argc, char** argv) {
	
	Restaurant restaurant = initialize_restaurant("Model1","input.txt");
	Queue cashiers[restaurant.number_of_cashier];
	vector<Customer> customers;
	for(int customer_index=0;customer_index< restaurant.number_of_order;customer_index++){
		Customer customer(customer_index,restaurant.array[customer_index][0],restaurant.array[customer_index][1],restaurant.array[customer_index][2],restaurant.array[customer_index][3]);
		customers.push_back(customer);
	}
	float time = 0.0;
	for(int index=0;index<restaurant.number_of_order;index++){
		time = customers[index].arrival_time;

/*
        int search_cashier=0;
        float workendfirst=cashiers[0].finish_time;

        for(int i=0;i<restaurant.number_of_barista;i++){
            if(cashiers[i].finish_time<workendfirst){
                workendfirst=cashiers[i].finish_time;
                search_cashier=i;
            }
        }
        int searchostumer=0;

        for(int index=0;index<restaurant.number_of_order;index++){
            if(customers[index].dontgocashier)
            {
                searchostumer=index;
                break;
            }



        }
        customers[searchostumer].dontgocashier= false;
        float waittime=cashiers[searchostumer].finish_time-customers[searchostumer].arrival_time;
        if(waittime<0)waittime=0;
        customers[index].order_ready_time = waittime + customers[index].order_time_normal+customers[searchostumer].arrival_time;
        cashiers[searchostumer].enQueue(customers[index]);
        cashiers[searchostumer].finish_time = customers[index].order_ready_time;
        cashiers[searchostumer].busy_time += customers[index].order_time_normal;
        */


        if(customers[index].id<restaurant.number_of_cashier){
			customers[index].order_ready_time = time + customers[index].order_time_normal;
			cashiers[customers[index].id].enQueue(customers[index]);
			cashiers[customers[index].id].finish_time = customers[index].order_ready_time;
			cashiers[customers[index].id].busy_time += customers[index].order_time_normal;
		}
		else{
			bool is_added = false;
			for(int i=0;i<restaurant.number_of_cashier;i++){
				if(cashiers[i].finish_time < time){
					customers[index].order_ready_time = time + customers[index].order_time_normal;
					cashiers[i].finish_time = customers[index].order_ready_time;
					cashiers[i].enQueue(customers[index]);
					cashiers[i].busy_time += customers[index].order_time_normal;
				
					is_added = true;
					break;
				}
			}
			
			if(!is_added){
		
			customers[index].order_ready_time = cashiers[0].finish_time + customers[index].order_time_normal;
			cashiers[0].enQueue(customers[index]);
			cashiers[0].finish_time = customers[index].order_ready_time;
			cashiers[0].busy_time += customers[index].order_time_normal;
					
			
			}
		}
	}


	Queue barista[restaurant.number_of_barista];
	sort(customers.begin(),customers.end());
    for(int index=0;index<restaurant.number_of_order;index++){
        cout<<"Out of Cashier"<< customers[index].order_ready_time<<"and sort:"<<endl;
    }
	for(int index=0;index<restaurant.number_of_order;index++){
	//	time = customers[index].order_ready_time;

        int searchbarista=0;
        float workendfirst=barista[0].finish_time;
        for(int i=0;i<restaurant.number_of_barista;i++){
            if(barista[i].finish_time<workendfirst){
                workendfirst=barista[i].finish_time;
                searchbarista=i;
            }
        }
        float money=-1;
        int searccostumer=-1;
        for(int j=0;j<restaurant.number_of_order;j++){
            if(customers[j].dontgobarista){
            if(workendfirst==0){
                searccostumer=j;
              
                break;
            }
            else{
                if(customers[j].order_ready_time<=workendfirst&&(customers[j].price_of_order>money)){
                    searccostumer=j;
                    money=customers[j].price_of_order;
                }
            }
            }
        }
        cout<<"Searc"<<searccostumer<<endl;
        if(searccostumer==-1){
            for(int j=0;j<restaurant.number_of_order;j++){
                if(customers[j].dontgobarista){
                    searccostumer=j;
                    break;
                }
            }
        }

        float waittime=barista[searchbarista].finish_time-customers[searccostumer].order_ready_time;
        if(waittime<0)waittime=0;
        cout<<"wait time"<<waittime<<endl;
        customers[searccostumer].dontgobarista= false;
        customers[searccostumer].brew_ready_time = customers[searccostumer].order_ready_time+waittime + customers[searccostumer].brew_time_normal;
        barista[searchbarista].busy_time += customers[searccostumer].brew_time_normal;
        barista[searchbarista].finish_time = customers[searccostumer].brew_ready_time;
        barista[searchbarista].price_of_order = customers[searccostumer].price_of_order;
        


		}
    for(int index=0;index<restaurant.number_of_order;index++){
        cout<<"Out of barista "<< customers[index].brew_ready_time- customers[index].arrival_time<<"id:"<<customers[index].id<<endl;
    }
	
/*	int index = 0;
	while(index<restaurant.number_of_order){
		if(barista[index].front == NULL){
			index++;
			continue;
		}
		barista[index].printQueue();
		cout << endl;
		barista[index].deQueue();
	}
	
*/	
}
	
