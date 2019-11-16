//
// Created by 陈高杰 on 2019-11-15.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr or pHead->next== nullptr){
            return pHead;
        }
        ListNode* new_head = new ListNode(-1);
        new_head->next = pHead;
        ListNode* pnode = pHead;
        ListNode* pre = new_head;
        ListNode* next = nullptr;
        while(pnode != nullptr && pnode->next != nullptr){
            next = pnode->next;
            if(next->val == pnode->val){
                while(next != nullptr && next->val == pnode->val) {
                    next = next->next;
                }
                pnode = next;
                pre->next = pnode;

            }
            else{
                pre = pnode;
                pnode = next;
            }
        }
        ListNode* output = new_head->next;
        delete new_head;
        return output;
    }
};

//int main()
//{
//    ListNode* l1 = new ListNode(1);
////    ListNode* l2 = new ListNode(2);
////    ListNode* l3 = new ListNode(2);
////    ListNode* l4 = new ListNode(3);
////    ListNode* l5 = new ListNode(1);
////    l1->next = l2;
////    l2->next = l3;
////    l3->next = l4;
////    l4->next = l5;
//    ListNode* pnode = l1;
//    while(pnode){
//        cout << pnode->val << endl;
//        pnode = pnode->next;
//    }
//    Solution solution;
//    ListNode* pnode2 = solution.deleteDuplication(l1);
//    while(pnode2){
//        cout << pnode2->val << endl;
//        pnode2 = pnode2->next;
//    }
//    return 0;
//}