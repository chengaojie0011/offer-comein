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

class Solution_Mergesort{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
    vector<int> Merge(vector<int> &data,int start,int mid, int end){
        //设置左右两个指针
        int i = start;
        int j = mid+1;
        int k = 0;
        int count = 0;
        vector<int> temp(end-start+1,0);   //设置一个辅助栈
        while(i<=mid && j <=end){
            if(data[i]>data[j]){
                count +=  mid-i+1;
                temp[k++] = data[j++];
            }
            else{
                temp[k++] = data[i++];
            }
        }
        //如果还有多的补上
        while(i<=mid)
            temp[k++] = data[i++];
        while(j<=end)
            temp[k++] = data[j++];
        for (int l = 0; l < temp.size(); ++l) {
            //注意事项start
            data[start+l] = temp[l];
        }
        return data;
    }

    vector<int> Mergesort(vector<int> &data,int start,int end){
        if(start == end)
            return data;
        int mid = (start+end)/2;
        data = Mergesort(data,start,mid);
        data = Mergesort(data,mid+1,end);
        data = Merge(data,start,mid,end);
        return data;
    }

};

//int main() {
//    Solution_Mergesort solution;
//    vector<int> l = {60, 50, 90, 30, 70, 40, 80, 75};
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = solution.Mergesort(l, 0, l.size() - 1);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout <<sort_l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}

