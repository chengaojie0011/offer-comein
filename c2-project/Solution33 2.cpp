//
// Created by 陈高杰 on 2020/2/6.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length = sequence.size();
        if(length <= 0 || sequence.empty()){
            return false;
        }
        int root = sequence.back();
        int i = 0;
        for (; i < length-1; ++i) {
            if(sequence[i]>root){
                break;
            }
        }

        int j = i;
        for (; j < length-1; ++j) {
            if(sequence[j]<root){
                return false;
            }
        }

        bool left = true;
        bool right = true;
        vector<int> leftTree,rightTree;
        if(i>0) {
            for (int m = 0; m < i; ++m) {
                leftTree.push_back(sequence[m]);
            }
            left = VerifySquenceOfBST(leftTree);
        }
        if(i<length-1) {
            for (int m = i; m < length-1; ++m) {
                rightTree.push_back(sequence[m]);
            }
            right = VerifySquenceOfBST(rightTree);
        }

        return left && right;
    }
};

//int main()
//{
//    vector<int> s = {5,7,6,9,11,10,8};
//    Solution solution;
//    bool output;
//    output = solution.VerifySquenceOfBST(s);
//    cout << "output:" <<output << endl;
//    system("PAUSE");
//    return 0;
//}
