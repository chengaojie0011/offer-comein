//
// Created by 陈高杰 on 2020/3/24.
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}

};

//int main()
//{
//    TreeNode t1 = TreeNode(10);
//    TreeNode t2 = TreeNode(5);
//    TreeNode t3 = TreeNode(12);
//    TreeNode t4 = TreeNode(4);
//    TreeNode t5 = TreeNode(7);
//    t1.left = &t2;
//    t1.right = &t3;
//    t2.left = &t4;
//    t2.right = &t5;
////    cout << t1.right->val << endl;
////    Solution solution;
////    vector<vector<int> > output;
////    output = solution.FindPath(&t1,22);
////    cout << "output:" << output<< endl;
//    system("PAUSE");
//    return 0;
//}