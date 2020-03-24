# -*- coding:utf-8 -*-
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # 返回 RandomListNode
    def CloneNode(self, pHead):
        pnode = pHead
        while pnode !=  None:
            pclone = RandomListNode(-1)
            pclone.label = pnode.label
            pclone.next= pnode.next
            pclone.random = None
            pnode.next = pclone
            pnode = pclone.next
        return pHead

    def AddRandom(self, pHead):
        pnode = pHead
        while pnode != None:
            if pnode.random != None:
                pnode.next.random = pnode.random.next
            pnode = pnode.next.next
        return pHead

    def SplitNode(self,pHead):
        pnode = pHead
        pHead2 = pHead.next
        # pnode2 = pHead.next
        while pnode!= None:
            pnode2 = pnode.next
            pnode_nextnext = pnode2.next
            pnode.next = pnode_nextnext
            if pnode_nextnext:
                pnode2.next = pnode_nextnext.next
            else:
                pnode2.next =None
            pnode = pnode_nextnext

        return pHead2

    def Clone(self, pHead):
        # write code here
        if pHead ==None:
            return None
        pHead2 = self.CloneNode(pHead)
        pHead2  = self.AddRandom(pHead2)
        pHead2 = self.SplitNode(pHead2)
        return  pHead2


if __name__ == '__main__':
    listNode11 = RandomListNode(1)
    listNode12 = RandomListNode(2)
    listNode13 = RandomListNode(3)
    listNode14 = RandomListNode(4)
    listNode15 = RandomListNode(5)
    listNode11.next = listNode12
    listNode12.next = listNode13
    listNode13.next = listNode14
    listNode14.next = listNode15

    listNode11.random = listNode13
    listNode12.random  = listNode15
    listNode14.random = listNode12

    solution1 = Solution()
    a = solution1.Clone(listNode11)
    pnode = a
    while pnode !=  None:
        print(pnode.label)
        pnode =pnode.next
    print(a)



