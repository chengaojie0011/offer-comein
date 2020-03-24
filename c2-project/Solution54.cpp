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

class Solution1 {
private:
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr || k<=0)
            return nullptr;
        TreeNode* node = nullptr;
        node = KthNode(pRoot->left, k);
        if(node!= nullptr)
            return node;
        count++;
        if(count ==k){
            return pRoot;
        }
        node = KthNode(pRoot->right, k);
        return node;
    }

};

class Solution2 {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr || k<=0)
            return nullptr;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec,k);
        //
        if(k>vec.size())
            return nullptr;
        return vec[k-1];
    }
    void Inorder(TreeNode* pRoot,vector<TreeNode*> &vec,int k){
        if(pRoot==nullptr)
            return;
        Inorder(pRoot->left,vec,k);
        vec.push_back(pRoot);
        if(vec.size()==k)
            return;
        Inorder(pRoot->right,vec,k);
        return;
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==nullptr || k<=0)
            return nullptr;
        vector<TreeNode*> vec;
        Inorder(pRoot,vec,k);
        if(k>vec.size())
            return nullptr;
        return vec[k-1];
    }
    void Inorder(TreeNode* pRoot,vector<TreeNode*> &vec,int k){
        if(pRoot==nullptr)
            return;
        vector <TreeNode*> stack1;
        while(!stack1.empty() || pRoot !=nullptr){
            if(pRoot !=nullptr){
                stack1.push_back(pRoot);
                pRoot = pRoot->left;
            }
            else{
                TreeNode* node = stack1.back();
                stack1.pop_back();
                vec.push_back(node);
                if(vec.size()==k)
                    return;
                pRoot = node->right;
            }
        }
        return;
    }
};

//int main(){
//    TreeNode TreeNode1 = TreeNode(5);
//    TreeNode TreeNode2 = TreeNode(3);
//    TreeNode TreeNode3 = TreeNode(7);
//    TreeNode TreeNode4 = TreeNode(2);
//    TreeNode TreeNode5 = TreeNode(4);
//    TreeNode TreeNode6 = TreeNode(6);
//    TreeNode TreeNode7 = TreeNode(8);
//    TreeNode1.left = &TreeNode2;
//    TreeNode1.right = &TreeNode3;
//    TreeNode2.left = &TreeNode4;
//    TreeNode2.right = &TreeNode5;
//    TreeNode3.left = &TreeNode6;
//    TreeNode3.right = &TreeNode7;
//    Solution solution;
//    int k = 3;
//    TreeNode* x = solution.KthNode(&TreeNode1,k);
//    cout<< x->val<<endl;
//    system("PAUSE");
//    return 0;
//}