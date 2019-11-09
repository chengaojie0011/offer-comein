//
// Created by 陈高杰 on 2019-11-09.
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
    int cutRope(int number) {
        if(number<=1){
            return 0;
        }
        else if(number==2){
            return 1;
        }
        else if(number==3){
            return 2;
        }
        int* products = new int[number+1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        int max = 0;
        for (int i = 4; i < number+1; ++i) {
            max = 0;
            for (int j = 1; j <= number/2; ++j) {
                int product = products[j]*products[i-j];
                if(product>max){
                    max = product;
                }

            }
            products[i] = max;
        }

        return max;
    }
};

class Solution2 {
public:
    int cutRope(int number) {
        int max = 0;
        if(number<=1){
            return 0;
        }
        else if(number==2){
            return 1;
        }
        else if(number==3){
            return 2;
        }
        int threetimes = number/3;
        if(number%3==1){
            threetimes -=1;
        }
        int twotimes = (number-threetimes*3)/2;
        max = pow(3,threetimes)*pow(2,twotimes);
        return max;
    }
};

int main()
{

    Solution1 solution;
    cout << solution.cutRope(4) << endl;
    return 0;
}


