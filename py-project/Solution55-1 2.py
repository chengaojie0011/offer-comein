# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def TreeDepth(self, pRoot):
        # write code here
        if pRoot==None:
            return 0
        left = self.TreeDepth(pRoot.left)
        right = self.TreeDepth(pRoot.right)
        if left>right:
            return left+1
        else:
            return right+1

if __name__ == '__main__':
    TreeNode1 = TreeNode(5)
    TreeNode2 = TreeNode(3)
    TreeNode3 = TreeNode(7)
    TreeNode4 = TreeNode(2)
    TreeNode5 = TreeNode(4)
    TreeNode6 = TreeNode(6)
    TreeNode7 = TreeNode(8)
    TreeNode1.left = TreeNode2
    TreeNode1.right = TreeNode3
    TreeNode2.left = TreeNode4
    TreeNode2.right = TreeNode5
    TreeNode3.left = TreeNode6
    TreeNode3.right = TreeNode7
    k = 3
    # print(len(l))
    solution1 = Solution()
    a = solution1.TreeDepth(TreeNode1)
    print(a.val)