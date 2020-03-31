# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head == None or k <= 0:
            return None
        node1 = head
        for i in range(k-1):
            if node1.next:
                node1 = node1.next
            else:
                return None
        node2 = head
        while(node1.next):
            node1 = node1.next
            node2 = node2.next
        return node2




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
    # listNode5.next = listNode6

    node = listNode1
    while node != None:
        print(node.val)
        node = node.next

    solution1 = Solution()
    a = solution1.FindKthToTail(listNode1, 1)
    print(a)