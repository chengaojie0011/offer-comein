# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        if pHead == None or pHead ==None:
            return pHead
        pre = None
        cur = pHead
        while cur != None:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre



if __name__ == "__main__":

    listNode1 = ListNode(1)
    listNode2 = ListNode(2)
    listNode3 = ListNode(3)
    listNode4 = ListNode(4)
    listNode5 = ListNode(5)
    listNode6 = ListNode(6)

    listNode1.next = listNode2
    listNode2.next = listNode3
    listNode3.next = listNode4
    listNode4.next = listNode5
    listNode5.next = listNode6


    node = listNode1
    while node != None:
        print(node.val)
        node = node.next

    solution1 = Solution()
    a = solution1.ReverseList(listNode1)
    # print(a.val)
    while a != None:
        print(a.val)
        a = a.next