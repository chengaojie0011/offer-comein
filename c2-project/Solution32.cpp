//
// Created by 陈高杰 on 2020/2/5.
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> queue;
        if(root == nullptr){
            return res;
        }
        queue.push_back(root);
        int p =0;
        while(p < queue.size()){
            TreeNode* node = queue[p];
            p++;
            res.push_back(node->val);
            if(node->left){
                queue.push_back(node->left);
            }
            if(node->right){
                queue.push_back(node->right);
            }
        }
        return res;
    }
};

// 题目二：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
//返回二维列表[[1,2],[4,5]]
class Solution2 {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == nullptr) {
            return result;
        }
        vector<TreeNode*> queue = {pRoot};

        while(!queue.empty()){
            vector<int> res;
            vector<TreeNode*> next_q;
            for (int i = 0; i < queue.size(); ++i) {
                res.push_back(queue[i]->val);
                if(queue[i]->left){
                    next_q.push_back(queue[i]->left);
                }
                if(queue[i]->right){
                    next_q.push_back(queue[i]->right);
                }
            }
            queue = next_q;
            result.push_back(res);
        }
        return result;
    }

};

class Solution3 {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == nullptr) {
            return result;
        }
        vector<TreeNode*> stack1;
        stack1.push_back(pRoot);
        vector<TreeNode*> stack2;
        while(!stack1.empty() || !stack2.empty()){
            vector<int> res1,res2;
            TreeNode* node = nullptr;
            while(!stack1.empty() ){
                node = stack1.back();
                res1.push_back(node->val);
                if(node->left){
                    stack2.push_back(node->left);
                }
                if(node->right){
                    stack2.push_back(node->right);
                }
                stack1.pop_back();
            }
            if(!res1.empty()){
                result.push_back(res1);
            }
            while(!stack2.empty() ){
                node = stack2.back();
                res2.push_back(node->val);
                if(node->right){
                    stack1.push_back(node->right);
                }
                if(node->left){
                    stack1.push_back(node->left);
                }
                stack2.pop_back();
            }
            if(!res2.empty()){
                result.push_back(res2);
            }
        }
        return result;
    }
};

//int main()
//{
////    vector<int> pushv = {1,2,3,4,5};
////    vector<int> popv = {4,5,3,2,1};
////    Solution solution;
////    bool output;
////    output = solution.IsPopOrder(pushv,popv);
//    cout << "output" << endl;
//    system("PAUSE");
//    return 0;
//}