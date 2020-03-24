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

int randomInRange(int start,int end)
{
    srand ( time(NULL) );
    return rand() % (end-start+1) + start;

}
void Swap(int &data1,int &data2){
    int temp = data1;
    data1 = data2;
    data2 = temp;
}

int Partition(vector<int> &data,int length,int start, int end){
    if(data.empty() || length<=0 || start<0 || end >=length){
        return -1;
    }
    int index = randomInRange(start,end);
    Swap(data[index],data[end]);
    int small = start-1;
    for (int i = start; i < end; ++i) {
        if(data[i]<data[end]){
            small++;
            if(small !=i){
                Swap(data[small],data[i]);
            }
        }
    }
    small++;
    Swap(data[small],data[end]);
    return small;
}

vector<int> QuickSort(vector<int> &data,int length,int start, int end){
    if(start == end){
        return data;
    }
    int index = Partition(data, length, start, end);
    if(index > start)
        data = QuickSort(data,length,start,index-1);
    if(index < end)
        data = QuickSort(data,length,index+1,end);
    return data;
}

//int main(){
//    vector<int> l = {2,4,6,3,5};
//    int x = Partition(l, 5, 0, 4);
//    cout << x<< endl;
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = QuickSort(l, 5, 0, 4);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout << sort_l[i] ;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//
//}
