//
// Created by as_as on 9.11.2022.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    // start from middle of array and then go left and right respectivly
public:
    vector<int> numvec;
    int middle,rightsum,leftsum;
    int changeindex=0;
    int pivotIndex(vector<int>& nums) {
        numvec=nums;
        middle=(nums.size()-1)/2;
        return ans();
    }
    int ans(){
        if( middle==numvec.size()||middle<-1) return -1;
         leftsum= sumloop(0,middle);
         rightsum= sumloop(middle+1,numvec.size());
        changeindex++;
        cout<<middle<<" ";
        if(leftsum== rightsum) {
            if(middle==0 || middle==numvec.size()-1) return  0;
            return  middle;
        }
        else if(changeindex%2==1) {
            middle-=changeindex;
        }
        else  {
            middle+=changeindex;
        }

        if(middle<0) middle=-1;
        return ans();

    }
    int sumloop(int startindex,int endindex){
        int sum=0;
        for (int i = startindex; i <endindex ; ++i) {
            sum+=numvec[i];
        }
        return sum;
    }
    int findsumwhenpivotindexchange(){
    }

    int findsumwhenpivotindexchange(int changeindex){

    }


};
