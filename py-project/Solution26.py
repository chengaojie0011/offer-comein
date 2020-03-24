# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSubtree(self, pRoot1, pRoot2):
        if pRoot2 == None:
            return True
        if pRoot1 == None:
            return False
        if pRoot1.val == pRoot2.val:
            return self.isSubtree(pRoot1.left, pRoot2.left) and self.isSubtree(pRoot1.right, pRoot2.right)
        else:
            return False

    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        res = False
        if pRoot1 and pRoot2:
            if pRoot1.val == pRoot2.val:
                res =  self.isSubtree(pRoot1, pRoot2)
            if res is False:
                res = self.HasSubtree(pRoot1.left, pRoot2)
            if res is False:
                res = self.HasSubtree(pRoot1.right, pRoot2)
        return res


class Solution2:
    def HasSubtree(self, pRoot1, pRoot2):

        def convert(p):
            if p:
                return str(p.val) + convert(p.left) + convert(p.right)
            else:
                return ""

        return convert(pRoot2) in convert(pRoot1) if pRoot2 else False

if __name__ == "__main__":
   a = 1