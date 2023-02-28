//
// Created by as_as on 10.11.2022.
#include <vector>
#ifndef SUMARRAY_FINDPIVOTINDEX2_H
#define SUMARRAY_FINDPIVOTINDEX2_H


class findpivotindex2 {
public:
    int i=0;
    int rightsum,leftsum,pivotint;
    std::vector<int> numbervector;

    int pivotIndex(std::vector<int>& nums){
        numbervector=nums;
        pivotint=0;
        rightsum= sumloop(1,nums.size());
        leftsum= 0;
        if(rightsum==leftsum) return pivotint ;

        while(i<nums.size()){
            i++;
            pivotint++;
            calculatesumagain();

            if(rightsum==leftsum) return pivotint ;



        }

        return -1;
    }
    int sumloop(int startindex,int endindex){
        int sum=0;

        for (int i = startindex; i <endindex ; ++i) {
            sum+=numbervector[i];
        }

        return sum;
    }
    //index increase 1 every time
    void calculatesumagain(){

        leftsum+=numbervector[pivotint-1];

        rightsum=rightsum-numbervector[pivotint];
    }


};


#endif //SUMARRAY_FINDPIVOTINDEX2_H
