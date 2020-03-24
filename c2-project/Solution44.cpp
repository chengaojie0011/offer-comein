//
// Created by 陈高杰 on 2020/2/12.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;


class Solution{
public:
    int countOfInt(int n){
        if(n==1)
            return 10;
        else
            return int(9*pow(10 , n-1));
    }

    int inIndex(int index, int n){
        int n_first = 0;
        if(n==1)
            n_first = 0;
        else
            n_first = pow(10,n-1);
        int number = int(n_first + index/n);
        int indexfornum = int(n-index%n-1);
        for (int i = 0; i < indexfornum; ++i) {
            number /=10;
        }
        return number%10;
    }
    int digitAtIndex(int index){
        if(index<0){
            return -1;
        }
        int digit = 1;
        while(true){
            int num = countOfInt(digit);
            if(index<num){
                return inIndex(index,digit);
            }
            index -= num*digit;
            digit++;
        }

    }
};

//int main(){
//    int l = 1001;
//    Solution solution;
//    int x = solution.digitAtIndex(l);
//    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}


