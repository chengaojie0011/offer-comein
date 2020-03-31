//
// Created by 陈高杰 on 2020/2/8.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr){
            return nullptr;
        }
        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr){
            return pRootOfTree;
        }
        TreeNode* left = nullptr;
        left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        while(left != nullptr && p->right != nullptr){
            p = p->right;
        }
        if(left != nullptr){
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        TreeNode* right = nullptr;
        right = Convert(pRootOfTree->right);
        if(right != nullptr){
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }
        if(left != nullptr){
            return left;
        }
        else{
            return pRootOfTree;
        }
    }
};


//int main()
//{
//    TreeNode TreeNode1 = TreeNode(10);
//    TreeNode TreeNode2 = TreeNode(6);
//    TreeNode TreeNode3 = TreeNode(14);
//    TreeNode TreeNode4 = TreeNode(4);
//    TreeNode TreeNode5 = TreeNode(8);
//    TreeNode TreeNode6 = TreeNode(12);
//    TreeNode TreeNode7 = TreeNode(16);
//
//    TreeNode1.left = &TreeNode2;
//    TreeNode1.right = &TreeNode3;
//    TreeNode2.left = &TreeNode4;
//    TreeNode2.right = &TreeNode5;
//    TreeNode3.left = &TreeNode6;
//    TreeNode3.right = &TreeNode7;
//
//    Solution solution;
//    TreeNode*  output;
//    output = solution.Convert(&TreeNode1);
//
//    TreeNode* pnode = output;
////    TreeNode* pnode = &TreeNode11;
//    while(pnode != nullptr){
//        cout << pnode->val << endl;
//        pnode = pnode->right;
//    }
//
//    system("PAUSE");
//    return 0;
//}
