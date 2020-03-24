//
// Created by 陈高杰 on 2020/2/16.
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


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int length1 = GetListLength(pHead1);
        int length2 = GetListLength(pHead2);
        int difidx = length1 - length2;
        ListNode* pLong = pHead1;
        ListNode* pShort = pHead2;
        if(length1<length2){
            ListNode* pLong = pHead2;
            ListNode* pShort = pHead1;
            difidx = length2 - length1;
        }

        for (int i = 0; i < difidx; ++i) {
            pLong = pLong->next;
        }
        while(pLong!= nullptr && pShort!= nullptr && pLong!=pShort){
            pLong = pLong->next;
            pShort = pShort->next;
        }
        ListNode* pCommon = pLong;
        return pCommon;
    }

    int GetListLength(ListNode* pHead1) {
        int length = 0;
        ListNode* pNode = pHead1;
        while(pNode !=nullptr){
            length++;
            pNode = pNode->next;
        }
        return length;
    }
};

//int main(){
//    ListNode ListNode1 = ListNode(1);
//    ListNode ListNode2 = ListNode(2);
//    ListNode ListNode3 = ListNode(3);
//    ListNode ListNode4 = ListNode(4);
//    ListNode ListNode5 = ListNode(5);
//    ListNode ListNode6 = ListNode(6);
//    ListNode ListNode7 = ListNode(7);
//
//    ListNode1.next = &ListNode2;
//    ListNode2.next = &ListNode3;
//    ListNode3.next = &ListNode6;
//    ListNode6.next = &ListNode7;
//
//    ListNode4.next = &ListNode5;
//    ListNode5.next = &ListNode6;
//
//    Solution solution;
//    ListNode* x = solution.FindFirstCommonNode(&ListNode1,&ListNode4);
//    cout<< x->val<<endl;
//    system("PAUSE");
//    return 0;
//}
