#ifndef ORDER_H
#define ORDER_H

class Order
{
	public:
		int id;
		float arrival_time,order_time, brew_time, price;
		Order(){
		
		}
		Order(int id,float arrival_time, float order_time, float brew_time ,float price){
		this->id = id;
		this->arrival_time = arrival_time;
		this->order_time = order_time;
		this->brew_time = brew_time;
		this->price = price;
		}
	protected:
};

#endif
