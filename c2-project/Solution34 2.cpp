//
// Created by 陈高杰 on 2020/2/6.
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
    vector<vector<int> > res;
    void FindPathIn(TreeNode* root,vector<int> path, int expectNumber,int currentNumber){
        currentNumber += root->val;
        path.push_back(root->val);
        bool isleaf = root->left == nullptr && root->right == nullptr;
        if(isleaf && currentNumber ==expectNumber){
            res.push_back(path);
        }
        if(root->left != nullptr){
            FindPathIn(root->left,path,expectNumber,currentNumber);
        }
        if(root->right != nullptr){
            FindPathIn(root->right,path,expectNumber,currentNumber);
        }
        path.pop_back();
        return;
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr){
            return res;
        }
        vector<int> path;
        int  currentNumber = 0;
        FindPathIn(root,path,expectNumber,currentNumber);
        return res;
    }
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
//    Solution solution;
//    vector<vector<int> > output;
//    output = solution.FindPath(&t1,22);
////    cout << "output:" << output<< endl;
//    system("PAUSE");
//    return 0;
//}
