# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.flag = -1

    def Serialize(self, root):
        # write code hereright
        if not root:
            return '#,'
        serial = str(root.val)+','+ self.Serialize(root.left) + self.Serialize(root.right)
        return serial

    def Deserialize(self, s):
        # write code here
        self.flag += 1
        l = s.split(',')
        # print(l)
        if self.flag  >= len(s)-1:
            return None
        root = None
        if l[self.flag] != '#':
            root = TreeNode(int(l[self.flag]))
            root.left = self.Deserialize(s)
            root.right = self.Deserialize(s)
        return root

if __name__ == '__main__':
    TreeNode1 = TreeNode(1)
    TreeNode2 = TreeNode(2)
    TreeNode3 = TreeNode(3)
    TreeNode4 = TreeNode(4)
    TreeNode5 = TreeNode(5)
    TreeNode6 = TreeNode(6)


    TreeNode1.left = TreeNode2
    TreeNode1.right = TreeNode3
    TreeNode2.left = TreeNode4
    # TreeNode2.right = TreeNode5
    TreeNode3.left = TreeNode5
    TreeNode3.right = TreeNode6

    solution1 = Solution()
    a = solution1.Serialize(TreeNode1)
    s = "1,2,4,#,#,#,3,5,#,#,6,#,#,"
    b= solution1.Deserialize(s)
    # pnode = a
    # while pnode !=  None:
    #     print(pnode.val)
    #     pnode =pnode.right
    print(a)
