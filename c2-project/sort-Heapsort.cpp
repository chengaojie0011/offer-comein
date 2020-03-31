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

class Solution_Heapsort{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }

    void adjustHeap(vector<int>&input,int start,int end){
        int child=start*2+1;
        if(child<=end){
            if(child+1<=end&&input[child+1]>input[child]){
                child=child+1;  //获取孩子结点的较大那个
            }
            if(input[child]>input[start]){
                Swap(input[start],input[child]);
                adjustHeap(input,child,end);
            }

        }

    }
    vector<int> Heapsort(vector<int> &data,int start,int end){
        int length = data.size();
        //初始化一个最大堆，i的范围为有孩子结点的节点
        for (int i = length/2-1; i >=0 ; --i) {
            adjustHeap(data,i,length-1);
        }
        //进行堆排序，可以少排一次
        for (int j = length-1; j >0 ; --j) {
            Swap(data[j],data[0]);
            adjustHeap(data,0,j-1); //注意要到j-1
        }
        return data;
    }

};

//int main() {
//    Solution_Heapsort solution;
//    vector<int> l = {60, 50, 90, 30, 70, 40, 80, 75};
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = solution.Heapsort(l, 0, l.size() - 1);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout <<sort_l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}

