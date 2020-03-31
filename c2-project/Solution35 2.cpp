//
// Created by 陈高杰 on 2020/2/6.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* CloneNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode!= nullptr){
            RandomListNode* pCopy = new RandomListNode(pNode->label);
//            pCopy->label = pNode->label;
            pCopy->next = pNode->next;
            pCopy->random = nullptr;
            pNode->next = pCopy;
            pNode = pNode->next->next;
        }
        return pHead;
    }

    RandomListNode* AddRandom(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode!= nullptr){
            if(pNode->random){
                RandomListNode* pCopy =  pNode->next;
                pCopy->random = pNode->random->next;
            }
            pNode = pNode->next->next;
        }
        return pHead;
    }

    RandomListNode* SplitNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pHead2 = pHead->next;
        while(pNode){
            RandomListNode* pNode2 = pNode->next;
            RandomListNode* pNode_nextnext = pNode2->next;
            pNode->next = pNode_nextnext;
            if(pNode2->next){
                pNode2->next = pNode2->next->next;
            }
            else{
                pNode2->next = nullptr;
            }
            pNode =pNode_nextnext;
        }
        return pHead2;
    }


    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead== nullptr){
            return nullptr;
        }
        RandomListNode* pHead2 = nullptr;
        pHead2 = CloneNode(pHead);
        pHead2 = AddRandom(pHead2);
        pHead2 = SplitNode(pHead2);
        return pHead2;
    }
};

//int main()
//{
//    RandomListNode listNode11 = RandomListNode(1);
//    RandomListNode listNode12 = RandomListNode(2);
//    RandomListNode listNode13 = RandomListNode(3);
//    RandomListNode listNode14 = RandomListNode(4);
//    RandomListNode listNode15 = RandomListNode(5);
//
//    listNode11.next = &listNode12;
//    listNode12.next = &listNode13;
//    listNode13.next = &listNode14;
//    listNode14.next = &listNode15;
//
//    listNode11.random = &listNode13;
//    listNode12.random  = &listNode15;
//    listNode14.random = &listNode12;
//    Solution solution;
//    RandomListNode*  output;
//    output = solution.Clone(&listNode11);
//
//    RandomListNode* pnode = output;
////    RandomListNode* pnode = &listNode11;
//    while(pnode != nullptr){
//        cout << pnode->label << endl;
//        pnode = pnode->next;
//    }
//
//    system("PAUSE");
//    return 0;
//}
