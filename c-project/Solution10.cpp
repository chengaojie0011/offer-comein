//
// Created by 陈高杰 on 2019-11-04.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        long int res1 = 0;
        long int res2 = 1;
        long int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = res1+res2;
            res1 = res2;
            res2 = res;
        }
        return res;

    }
};

int main()
{
    vector <int> pre = {1,2,4,7,3,5,6,8};
    vector <int> vin = {4,7,2,1,5,3,8,6};
    cout << pre[0] << endl;
    Solution solution;
    cout << solution.Fibonacci(10) << endl;
    return 0;
}