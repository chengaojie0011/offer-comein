#include <iostream>
#include <stdlib.h>
#include <string>
#include "Solution5.h"
//#include "Solution3.cpp"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	//ListNode(int x) :
	//	val(x), next(NULL) {
	//}
};

void AddToTail(ListNode** pHead, int value){
	ListNode* pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr)
		{
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}

void RemoveNode(ListNode** pHead,int value){
	if (*pHead == nullptr)
	{
		return;
	}

	ListNode* p_tobedel = nullptr;

	if ((*pHead)->val == value)
	{
		p_tobedel = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr&&pNode->next->val !=value)
		{
			pNode = pNode->next;
		}


		if (pNode->next != nullptr&&pNode->next->val == value)
		{
			p_tobedel = pNode->next;
			pNode->next = pNode->next->next;
		}
	}
	if (p_tobedel!=nullptr)
	{
		delete p_tobedel;
		p_tobedel = nullptr;
	}

}


int main()
{
	ListNode* p = nullptr;
	//Solution6 solution;
	bool output;

	AddToTail(&p,1);
	AddToTail(&p, 2);
	AddToTail(&p, 3);
	AddToTail(&p, 4);
	RemoveNode(&p, 2);
	RemoveNode(&p, 4);
	while (p != nullptr)
	{
		cout << p->val << endl;
		p = p->next;
	}

	system("PAUSE");
	return 0;
}