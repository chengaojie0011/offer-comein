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
    int Add(int num1, int num2)
    {
        int sum = 0, carry = 0;
        while(num2!=0){
            sum = num1 ^ num2;
            carry = (num1 & num2)<<1;
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};



//int main(){
//    Solution solution;
//    int a = 4;
//    int b = -3;
//    int n1;
//    n1 = solution.Add(a,b);
//    cout<< n1<<endl;
//    system("PAUSE");
//    return 0;
//}
