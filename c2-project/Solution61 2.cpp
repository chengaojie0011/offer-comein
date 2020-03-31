//
// Created by 陈高杰 on 2020/3/19.
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
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty() or numbers.size()!=5)
            return false;
        sort(numbers.begin(),numbers.end());
        int num0 = 0;
        for (int i = 0; i < numbers.size()-1; ++i) {
            if(numbers[i] < 0 || numbers[i] > 13) return false;
            if(numbers[i]==0)
                num0++;
            else{
//                cout<<num0<<endl;
                int temp = numbers[i+1]-numbers[i];
                if(temp == 0){
                    return false;
                }
                num0 = num0-(temp-1);
                if(num0<0)
                    return  false;
            }
        }
        return true;
    }
};

//必须满足两个条件
//1. 除0外没有重复的数
//2. max - min < 5

class Solution2 {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty() or numbers.size()!=5)
            return false;
        int* d = new int[14];
        int max =-1;
        int min =14;
        for (int i = 0; i < numbers.size(); ++i) {
            if(numbers[i] < 0 || numbers[i] > 13) return false;
            if(numbers[i] == 0) continue;
            d[numbers[i]]++;
            if(d[numbers[i]]>1) return false;
            if(max<numbers[i]) max = numbers[i];
            if(min>numbers[i]) min = numbers[i];
            if(max - min >= 5) return false;
        }
        delete[]d;
//        cout<<max<<endl;
//        cout<<min<<endl;
        return true;
    }
};

//int main(){
//    Solution2 solution;
//    //0,3,1,6,4
//
//    vector<int> k = {1,3,2,6,4};
//   // 1,0,0,5,0
//    bool n1;
//    n1 = solution.IsContinuous(k);
////    for (int i = 0; i < n1.size(); ++i) {
////        cout<< n1[i];
////    }
//    cout<< n1;
//    system("PAUSE");
//    return 0;
//}