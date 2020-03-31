# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        # write code here
        if root == None:
            return root
        tmp = root.left
        root.left = root.right
        root.right = tmp
        if root.left:
            self.Mirror(root.left)
        if root.right:
            self.Mirror(root.right)
        return root



if __name__ == "__main__":
   a = 1