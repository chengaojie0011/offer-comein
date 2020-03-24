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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k<=0 || pListHead== nullptr){
            return nullptr;
        }
        ListNode* node1 = pListHead;
        ListNode* node2 = pListHead;
        for (int i = 0; i < k-1; ++i) {
            if(node1->next != nullptr){
                node1 = node1->next;
            }
            else{
                return nullptr;
            }
        }
        while(node1->next != nullptr){
            node1 = node1->next;
            node2 = node2->next;
        }
        return node2;

    }
};


//int main()
//{
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(2);
//	ListNode* l3 = new ListNode(3);
//    ListNode* l4 = new ListNode(4);
//    ListNode* l5 = new ListNode(5);
//    ListNode* l6 = new ListNode(6);
//
//	l1->next = l2;
//	l2->next = l3;
//    l3->next = l4;
//    l4->next = l5;
//    l5->next = l6;
//
//
//	Solution solution;
//    ListNode* output = nullptr;
//
//	ListNode* nodes = l1;
//	while (nodes != nullptr)
//	{
//		cout << nodes->val << endl;
//		nodes = nodes->next;
//
//	}
//	cout << "listnode over" << endl;
//    output = solution.FindKthToTail(l1,3);
//
//    cout << output->val << endl;
//	system("PAUSE");
//	return 0;
//}

