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

class Solution_Bubblesort{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
    vector<int> Bubblesort(vector<int> &data, int start, int end){
        int len = data.size();
        for (int i = 0; i < len-1; ++i) {
            for (int j = len-1; j > i ; --j) {
                if(data[j]<data[j-1])
                    Swap(data[j],data[j-1]);
            }
        }
        return data;
    }
};

//int main() {
//    Solution_Bubblesort solution;
//    vector<int> l = {60, 50, 90, 30, 70, 40, 80, 75};
////    for (int i = 0; i < l.size(); ++i) {
////        cout << l[i] ;
//////        cout << " "<< endl;
////    }
//    vector<int> sort_l = solution.Bubblesort(l, 0, l.size() - 1);
//    for (int i = 0; i < sort_l.size(); ++i) {
//        cout <<sort_l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}

