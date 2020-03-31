//
// Created by 陈高杰 on 2020/3/26.
//
//
// Created by 陈高杰 on 2020/3/25.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution_ShellSort{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
    vector<int> ShellSort(vector<int>data, int start, int end)
    {
        // 希尔排序（增量不断砍半，第一次为两个数比较）
        for(int gap=data.size()/2;gap>0;gap/=2)
        {
            // 直接插入排序（gap后的数字都直接插序一遍）
            for(int i=gap;i<data.size();++i)
            {
                int temp = data[i];
                int j = i-gap;
                while (j >= 0 && temp < data[j])//寻找插入位置
                {
                    data[j+gap] = data[j];
                    j -= gap;
                }
                data[j+gap] = temp;

            }
        }

        return data;
    }
};

//int main() {
//    Solution_ShellSort solution;
//    vector<int> l = {60, 50, 90, 30, 70, 40, 80, 75};
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = solution.ShellSort(l, 0, l.size() - 1);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout <<sort_l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}

