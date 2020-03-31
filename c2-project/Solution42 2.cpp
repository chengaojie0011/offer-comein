//
// Created by 陈高杰 on 2020/2/11.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int length  = array.size();
        vector<int> dp = array;
        for (int i = 1; i < length; ++i) {
            int temp = dp[i-1]+array[i];
            if(temp>array[i]){
                dp[i] =temp;
            }
        }
        int max_dp = dp[0];
        for (int j = 1; j < length; ++j) {
            if(dp[j]>max_dp)
                max_dp = dp[j];
        }
        return max_dp;
    }
};

//
//int main(){
//    vector<int> l = {1,-2,3,10,-4,7,2,-5};
//    Solution solution;
//    int x = solution.FindGreatestSumOfSubArray(l);
//    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}

