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

/*使用循环实现*/

class Solution6_1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        stack <ListNode*> stk;
        ListNode* node = head;
        while (node!=nullptr)
        {
            stk.push(node);
            node = node->next;
        }
        while (!stk.empty())
        {
            //cout << (stk.top())->val<< endl;
            vec.push_back((stk.top())->val);
            stk.pop();
        }
        return vec;
    }
};

/*使用递归实现*/

class Solution6_2 {
public:
    vector<int> vec;
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head != nullptr)
        {
            if (head->next != nullptr)
            {
                vector<int> temp = printListFromTailToHead(head->next);
            }
            vec.push_back(head->val);
        }
        return vec;
    }
};

class Solution6_3 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> inverse;
        if (head == nullptr){
            return  inverse;
        }
        ListNode *p = head;
        ListNode *q = p->next;
        p->next = NULL;
        while (q != NULL)
        {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        while (p != NULL)
        {
            inverse.push_back(p->val);
            p = p->next;
        }
        return inverse;

    }
};


//int main()
//{
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(2);
//	ListNode* l3 = new ListNode(3);
//
//	l1->next = l2;
//	l2->next = l3;
//
//
//	Solution6_3 solution;
//	bool output;
//
//	ListNode* nodes = l1;
//	while (nodes != nullptr)
//	{
//		cout << nodes->val << endl;
//		nodes = nodes->next;
//
//	}
//	cout << "listnode over" << endl;
//
//	vector<int> vec_cout = solution.printListFromTailToHead(l1);
//
//	auto iter = vec_cout.begin();
//	while (iter != vec_cout.end())
//	{
//		cout << *iter << endl;
//		++iter;
//	}
//	system("PAUSE");
//	return 0;
//}

