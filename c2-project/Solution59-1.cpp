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
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> max_in_window;
        if(num.size()<size || size<1){
            return max_in_window;
        }
        deque<int> index;
        for (int i = 0; i < size; ++i) {
            while(!index.empty() && num[i]>=num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        max_in_window.push_back(num[index.front()]);
        for (int j = size; j < num.size(); ++j) {
            while(!index.empty() && num[j]>=num[index.back()])
                index.pop_back();
            if(!index.empty() && index.front()<=j-size)
                index.pop_front();
            index.push_back(j);
            max_in_window.push_back(num[index.front()]);
        }
        return max_in_window;
    }
};

//int main(){
//    Solution solution;
//    vector<int> k = {2,3,4,2,6,2,5,1};
//    vector<int> n1;
//    n1 = solution.maxInWindows(k,3);
//    for (int i = 0; i < n1.size(); ++i) {
//        cout<< n1[i];
//    }
//    system("PAUSE");
//    return 0;
//}

