//
// Created by 陈高杰 on 2020/2/17.
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
    vector<vector<float>> FindSum(int num) {
        vector<vector<float>> p;
        if(num<1)
            return p;
        //状态数组，数组指针
//        int (*arr)[100]= new int[6][100];
        int arr[num+1][6*num+1];
        memset(arr,0,sizeof(arr));

        for(int i = 1; i <=6; i++)//初始状态
            arr[1][i] = 1;

        for (int i = 2; i <=num; ++i) {
            for (int j = i; j <= 6*i; ++j) {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j - 2] + arr[i - 1][j - 3]+
                        arr[i - 1][j - 4] + arr[i - 1][j - 5] + arr[i - 1][j - 6];
            }
        }
        int total  = pow(6,num);
        for(int i = num; i <= 6 * num; i++)
        {
            float pro = arr[num][i] * 1.0 /  total;
            cout<<"骰子的和为 "<<i<<" 时，对应的频率为："<<pro<<endl;
            vector<float> temp={(float)i,pro};
            p.push_back(temp);
        }
        return p;
    }
};

//int main(){
//    Solution solution;
//
//    vector<vector<float>> n1 = solution.FindSum(2);
//
//    for (int i = 0; i < n1.size(); ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout<< n1[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    system("PAUSE");
//    return 0;
//}

