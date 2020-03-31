# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回对应节点TreeNode
    def __init__(self):
        self.count = 0

    def KthNode(self, pRoot, k):
        # write code here
        if pRoot == None or k<=0:
            return None
        node = self.KthNode(pRoot.left, k)
        if node != None:
            return node
        self.count +=1
        if self.count ==k:
            return pRoot
        node = self.KthNode(pRoot.right, k)
        return node


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
    a = solution1.KthNode(TreeNode1,k)
    print(a.val)