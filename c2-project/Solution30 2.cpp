//
// Created by 陈高杰 on 2020/1/30.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    stack<int> s;
    stack<int> s_min;
    void push(int value) {
        int min = 0;
        min = s_min.top();
        s.push(value);
        if(s_min.empty() || value < s_min.top()){
            s_min.push(value);
        }
        else{
            s_min.push(s_min.top());
        }
        s.push(value);
    }
    void pop() {
        if(!s.empty())
            s.pop();
            s_min.pop();
    }
    int top() {
        if(!s.empty()){
            return s.top();
        }
    }
    int min() {
        if(!s_min.empty()){
            return s_min.top();
        }
    }
};

//int main()
//{
////    vector<vector<int>> data = { { 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9, 10, 11, 12}, { 13, 14, 15, 16}};
//    vector<vector<int>> data = {{1},{2},{3},{4},{5}};
//    cout << "listnode over" << endl;
//    Solution solution;
//    vector<int> output;
//    output = solution.printMatrix(data);
//    int col = data[0].size();
//    int row = data.size();
//    cout << "col:" << col << endl;
//    cout << "row:" << row << endl;
////    output = {1,2,3,4,5};
//    for (int i = 0; i < col *row; ++i) {
//        cout << output[i] << endl;
//    }
//
//    system("PAUSE");
//    return 0;
//}

