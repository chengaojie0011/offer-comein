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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        if(TreeDepth(pRoot) !=-1)
            return true;
        else
            return false;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        int depth = 0;
        if(pRoot == nullptr)
            return 0;
        int left = TreeDepth(pRoot->left);
        if(left ==-1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if(right == -1)
            return -1 ;
        if(abs(left - right)>1)
            return -1;
        return (left > right ? left : right) + 1;
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
//    int x = solution.IsBalanced_Solution(&TreeNode1);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}