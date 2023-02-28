#include "readfiles.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

 
	


// read files and store them into arrays

int** readfiles::r2(std:: string mapn,int xmap, int ymap){
	 fstream mapfile;// file stream
     int** mapparr;
    int** maparr= new int*[xmap];

    
    
    string maps;

	
	int indexy=0;

	mapfile.open(mapn.c_str(),ios::in);

	if(mapfile.is_open()){

		
			while(getline(mapfile,maps)){
			maparr[indexy]=new int[ymap];// store all int here
			stringstream ss;
 			string tempstr;
 			
 			int index=0;
 			int num;
 			
		 
 			
    	/* Storing the whole string into string stream */
    	
		//	cout<<maps<<"+++";

  		  	ss << maps;
  		
		    	while(!ss.eof()){
  		  		ss>>tempstr;
  		  		
  		  		if(stringstream(tempstr)>>num){
  		  				maparr[indexy][index]=num;
  		  				
  		  			
  		  			 if(index==ymap-1){
  		  			
  		  			
  		  				index=-1;
  		  				
						}
					
						
  		  			//	cout<<num<<" ";
  		  				index++;
					}
				
				}
				indexy++;
				
			
  		  	
  		  	
		
		}
	
		
	
		
		
	}
    for(int x=0;x<xmap;x++)
    {
        for(int y=0;y<ymap;y++)
        {
            cout<<maparr[x][y]<<" ";
            
        }
        cout<<endl;
    }

	mapfile.close();
	
	
	//////            key
	
	
    return maparr;
    
    
    
    
	}
	


	


/*	while(getline(mapfile,maps)){
			
			maparr[xmap]=(int)maps;
			cout<<maps<<endl;
		}
		
		
		
		int readfiles::readfiless(std:: string mapn, std::string keyn,int xmap, int ymap, int xkey, int ykey ,int **mapar){
	 stringstream ss;
 
    /* Storing the whole string into string stream 
    ss << mapn;
 
    /* Running loop till the end of the stream 
    string temp;
    int found;
    while (!ss.eof()) {
 
        /* extracting word by word from stream 
        ss >> temp;
 
        /* Checking the given word is integer or not 
        if (stringstream(temp) >> found)
            cout << found << " ";
 
        /* To save from space at the end of string 
        temp = "";
    }
    	return 1;
		
		*/
		
		
		
		
		
		
		
		
	

