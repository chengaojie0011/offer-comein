# -*- coding:utf-8 -*-
import functools
import sys

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        length1 = self.GetListLength(pHead1)
        length2 = self.GetListLength(pHead2)
        diffidx = length1 - length2
        pLong = pHead1
        pShort = pHead2

        if diffidx <0:
            pLong = pHead2
            pShort = pHead1
            diffidx = length2 - length1

        for i in range(diffidx):
            pLong = pLong.next

        while pLong != None and pShort != None and pLong != pShort:
            pLong = pLong.next
            pShort = pShort.next

        pNode = pLong
        return pNode

    def GetListLength(self,pNode):
        length = 0
        while pNode != None:
            pNode = pNode.next
            length +=1
        return length


if __name__ == '__main__':
    ListNode1 = ListNode(1)
    ListNode2 = ListNode(2)
    ListNode3 = ListNode(3)
    ListNode4 = ListNode(4)
    ListNode5 = ListNode(5)
    ListNode6 = ListNode(6)
    ListNode7 = ListNode(7)

    ListNode1.next = ListNode2
    ListNode2.next = ListNode3
    ListNode3.next = ListNode6
    ListNode4.next = ListNode5
    ListNode5.next = ListNode6
    ListNode6.next = ListNode7

    # print(len(l))
    solution1 = Solution()
    a = solution1.FindFirstCommonNode(ListNode1,ListNode4)
    print(a.val)