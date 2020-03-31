//
// Created by 陈高杰 on 2020/2/10.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution_Qsort{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
    int RandInRange(int start,int end){
        srand(time(NULL));
        return rand()%(end-start+1)+start;
    }
    //1.small代表已经确定的比index小的数
    int Partition(vector<int> &data, int start, int end){
        if(data.empty() ||data.size()<=0 ||start<0 || end >= data.size())
            return -1;
//        int index = RandInRange(start,end);
//        Swap(data[index],data[end]);
        int index = end;
        int small = start-1;
        //记得从start开始
        for (int i = start; i < end; ++i) {
            if(data[i]<data[end]){
                small++;
                if(small!=i)
                    Swap(data[i],data[small]);
            }
        }
        small++;
        Swap(data[end],data[small]);
        return small;
    }
    //1.先随机选出一个数，然后别的数分别放到其左右两边，按大小；
    //2.然后左右分别快排
    vector<int> Qsort(vector<int> &data, int start, int end){
        if(start == end )
            return data;
        int index  = Partition(data, start,end);
        if(index>start)
            data = Qsort(data,start,index-1);
        if(index<end)
            data = Qsort(data,index+1,end);
        return data;
    }
};

//int main() {
//    Solution_Qsort solution;
//    vector<int> l = {10, 50, 90, 30, 70, 40, 80, 60};
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = solution.Qsort(l, 0, l.size() - 1);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout << sort_l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//
//}
