//
// Created by 陈高杰 on 2020/3/24.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number <=0)
            return 0;
        else if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else
            return rectCover(number-1)+rectCover(number-2);
    }
};

class Solution1 {
public:
    int rectCover(int number) {
        if(number <=0)
            return 0;
        else if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        int num1 = 1;
        int num2 = 2;
        int sum =  0;
        for (int i = 3; i <= number ; ++i) {
            sum = num1 + num2;
            num1 = num2;
            num2 = sum;
        }
        return sum;
    }
};

//int main()
//{
//    Solution solution;
//    cout << solution.rectCover(3) << endl;
//    return 0;
//}