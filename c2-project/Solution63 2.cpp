//
// Created by 陈高杰 on 2020/3/22.
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
#include <list>
using namespace std;

class Solution {
public:
    int MaxDiff(vector<int> n)
    {
        if(n.size()<2 || n.empty())
            return -1;
        int min = n[0];
        int maxdiff = n[1]-min;
        for (int i = 2; i < n.size(); ++i) {
            if(n[i-1]<min)
                min = n[i-1];
            int temp = n[i]-min;
            if(temp>maxdiff)
                maxdiff = temp;
        }
        return maxdiff;
    }
};

//int main(){
//    Solution solution;
//    vector<int> a = {9,11,8,5,7,12,16,14};
//    int n1;
//    n1 = solution.MaxDiff(a);
////    for (int i = 0; i < n1.size(); ++i) {
////        cout<< n1[i];
////    }
//    cout<< n1;
//    system("PAUSE");
//    return 0;
//}

