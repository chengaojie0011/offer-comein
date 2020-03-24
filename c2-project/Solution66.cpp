//
// Created by 陈高杰 on 2020/3/23.
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
#include <list>

using namespace std;


class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
         int len = A.size();
         vector<int> res(len, 1);
         if(A.empty() || len<1)
             return res;
        res[0] = 1;
        for (int i = 1; i < len; ++i) {
            res[i] = res[i-1] * A[i-1];
        }
        int temp = 1;
        for (int i = len-2; i >= 0; --i) {
            temp = temp *A[i+1];
            res[i] = res[i] *temp;
        }
        return res;
    }
};


//int main(){
//    Solution solution;
//    vector<int> a = {1,2,3,4,5};
////    [120,60,40,30,24]
//    vector<int> n;
//    n = solution.multiply(a);
//    for (int i = 0; i < n.size(); ++i) {
//        cout<<n[i]<<' ';
//    }
//    system("PAUSE");
//    return 0 ;
//}