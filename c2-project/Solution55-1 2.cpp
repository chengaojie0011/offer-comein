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


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int depth = 0;
        if(pRoot == nullptr)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
};

//
//int main(){
//    TreeNode TreeNode1 = TreeNode(1);
//    TreeNode TreeNode2 = TreeNode(2);
//    TreeNode TreeNode3 = TreeNode(3);
//    TreeNode TreeNode4 = TreeNode(4);
//    TreeNode TreeNode5 = TreeNode(5);
//    TreeNode TreeNode6 = TreeNode(6);
//    TreeNode TreeNode7 = TreeNode(7);
//    TreeNode1.left = &TreeNode2;
//    TreeNode1.right = &TreeNode3;
//    TreeNode2.left = &TreeNode4;
//    TreeNode2.right = &TreeNode5;
//    TreeNode3.right = &TreeNode6;
//    TreeNode5.left = &TreeNode7;
//
//    Solution solution;
//    int k = 3;
//    int x = solution.TreeDepth(&TreeNode1);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}