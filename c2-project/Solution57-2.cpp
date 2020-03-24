//
// Created by 陈高杰 on 2020/2/17.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3)
            return res;
        int small=1;
        int big = 2;
        int mid = (sum+1)/2;
        int all = small+big;
        while(small<mid){
            if(all == sum)
                res.push_back(PrintSumOnce(small,big));
            while(all>sum && small<mid){
                all -=small;
                small++;
                if(all == sum)
                    res.push_back(PrintSumOnce(small,big));
            }
            big++;
            all +=big;
        }
        return res;
    }
    vector<int> PrintSumOnce(int num1, int num2){
        vector<int>  res_in;
        for (int i = num1; i <= num2; ++i) {
            res_in.push_back(i);
        }
        return res_in;
    }
};


//int main(){
//    vector<int> l = {1,2,4,7,11,15};
//
//    Solution solution;
//    int k = 15;
//    vector<vector<int> > n1;
//    n1 = solution.FindContinuousSequence(k);
//    for (int i = 0; i < n1.size(); ++i) {
//        cout<< n1[i].size()<<endl;
//        for (int j = 0; j < n1[0].size(); ++j) {
//            cout<< n1[i][j]<<endl;
//        }
//        cout<<endl;
//    }
//    system("PAUSE");
//    return 0;
//}

