# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def compare(self, pRoot1, pRoot2):
        if pRoot1 == None and pRoot2 ==None:
            return True
        if pRoot1 == None or pRoot2 ==None:
            return False
        if pRoot1.val != pRoot2.val:
            return False
        return self.compare(pRoot1.left, pRoot2.right) and self.compare(pRoot1.right, pRoot2.left)

    def isSymmetrical(self, pRoot):
        # write code here
        return self.compare(pRoot, pRoot)




if __name__ == "__main__":
   a = 1
