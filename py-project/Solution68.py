# -*- coding:utf-8 -*-

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.rigjt = None

if __name__ == '__main__':
    t1 = TreeNode(10)
    t2 = TreeNode(5)
    t3 = TreeNode(12)
    t4 = TreeNode(4)
    t5 = TreeNode(7)

    t1.left = t2
    t1.right = t3
    t2.left = t4
    t2.right = t5

    # solution1 = Solution()
    # a = solution1.FindPath(t1,22)
    # print(a)