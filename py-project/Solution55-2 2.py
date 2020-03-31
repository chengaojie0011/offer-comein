# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def IsBalanced_Solution(self, pRoot):
        # write code here
        if pRoot == None:
            return True
        if self.dfs(pRoot)!=-1:
            return True
        else:
            return False

    def dfs(self,pRoot):
        if pRoot == None:
            return 0
        left = self.dfs(pRoot.left)
        if left == -1:
            return -1
        right = self.dfs(pRoot.right)
        if right == -1:
            return -1
        if abs(left-right)>1:
            return -1
        return max(left,right)+1


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
    a = solution1.IsBalanced_Solution(TreeNode1)
    print(a)