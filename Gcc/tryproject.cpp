#include <iostream>
using namespace std;

int numm=21;



class tryproject // declare a class name
{
	public:
		void 	go();
		tryproject(); // declare cons 
	protected:
		int num;
		
	


	
};

 tryproject::tryproject()
{
	cout<< "works " ;
	
}
void tryproject::go(){
	cout<<"do this";
}
int main (){
	tryproject tp;

	int numm=12;
	cout << "number of local "<<numm<< endl;
	cout <<"number of global " << ::numm <<endl;
	tp.go();
	return 0;

}
