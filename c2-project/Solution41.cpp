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

class Solution {
private:
    priority_queue <int,vector<int>,greater<int> > small;
    priority_queue <int,vector<int>,less<int> > large;
public:
    void Insert(int num)
    {
        large.push(num);
        small.push(large.top());
        large.pop();
        if(large.size()< small.size()){
            int tmp = small.top();
            small.pop();
            large.push(tmp);
        }
    }

    double GetMedian()
    {
        if(large.size()!=small.size()){
            return large.top();
        }
        else{
            return double((large.top() + small.top())/2.0);
        }
    }

};

//int main(){
//    vector<int> l = {2,4,6,3,5};
//    Solution solution;
//    solution.Insert(2);
//    solution.Insert(4);
//    solution.Insert(6);
//    solution.Insert(3);
//    solution.Insert(5);
//    double x = solution.GetMedian();
//    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}

