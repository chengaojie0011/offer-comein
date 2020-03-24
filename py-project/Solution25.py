# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        if pHead1 == None:
            return pHead2
        elif pHead2 == None:
            return pHead1

        node = None
        if pHead1.val < pHead2.val:
            node = pHead1
            node.next = self.Merge(pHead1.next,pHead2)
        else:
            node = pHead2
            node.next = self.Merge(pHead1,pHead2.next)
        return node





if __name__ == "__main__":

    listNode11 = ListNode(1)
    listNode12 = ListNode(3)
    listNode13 = ListNode(5)
    listNode14 = ListNode(7)

    listNode21 = ListNode(2)
    listNode22 = ListNode(4)
    listNode23 = ListNode(6)
    listNode24 = ListNode(8)

    listNode11.next = listNode12
    listNode12.next = listNode13
    listNode13.next = listNode14

    listNode21.next = listNode22
    listNode22.next = listNode23
    listNode23.next = listNode24


    node = listNode11
    while node != None:
        print(node.val)
        node = node.next

    node = listNode21
    while node != None:
        print(node.val)
        node = node.next

    solution1 = Solution()
    a = solution1.Merge(listNode11,listNode21)
    # print(a.val)
    while a != None:
        print(a.val)
        a = a.next