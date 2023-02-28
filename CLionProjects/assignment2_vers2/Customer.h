#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
	public:
		int id;
		float arrival_time,order_time_normal,order_ready_time,brew_time_normal,brew_ready_time, price_of_order;
        bool dontgobarista= true;
    bool dontgocashier= true;
        Customer(){
		}
		Customer(int id,float arrival_time,float order_time_normal,float brew_time_normal,float price_of_order){
			this->id = id;
			this->arrival_time =arrival_time;
			this->order_time_normal = order_time_normal;
			this->brew_time_normal = brew_time_normal;
			this->price_of_order = price_of_order;
		}
	 bool operator < (const Customer& customer) const
    {
        return (order_ready_time < customer.order_ready_time);
    }
	protected:
		
};


#endif
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
	public:
	protected:
};

#endif
