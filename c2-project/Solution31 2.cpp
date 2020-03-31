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
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(!pushV.empty() && !popV.empty()){
            vector<int> stack;
            int j = 0;
            for (int i = 0; i < pushV.size(); ++i) {
                int x =  pushV[i];
                stack.push_back(x);
                while(j < popV.size() && stack.back() == popV[j]){
                    stack.pop_back();
                    j++;
                }
            }
            return  stack.empty();
        }
        return false;
    }
};

//int main()
//{
//    vector<int> pushv = {1,2,3,4,5};
//    vector<int> popv = {4,5,3,2,1};
//    Solution solution;
//    bool output;
//    output = solution.IsPopOrder(pushv,popv);
//    cout << output << endl;
//    system("PAUSE");
//    return 0;
//}