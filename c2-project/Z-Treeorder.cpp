//
// Created by 陈高杰 on 2020/3/26.
//


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution{
public:
    void Swap(int &data1, int &data2){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
    void preorder_r(TreeNode* root,vector<int> &ret)
    {
        if(root == nullptr)
            return;
        ret.push_back(root->val);
        cout<<root->val<<endl;
        preorder(root->left , ret);
        preorder(root->right , ret);
        return;
    }

    //前序遍历
    void preorder(TreeNode* root,vector<int> &ret)
    {
        vector<TreeNode*> stack;
        TreeNode* p = root;
        while(p || !stack.empty()){
            if(p){
                stack.push_back(p); //父节点压入栈
                ret.push_back(p->val);
                p = p->left;
            }
            else{
                p = stack.back(); //回到父节点
                stack.pop_back(); //回到父节点，出栈
                p = p->right;
            }
        }
        return;
    }

    //中序遍历
    void inorder(TreeNode* root,vector<int> &ret)
    {
        vector<TreeNode*> stack;
        TreeNode* p = root;
        while(p || !stack.empty()){
            if(p){
                stack.push_back(p);
                p = p->left;
            }
            else{
                p = stack.back();
                stack.pop_back();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        return;
    }
    //后序遍历
    void postorder(TreeNode* root,vector<int> &ret)
    {
        vector<TreeNode*> stack;
        TreeNode* p = root;
        while(p || !stack.empty()){
            if(p){
                stack.push_back(p);
                ret.push_back(p->val);
                p = p->right;
            }
            else{
                p = stack.back();
                stack.pop_back();
                p = p->left;
            }
        }
        reverse(ret.begin(),ret.end());
        return;
    }
    //层序遍历
    void levelorder(TreeNode* root,vector<int> &ret)
    {
        queue<TreeNode*> queue;
        TreeNode* p = root;
        queue.push(p);
        while(!queue.empty()){
            p = queue.front();
            queue.pop();
            ret.push_back(p->val);
            if(p->left)
                queue.push(p->left);
            if(p->right)
                queue.push(p->right);
        }
        return;
    }


};


//int main() {
//    Solution solution;
//    TreeNode t1 = TreeNode(1);
//    TreeNode t2 = TreeNode(2);
//    TreeNode t3 = TreeNode(3);
//    TreeNode t4 = TreeNode(4);
//    TreeNode t5 = TreeNode(5);
//    TreeNode t6 = TreeNode(6);
//    TreeNode t7 = TreeNode(7);
//    TreeNode t8 = TreeNode(8);
//
//    t1.left = &t2;
//    t1.right = &t3;
//    t2.left = &t4;
//    t4.right = &t7;
//    t3.left = &t5;
//    t3.right = &t6;
//    t6.left = &t8;
//
//    vector<int> l;
//    solution.levelorder(&t1,l);
//    cout<<"-------------------"<<endl;
//    for (int i = 0; i < l.size(); ++i) {
//        cout <<l[i] << endl;
////        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}

