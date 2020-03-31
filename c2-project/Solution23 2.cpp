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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while(fast->next != nullptr && fast != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode* slow2 = pHead;
                while(slow2 != slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }

        }
        return nullptr;
    }
};

//int main()
//{
//    ListNode* l1 = new ListNode(1);
//    ListNode* l2 = new ListNode(2);
//    ListNode* l3 = new ListNode(3);
//    ListNode* l4 = new ListNode(4);
//    ListNode* l5 = new ListNode(5);
//    ListNode* l6 = new ListNode(6);
//
//    l1->next = l2;
//    l2->next = l3;
//    l3->next = l4;
//    l4->next = l5;
//    l5->next = l6;
//    l6->next = l3;
//
//    Solution solution;
//    ListNode* output = nullptr;
//
//    ListNode* nodes = l1;
////    while (nodes != nullptr)
////    {
////        cout << nodes->val << endl;
////        nodes = nodes->next;
////
////    }
//    cout << "listnode over" << endl;
//    output = solution.EntryNodeOfLoop(l1);
//
//    cout << output->val << endl;
//    system("PAUSE");
//    return 0;
//}

