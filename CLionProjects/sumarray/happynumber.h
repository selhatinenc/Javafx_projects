//
// Created by as_as on 9.11.2022.
//

#ifndef SUMARRAY_HAPPYNUMBER_H
#define SUMARRAY_HAPPYNUMBER_H

// solution is lack You should use vector in while loop in order to numbers used before !!!
class happynumber {

public:
    bool happyfunction(int n) {
        int mod;
        int sum;
        int count=30;

        while(count>0){
            count--;
            sum=0;

            while (true){
                mod=n%10;
                n/=10;
                sum+=mod*mod;
                if(n==0) break;
            }
            if(sum==1) return true;
            n=sum;
        }
        return false;
    }

    bool isHappy(int n) {

            if(!happyfunction(n)) return false;
            return true;


    }
};


#endif //SUMARRAY_HAPPYNUMBER_H
