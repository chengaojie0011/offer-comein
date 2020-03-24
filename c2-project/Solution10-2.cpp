//
// Created by 陈高杰 on 2020/3/24.
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
    int jumpFloorII(int number) {
        if(number<=0)
            return 0 ;
//        return pow(2,number-1);
        return 1<<--number;
    }
};


class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0)
            return 0 ;
        else if (number ==1)
            return 1;
        else if (number ==2)
            return 2;
        int sum = 1;
        for (int i = 2; i <= number; ++i) {
            sum += sum;
        }
        return sum;
    }
};

//int main()
//{
//
//    Solution solution;
//    cout << solution.jumpFloorII(3) << endl;
//    return 0;
//}