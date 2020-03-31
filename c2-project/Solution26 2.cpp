//
// Created by 陈高杰 on 2020/1/30.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr){
            return pHead2;
        }
        else if(pHead2 == nullptr){
            return pHead1;
        }
        ListNode* node = nullptr;
        if(pHead1->val < pHead2->val){
            node = pHead1;
            node->next = Merge(pHead1->next,pHead2);
        }
        else{
            node = pHead2;
            node->next = Merge(pHead1,pHead2->next);
        }
        return node;

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

