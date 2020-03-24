//
// Created by 陈高杰 on 2020/2/9.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()){
            return 0;
        }
        int num = numbers[0];
        int time = 1;
        for (int i = 1; i <numbers.size() ; ++i) {
            if(num == numbers[i]){
                time++;
            }
            else{
                time--;
            }
            if(time == 0){
                num = numbers[i];
                time = 1;
            }
        }
        int time2 = 0;
        for (int i = 0; i <numbers.size() ; ++i) {
            if(num == numbers[i]){
                time2++;
            }
        }
        if(time2>numbers.size()/2){
            return num;
        }
        else{
            return 0;
        }
    }
};
//
//int main()
//{
//    vector<int> s = {1,2,3,2,2,2,5,4,2};
//    Solution solution;
//    int  output1;
//    output1 = solution.MoreThanHalfNum_Solution(s);
//    cout << output1<< endl;
////    vector<string>  output1 = {"abc","bca"};
////    for (int i = 0; i < output1.size(); ++i) {
////        for (int j = 0; j < output1[i].size(); ++j) {
////            cout << output1[i][j] ;
////        }
////        cout << " "<< endl;
////    }
//    system("PAUSE");
//    return 0;
//}

