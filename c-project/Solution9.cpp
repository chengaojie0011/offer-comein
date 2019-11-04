//
// Created by 陈高杰 on 2019-10-30.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp = 0;
        if(stack2.size()==0){
            while(stack1.size()>0){
                temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int head = stack2.top();
        stack2.pop();
        return head;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

// int main()
// {
//    vector <int> pre = {1,2,4,7,3,5,6,8};
//    vector <int> vin = {4,7,2,1,5,3,8,6};
//    cout << pre[0] << endl;
//    Solution solution;
// 	return 0;
// }