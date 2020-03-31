# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if pHead == None:
            return None
        slow = pHead
        fast = pHead
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                slow2 = pHead
                while slow != slow2:
                    slow = slow.next
                    slow2= slow2.next
                return slow2
        return None


# 不妨这样来算一下，当fast和slow相遇时， l_fast = l_slow + ring = 2 x l_slow，
# 换言之，l_slow = ring ！ 相遇时slow走过的距离，就已经是环的长度了！


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
    listNode6.next = listNode3


    node = listNode1
    # while node != None:
    #     print(node.val)
    #     node = node.next

    solution1 = Solution()
    a = solution1.EntryNodeOfLoop(listNode1)
    print(a.val)