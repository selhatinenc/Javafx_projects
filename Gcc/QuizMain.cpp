#include "QuizMain.h"
#include <iostream>
#include <string>

using namespace std;

QuizMain::QuizMain()
{
    // Hia stackoverflow
}

void QuizMain::my_new_function(std::string my_name){
    std::cout << "Hi " + my_name +"!" << std::endl;
}

void r(int value){
	if(0<value&& value<<10){
		r(value-2);
				r(value+1);
				cout<<value;

	}
}
int main()
{
	r(3)   ; return 0;
}
