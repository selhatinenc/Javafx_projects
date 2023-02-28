using namespace std;
#include <iostream>

int mynum=2;
class Mainn{
	public :
	m(){
	cout<< mynum<<endl;	
	};
	void enc(int x){
		cout<<"x:"<<x<<endl;
	}
	
	
};

int num=121;

int main(){
	
	Mainn m;
	

	
	cout<<num<<endl;
	int* pointer1=&num;
	int** pointer2=&pointer1;
	int *pointer3=pointer1;
//	int ** pointer4=pointer1; It gives error
	
	cout<<*pointer1<<endl;
	cout<<**pointer2<<endl;
	cout <<*pointer3<<endl;	
	cout<<**pointer4<<endl;
	
	
	
	return 0;
	
}
