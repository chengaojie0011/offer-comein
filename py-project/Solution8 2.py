# -*- coding:utf-8 -*-



class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None


class Solution:
    def GetNext(self, pNode):
        # write code here
        if pNode.right:
            p = pNode.right
            while p.left:
                p = p.left
            return p
        else:
            while pNode.next:
                if(pNode.next.left == pNode):
                   return pNode.next
                pNode = pNode.next
        return None


if __name__ == "__main__":

    a = 1
    if a is not None:
        print(a)