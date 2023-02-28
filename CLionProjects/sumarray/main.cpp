#include <iostream>
#include <vector>
#include "happynumber.h"
#include "findpivotindex2.h"
using namespace std;

class main {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> sumarray;
        for (int i: nums) {
            sum+=i;
            sumarray.push_back(sum);
        }
        return sumarray;

    }
};
int main(){
    findpivotindex2 findpivotindex2;
    vector<int> nums= {1,7,3,6,5,6};
    cout<<findpivotindex2.pivotIndex(nums);
    return 0;
}
/*  happynumber happynumber;
   happynumber.isHappy(2)
 * sumarray s;

    s.runningSum(nums);
	return 1;
 */
