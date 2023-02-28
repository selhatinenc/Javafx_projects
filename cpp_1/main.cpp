#include "main.h"
#include <iostream>
#include <string>
#include "readfiles.cpp"
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

main::main()
{
}


	


 std::ostringstream oss;


void findrecrusive(int x, int y,int** maparr,int** keyarr,int nxmap,int nymap,int nkey){
		int sum=0;
		int i;
		int j;
		int c=(nkey-1)/2;
	
		for ( i = -c; i < c+1; i++)
		{
			for ( j = -c; j < c+1; j++)
			{
				sum+=maparr[x+i][y+j]*keyarr[c+i][c+j];
			}
			
			
		}
				oss<<x<<","<<y<<":"<<sum<<endl;


		int mod=sum%5;
		if(mod<0){
			while(mod<0)mod+=5;
		}
		if(mod==1){
			
			 if(x<3+c) findrecrusive(x+nkey,y, maparr, keyarr, nxmap, nymap, nkey);
			 else{
				findrecrusive(x-nkey,y, maparr, keyarr, nxmap, nymap, nkey);
			 }
		}
		else if(mod==2){
			if(x>nxmap-4-c ) findrecrusive(x-nkey,y, maparr, keyarr, nxmap, nymap, nkey);
			else {
				 findrecrusive(x+nkey,y, maparr, keyarr, nxmap, nymap, nkey);
			}
		}
		else if(mod==3){
			if(y>nymap-4-c) findrecrusive(x,y-nkey, maparr, keyarr, nxmap, nymap, nkey);
			else{
				findrecrusive(x,y+nkey ,maparr, keyarr, nxmap, nymap, nkey);
			}
		}
		else if(mod==4)
		{
			if(y<3+c) findrecrusive(x,y+nkey, maparr, keyarr, nxmap, nymap, nkey);
			else{
				findrecrusive(x,y-nkey, maparr, keyarr, nxmap, nymap, nkey);
			}
		}
		else{
		}
				

}
void writeoutput(string outputfilename){
	std::string str= oss.str();
	cout<<str;
	ofstream ofs;
	ofs.open(outputfilename.c_str());
	ofs<<str;
	ofs.close();

}
int strtoint(string x){

	stringstream convert(x);
    int tempnumber=0;
    convert>>tempnumber;
    
    return tempnumber;

}

void split(string str, char div, int  x[]){
    	
    	int index=0;
     string temp = "";
   
      for(int i=0; i<(int)str.size(); i++){
         if(str[i] != div){
            temp += str[i];
        }
          else{
          	
		
          	x[index]=strtoint(temp);
          	index++;
              temp = "";
        }
    }
    x[index]=strtoint(temp);
    
       
}
int** maparr;
	int** keyarr;
	int nxmap,nymap,nxkey,nykey;	
	
int main(int argc, char** argv)
{
	
	cout << "You have entered " << argc<< " arguments:" << "\n";
  
    for (int i = 1; i < argc; ++i){
    	
        cout << argv[i] << "\n";
    
	}
	string s=argv[1];
	int splitfirstarg[2];
	split(s,'x',splitfirstarg);
	
      main ft;
	readfiles rf;
	nxmap=splitfirstarg[0] ,nymap=splitfirstarg[1];
	nxkey=strtoint(argv[2]);
	nykey=nxkey;
		cout<<" nxmap "<<nxmap;

	cout<<" nxkey "<<nxkey;
		cout<<" nykey "<<nykey;
	cout<<" nymap "<<nymap;

	maparr=rf.r2(argv[3],nxmap,nymap);
	keyarr=rf.r2(argv[4],nxkey,nxkey);
	findrecrusive(nxkey/2,nxkey/2,maparr,keyarr,nxmap,nymap,nxkey);
	writeoutput(argv[5]);
		
	
	    return 0;
}



