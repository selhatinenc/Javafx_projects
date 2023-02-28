
using namespace std;
#include <iostream>

class pro{
	static int n1;

	public:
		static int n2;
		void fun(int n1){
			cout<<" local variable of n1 is: "<< n1 <<endl;
			cout<<" static variable n1 is: "<< pro::n1<< endl;
		}
	protected:
		static int n3;
		
	private:
		static int n4;
	
	public:
		static int n5;
		
		
};


int pro::n1=21;
int pro::n2=2121;
int main(){
	pro p;
	
	int n1=1235;
	p.fun(n1);
	cout <<" the value of n2: "<<pro::n2;
	return 0;
	
	
}
