//
// Created by 陈高杰 on 2019-11-12.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0){
//            throw new RuntimeException("分母不能为0");
            return 0;
        }
        int e=exponent;
        if(exponent==0){
            return 1;
        }
        else if(exponent<0){
            e =-exponent;
        }
        double res = 1;
        double temp = base;
        while(e>0){
            if((e&1)==1){
                res = res*temp;
            }
            e =e>>1;
            temp *= temp;
        }
        if(exponent<0){
            res = 1/res;
        }
        return res;

    }
};


//int main()
//{
//    Solution solution;
//    cout << solution.Power(-2,3) << endl;
//    return 0;
//}




