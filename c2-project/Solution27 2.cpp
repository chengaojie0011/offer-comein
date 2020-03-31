//
// Created by 陈高杰 on 2020/1/30.
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr){
            return;
        }
        TreeNode *tmp = nullptr;
        tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        if(pRoot->left){
            Mirror(pRoot->left);
        }
        if(pRoot->right){
            Mirror(pRoot->right);
        }
        return;
    }
};

//int main()
//{
//    ListNode* l11 = new ListNode(1);
//    ListNode* l12 = new ListNode(3);
//    ListNode* l13 = new ListNode(5);
//    ListNode* l14 = new ListNode(7);
//
//    ListNode* l21 = new ListNode(2);
//    ListNode* l22 = new ListNode(4);
//    ListNode* l23 = new ListNode(6);
//    ListNode* l24 = new ListNode(8);
//
//    l11->next = l12;
//    l12->next = l13;
//    l13->next = l14;
//
//    l21->next = l22;
//    l22->next = l23;
//    l23->next = l24;
//
//    Solution solution;
//    ListNode* output = nullptr;
//
//    ListNode* nodes1 = l11;
//    while (nodes1 != nullptr)
//    {
//        cout << nodes1->val << endl;
//        nodes1 = nodes1->next;
//
//    }
//    ListNode* nodes2 = l21;
//    while (nodes2 != nullptr)
//    {
//        cout << nodes2->val << endl;
//        nodes2 = nodes2->next;
//
//    }
//    cout << "listnode over" << endl;
//
//    output = solution.Merge(l11,l21);
////    cout << output->val << endl;
//    while (output != nullptr)
//    {
//        cout << output->val << endl;
//        output = output->next;
//
//    }
//    system("PAUSE");
//    return 0;
//}

