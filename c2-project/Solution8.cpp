//
// Created by 陈高杰 on 2019-10-29.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr){
            return nullptr;
        }
        if(pNode->right != nullptr){
            pNode = pNode->right;
            while(pNode->left != nullptr){
                pNode = pNode->left;
            }
            return pNode;
        }
        else{
            while(pNode->next){
                TreeLinkNode* root = pNode->next;
                if(root->left==pNode){
                    return root;
                }
                pNode = pNode->next;
            }
        }
        return nullptr;

    }
};

// int main()
// {
//    vector <int> pre = {1,2,4,7,3,5,6,8};
//    vector <int> vin = {4,7,2,1,5,3,8,6};
//    cout << pre[0] << endl;
//    Solution solution;
//    TreeNode* tree;
//    tree = solution.reConstructBinaryTree(pre,vin);
//
//
// 	return 0;
// }




