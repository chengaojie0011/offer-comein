//
// Created by 陈高杰 on 2019-11-11.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution1 {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while(n){
            n = n&(n-1);
            count++;
        }
        return count;
    }
};

class Solution2 {
public:
    int  NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if(flag&n){
                count++;
            }
            flag = flag<<1;
        }
        return count;
    }
};

//int main()
//{
//    Solution2 solution;
//    cout << solution.NumberOf1(9) << endl;
//    return 0;
//}



