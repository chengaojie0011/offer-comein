# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        if pRootOfTree is None:
            return None
        if not pRootOfTree.left and not pRootOfTree.right:
            return pRootOfTree

        left = self.Convert(pRootOfTree.left)
        p = left

        while left and p.right:
            p = p.right

        if left:
            p.right = pRootOfTree
            pRootOfTree.left = p

        right = self.Convert(pRootOfTree.right)

        if right:
            right.left = pRootOfTree
            pRootOfTree.right = right

        return left if left else pRootOfTree

if __name__ == '__main__':
    TreeNode1 = TreeNode(10)
    TreeNode2 = TreeNode(6)
    TreeNode3 = TreeNode(14)
    TreeNode4 = TreeNode(4)
    TreeNode5 = TreeNode(8)
    TreeNode6 = TreeNode(12)
    TreeNode7 = TreeNode(16)

    TreeNode1.left = TreeNode2
    TreeNode1.right = TreeNode3
    TreeNode2.left = TreeNode4
    TreeNode2.right = TreeNode5
    TreeNode3.left = TreeNode6
    TreeNode3.right = TreeNode7

    solution1 = Solution()
    a = solution1.Convert(TreeNode1)
    pnode = a
    while pnode !=  None:
        print(pnode.val)
        pnode =pnode.right
    print(a)
