# -*- coding:utf-8 -*-

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplication(self, pHead):
        # write code here
        if pHead == None or pHead.next == None:
            return pHead
        new_head = ListNode(-1)
        new_head.next = pHead
        pnode = pHead
        pre = new_head
        nex = None
        while pnode and pnode.next:
            nex = pnode.next
            if nex.val == pnode.val:
                while nex and pnode.val ==nex.val:
                    nex = nex.next
                pnode = nex
                pre.next = pnode
            else:
                pre = pnode
                pnode = nex

        return new_head.next

if __name__ == "__main__":
    ln1 = ListNode(1)
    ln2 = ListNode(1)
    ln3 = ListNode(1)
    ln4 = ListNode(2)
    # ln5 = ListNode(3)
    # ln6 = ListNode(4)
    # ln7 = ListNode(5)
    # ln8 = ListNode(5)
    ln1.next = ln2
    ln2.next = ln3
    ln3.next = ln4
    # ln4.next = ln5
    # ln5.next = ln6
    # ln6.next = ln7
    # ln7.next = ln8
    # print(ln2.next)
    pnode  = ln1
    while pnode:
        print(pnode.val)
        if pnode.next:
            pnode = pnode.next
        else:
            break
    print('\n')
    solution1 = Solution()
    a = solution1.deleteDuplication(ln1)
    pnode  = a
    while pnode:
        print(pnode.val)
        if pnode.next:
            pnode = pnode.next
        else:
            break
    # print(a)